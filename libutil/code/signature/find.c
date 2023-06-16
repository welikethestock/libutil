#include "find.h"
#include "../../common/strlib.h"
#include "../../common/memlib.h"
#ifdef LIBUTIL_WINDOWS
#include "../../platform/nt/pe.h"
#endif

//TODO: fix for x64

static
void *FindSignature(const void *BaseAddress, const char *Signature, libutil_size Length)
{
    libutil_size SignatureLength = LibUtil_StringLength(Signature);
    for(const libutil_u8 *Address = (const libutil_u8 *)(BaseAddress); Length != 0; --Length, ++Address)
    {
        for(libutil_size Index = 0, SignatureIndex = 0; SignatureIndex < SignatureLength; ++Index)
        {
            if((Length - Index) == 0)
            {
                return NULL;
            }

            if(Signature[SignatureIndex] == '?')
            {
                SignatureIndex += 2;

                continue;
            }

            libutil_u8 Value = 0;
            for(libutil_size Index = 0; Index < 2; ++Index)
            {
                if(Signature[SignatureIndex + Index] >= '0' && Signature[SignatureIndex + Index] <= '9')
                {
                    Value = (Value * 16) + (Signature[SignatureIndex + Index] - '0');
                }
                else if(Signature[SignatureIndex + Index] >= 'a' && Signature[SignatureIndex + Index] <= 'f')
                {
                    Value = (Value * 16) + (10 + Signature[SignatureIndex + Index] - 'a');
                }
                else if (Signature[SignatureIndex + Index] >= 'A' && Signature[SignatureIndex + Index] <= 'F')
                {
                    Value = (Value * 16) + (10 + Signature[SignatureIndex + Index] - 'A');
                }
            }

            if(Address[Index] != Value)
            {
                break;
            }

            SignatureIndex += 3;

            if(!(SignatureIndex < SignatureLength))
            {
                return (void *)(Address);
            }
        }
    }

    return NULL;
}

LIBUTIL_API
void *LibUtil_Signature_FindInSection(const void *Module, const char *Signature, const char *Section)
{
#ifdef LIBUTIL_WINDOWS
    const LIBUTIL_NT_DOS_HEADER *Headers = (LIBUTIL_NT_DOS_HEADER *)(Module);
    if(Headers->e_magic != LIBUTIL_NT_DOS_HEADER_MAGIC)
    {
        return NULL;
    }

    const LIBUTIL_NT_IMAGE_NT_HEADERS *NTHeaders = (const LIBUTIL_NT_IMAGE_NT_HEADERS *)(LIBUTIL_NT_RVA_TO_ABS(Module, Headers->e_lfanew));
    if(NTHeaders->Signature != LIBUTIL_NT_NT_HEADERS_SIGNATURE)
    {
        return NULL;
    }

    if(NTHeaders->OptionalHeader.Magic != LIBUTIL_NT_IMAGE_FILE_MAGIC)
    {
        return NULL;
    }

    const LIBUTIL_NT_IMAGE_SECTION_HEADER *SectionHeader = (const LIBUTIL_NT_IMAGE_SECTION_HEADER *)(
        LIBUTIL_NT_RVA_TO_ABS(
            &NTHeaders->OptionalHeader,
            NTHeaders->FileHeader.SizeOfOptionalHeader
        )
    );

    for(int Index = 0; Index < NTHeaders->FileHeader.NumberOfSections; ++Index, ++SectionHeader)
    {
        if(SectionHeader->Characteristics & LIBUTIL_NT_IMAGE_SCN_MEM_DISCARDABLE)
        {
            continue;
        }

        if((SectionHeader->Characteristics & (LIBUTIL_NT_IMAGE_SCN_CNT_CODE | LIBUTIL_NT_IMAGE_SCN_CNT_INITIALIZED_DATA | LIBUTIL_NT_IMAGE_SCN_CNT_UNINITIALIZED_DATA)) == 0)
        {
            continue;
        }

        if(LibUtil_Memcmp(SectionHeader->Name, Section, LibUtil_StringLength(Section)) != 0)
        {
            continue;
        }

        return FindSignature((const void *)(LIBUTIL_NT_RVA_TO_ABS(Module, SectionHeader->VirtualAddress)), Signature, SectionHeader->VirtualSize);
    }
#endif

    return NULL;
}

LIBUTIL_API
void *LibUtil_Signature_FindInImage(const void *Module, const char *Signature)
{
#ifdef LIBUTIL_WINDOWS
    const LIBUTIL_NT_DOS_HEADER *Headers = (LIBUTIL_NT_DOS_HEADER *)(Module);
    if(Headers->e_magic != LIBUTIL_NT_DOS_HEADER_MAGIC)
    {
        return NULL;
    }

    const LIBUTIL_NT_IMAGE_NT_HEADERS *NTHeaders = (const LIBUTIL_NT_IMAGE_NT_HEADERS *)(LIBUTIL_NT_RVA_TO_ABS(Module, Headers->e_lfanew));
    if(NTHeaders->Signature != LIBUTIL_NT_NT_HEADERS_SIGNATURE)
    {
        return NULL;
    }

    if(NTHeaders->OptionalHeader.Magic != LIBUTIL_NT_IMAGE_FILE_MAGIC)
    {
        return NULL;
    }

    const LIBUTIL_NT_IMAGE_SECTION_HEADER *SectionHeader = (const LIBUTIL_NT_IMAGE_SECTION_HEADER *)(
        LIBUTIL_NT_RVA_TO_ABS(
            &NTHeaders->OptionalHeader,
            NTHeaders->FileHeader.SizeOfOptionalHeader
        )
    );

    for(int Index = 0; Index < NTHeaders->FileHeader.NumberOfSections; ++Index, ++SectionHeader)
    {
        if(SectionHeader->Characteristics & LIBUTIL_NT_IMAGE_SCN_MEM_DISCARDABLE)
        {
            continue;
        }

        if((SectionHeader->Characteristics & (LIBUTIL_NT_IMAGE_SCN_CNT_CODE | LIBUTIL_NT_IMAGE_SCN_CNT_INITIALIZED_DATA | LIBUTIL_NT_IMAGE_SCN_CNT_UNINITIALIZED_DATA)) == 0)
        {
            continue;
        }

        void *Result = FindSignature((const void *)(LIBUTIL_NT_RVA_TO_ABS(Module, SectionHeader->VirtualAddress)), Signature, SectionHeader->VirtualSize);
        if(Result != NULL)
        {
            return Result;
        }
    }
#endif

    return NULL;
}
