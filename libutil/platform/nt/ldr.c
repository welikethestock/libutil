#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "ldr.h"
#include "peb.h"
#include "../../arch/x86/mode.h"
#include "pe.h"
#include "../../common/strlib.h"
#include "../../crypto/luhash.h"

#ifdef LIBUTIL_X86
LIBUTIL_API
LIBUTIL_NT_PEB_LDR_DATA32 *LibUtil_Nt_GetLdrData32()
{
    return (LIBUTIL_NT_PEB_LDR_DATA32 *)(LibUtil_Nt_GetPeb32()->Ldr);
}

LIBUTIL_API
LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32 *LibUtil_Nt_ReadLdrDataEntry32()
{
    return (LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32 *)(LibUtil_Nt_GetLdrData32()->InLoadOrderModuleList.Flink);
}

#ifndef LIBUTIL_X86_PURE32
LIBUTIL_API
libutil_u64 LibUtil_Nt_GetLdrData64()
{
    libutil_u64 PEB = LibUtil_Nt_GetPeb64();
    if(PEB == NULL)
    {
        return NULL;
    }

    libutil_u64 Ldr;
    LibUtil_x86_Memcpy64((libutil_u64)(&Ldr), PEB + LIBUTIL_OFFSETOF(LIBUTIL_NT_PEB64, Ldr), sizeof(libutil_u64));

    return Ldr;
}

LIBUTIL_API
libutil_bool LibUtil_Nt_ReadLdrData64(LIBUTIL_NT_PEB_LDR_DATA64 *Ldr)
{
    libutil_u64 Ldr64 = LibUtil_Nt_GetLdrData64();
    if(Ldr64 == NULL)
    {
        return FALSE;
    }

    LibUtil_x86_Memcpy64((libutil_u64)(Ldr), Ldr64, sizeof(LIBUTIL_NT_PEB_LDR_DATA64));

    return TRUE;
}

LIBUTIL_API
libutil_u64 LibUtil_Nt_GetLdrDataEntry64()
{
    libutil_u64 Ldr = LibUtil_Nt_GetLdrData64();
    if(Ldr == NULL)
    {
        return NULL;
    }

    libutil_u64 Entry;
    LibUtil_x86_Memcpy64((libutil_size)(&Entry), Ldr + LIBUTIL_OFFSETOF(LIBUTIL_NT_PEB_LDR_DATA64, InLoadOrderModuleList.Flink), sizeof(libutil_u64));

    return Entry;
}

LIBUTIL_API
libutil_bool LibUtil_Nt_ReadLdrDataEntry64(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64 *Entry, libutil_u64 Address)
{
    if(Address == NULL)
    {
        return FALSE;
    }

    LibUtil_x86_Memcpy64((libutil_size)(Entry), Address, sizeof(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64));

    return TRUE;
}

LIBUTIL_API
void *LibUtil_Nt_GetLdrModuleExport32(void *Module, libutil_u32 Hash)
{
    if(!LibUtil_Nt_IsValidImage(Module, FALSE))
    {
        return NULL;
    }

    LIBUTIL_NT_DOS_HEADER               *DOSHeader          = (LIBUTIL_NT_DOS_HEADER *)(Module);
    LIBUTIL_NT_IMAGE_NT_HEADERS32       *NTHeaders          = (LIBUTIL_NT_IMAGE_NT_HEADERS32 *)(LIBUTIL_NT_RVA_TO_ABS32(DOSHeader, DOSHeader->e_lfanew));
    LIBUTIL_NT_IMAGE_EXPORT_DIRECTORY   *ExportDirectory    = (LIBUTIL_NT_IMAGE_EXPORT_DIRECTORY *)(LIBUTIL_NT_RVA_TO_ABS32(
        DOSHeader,
        NTHeaders->OptionalHeader.DataDirectory[LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_EXPORT].RVA)
    );

    libutil_u32 *NameRVAs       = (libutil_u32 *)(LIBUTIL_NT_RVA_TO_ABS32(DOSHeader, ExportDirectory->NamePointerRVA));
    libutil_u16 *Ordinals       = (libutil_u16 *)(LIBUTIL_NT_RVA_TO_ABS32(DOSHeader, ExportDirectory->OrdinalTableRVA));
    libutil_u32 *FunctionRVAs   = (libutil_u32 *)(LIBUTIL_NT_RVA_TO_ABS32(DOSHeader, ExportDirectory->ExportAddressTableRVA));

    for(libutil_u32 Index = 0; Index < ExportDirectory->NumberOfNamePointers; ++Index)
    {
        const char *FunctionName    = (const char *)(LIBUTIL_NT_RVA_TO_ABS32(DOSHeader, NameRVAs[Index]));
        libutil_u32 NameHash        = LibUtil_LUHash(FunctionName, NULL, LibUtil_StringLength(FunctionName));
        if(Hash == NameHash)
        {
            return (void *)(LIBUTIL_NT_RVA_TO_ABS32(
                DOSHeader,
                FunctionRVAs[Ordinals[Index]]
            ));
        }
    }

    return NULL;
}

LIBUTIL_API
void *LibUtil_Nt_GetLdrExport32(libutil_u32 ModuleHash, libutil_u32 Hash)
{
    LIBUTIL_NT_PEB_LDR_DATA32           *Ldr    = LibUtil_Nt_GetLdrData32();
    LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32   *Entry  = (LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32 *)(Ldr->InLoadOrderModuleList.Flink);
    while(Entry->BaseDllName.Buffer != NULL)
    {
        if(LibUtil_LUHash((const void *)(Entry->BaseDllName.Buffer), NULL, Entry->BaseDllName.Length) == ModuleHash)
        {
            void *Export = LibUtil_Nt_GetLdrModuleExport32((void *)(Entry->DllBase), Hash);
            if(Export != NULL)
            {
                return Export;
            }
        }

        Entry = (LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32 *)(Entry->InLoadOrderMemoryLinks.Flink);
    }

    return NULL;
}
#endif
#elif defined(LIBUTIL_X86_64)
LIBUTIL_API
LIBUTIL_NT_PEB_LDR_DATA64 *LibUtil_Nt_GetLdrData64()
{
    return (LIBUTIL_NT_PEB_LDR_DATA64 *)(LibUtil_Nt_GetPeb64()->Ldr);
}
#endif

#endif
