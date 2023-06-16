#ifndef __LIBUTIL_PLATFORM_NT_PE__
#define __LIBUTIL_PLATFORM_NT_PE__

#include "../../common/decl.h"

#ifdef LIBUTIL_MSVC
#pragma pack(push, 1)
#endif

#define LIBUTIL_NT_DOS_HEADER_MAGIC 0x5A4D
#define LIBUTIL_NT_NT_HEADERS_SIGNATURE 0x4550

#define LIBUTIL_NT_RVA_TO_ABS32(Base, RVA) \
    ((libutil_u32)(Base) + (libutil_u32)(RVA))

#define LIBUTIL_NT_RVA_TO_ABS64(Base, RVA) \
    ((libutil_u64)(Base) + (libutil_u64)(RVA))

#ifdef LIBUTIL_32_BITS
    #define LIBUTIL_NT_RVA_TO_ABS(Base, RVA) LIBUTIL_NT_RVA_TO_ABS32(Base, RVA)
#else
    #define LIBUTIL_NT_RVA_TO_ABS(Base, RVA) LIBUTIL_NT_RVA_TO_ABS64(Base, RVA)
#endif

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_DOS_HEADER
{
    libutil_u16                                                             e_magic;                                /*+0x000*/
    libutil_u16                                                             e_cblp;                                 /*+0x002*/
    libutil_u16                                                             e_cp;                                   /*+0x004*/
    libutil_u16                                                             e_crlc;                                 /*+0x006*/
    libutil_u16                                                             e_cparhdr;                              /*+0x008*/
    libutil_u16                                                             e_minalloc;                             /*+0x00A*/
    libutil_u16                                                             e_maxalloc;                             /*+0x00C*/
    libutil_u16                                                             e_ss;                                   /*+0x00E*/
    libutil_u16                                                             e_sp;                                   /*+0x010*/
    libutil_u16                                                             e_csum;                                 /*+0x012*/
    libutil_u16                                                             e_ip;                                   /*+0x014*/
    libutil_u16                                                             e_cs;                                   /*+0x016*/
    libutil_u16                                                             e_lfarlc;                               /*+0x018*/
    libutil_u16                                                             e_ovno;                                 /*+0x01A*/
    libutil_u16                                                             e_res[4];                               /*+0x01C*/
    libutil_u16                                                             e_oemid;                                /*+0x024*/
    libutil_u16                                                             e_oeminfo;                              /*+0x026*/
    libutil_u16                                                             e_res2[10];                             /*+0x028*/
    libutil_i32                                                             e_lfanew;                               /*+0x03C*/
} LIBUTIL_NT_DOS_HEADER;

typedef enum _LIBUTIL_NT_IMAGE_FILE_MACHINE
{
    LIBUTIL_NT_IMAGE_FILE_MACHINE_UNKNOWN = 0x0,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_ALPHA = 0x184,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_ARM = 0x1C0,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_ALPHA64 = 0x284,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_I386 = 0x14C,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_IA64 = 0x200,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_M68K = 0x268,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_MIPS16 = 0x266,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_MIPSFPU = 0x366,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_MIPSFPU16 = 0x466,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_POWERPC = 0x1F0,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_R3000 = 0x162,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_R4000 = 0x166,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_R10000 = 0x168,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_SH3 = 0x1A2,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_SH4 = 0x1A6,
    LIBUTIL_NT_IMAGE_FILE_MACHINE_THUMB = 0x1C2
} LIBUTIL_NT_IMAGE_FILE_MACHINE;

typedef enum _LIBUTIL_NT_IMAGE_FILE_CHARACTERISTICS
{
    LIBUTIL_NT_IMAGE_FILE_RELOCS_STRIPPED = 0x1,
    LIBUTIL_NT_IMAGE_FILE_EXECUTABLE_IMAGE = 0x2,
    LIBUTIL_NT_IMAGE_FILE_LINE_NUMS_STRIPPED = 0x4,
    LIBUTIL_NT_IMAGE_FILE_LOCAL_SYMS_STRIPPED = 0x8,
    LIBUTIL_NT_IMAGE_FILE_AGGRESSIVE_WS_TRIM = 0x10,
    LIBUTIL_NT_IMAGE_FILE_LARGE_ADDRESS_AWARE = 0x20,
    LIBUTIL_NT_IMAGE_FILE_16BIT_MACHINE = 0x40,
    LIBUTIL_NT_IMAGE_FILE_BYTES_REVERSED_LO = 0x80,
    LIBUTIL_NT_IMAGE_FILE_32BIT_MACHINE = 0x100,
    LIBUTIL_NT_IMAGE_FILE_DEBUG_STRIPPED = 0x200,
    LIBUTIL_NT_IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP = 0x400,
    LIBUTIL_NT_IMAGE_FILE_SYSTEM = 0x1000,
    LIBUTIL_NT_IMAGE_FILE_DLL = 0x2000,
    LIBUTIL_NT_IMAGE_FILE_UP_SYSTEM_ONLY = 0x4000,
    LIBUTIL_NT_IMAGE_FILE_BYTES_REVERSED_HI = 0x8000
} LIBUTIL_NT_IMAGE_FILE_CHARACTERISTICS;

typedef enum _LIBUTIL_NT_IMAGE_FILE_MAGIC_NUMBERS
{
    LIBUTIL_NT_IMAGE_FILE_MAGIC32 = 0x10B,
    LIBUTIL_NT_IMAGE_FILE_MAGIC64 = 0x20B,

#ifdef LIBUTIL_32_BITS
    LIBUTIL_NT_IMAGE_FILE_MAGIC = LIBUTIL_NT_IMAGE_FILE_MAGIC32
#elif defined(LIBUTIL_64_BITS)
    LIBUTIL_NT_IMAGE_FILE_MAGIC = LIBUTIL_NT_IMAGE_FILE_MAGIC64
#endif
} LIBUTIL_NT_IMAGE_FILE_MAGIC_NUMBERS;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_FILE_HEADER
{
    libutil_u16                                                             Machine;                                /*+0x000*/
    libutil_u16                                                             NumberOfSections;                       /*+0x002*/
    libutil_u32                                                             TimeDateStamp;                          /*+0x004*/
    libutil_u32                                                             PointerToSymbolTable;                   /*+0x008*/
    libutil_u32                                                             NumberOfSymbols;                        /*+0x00C*/
    libutil_u16                                                             SizeOfOptionalHeader;                   /*+0x010*/
    libutil_u16                                                             Characteristics;                        /*+0x012*/
} LIBUTIL_NT_IMAGE_FILE_HEADER;

typedef enum _LIBUTIL_NT_IMAGE_SUBSYSTEM
{
    LIBUTIL_NT_IMAGE_SUBSYSTEM_UNKNOWN = 0,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_NATIVE,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_WINDOWS_GUI,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_WINDOWS_CUI,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_POSIX_CUI,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_WINDOWS_CE_GUI,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_EFI_APPLICATION,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER,
    LIBUTIL_NT_IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER
} LIBUTIL_NT_IMAGE_SUBSYSTEM;

typedef enum _LIBUTIL_NT_IMAGE_DLLCHARACTERISTICS
{
    LIBUTIL_NT_IMAGE_DLLCHARACTERISTICS_NO_BIND = 0x800,
    LIBUTIL_NT_IMAGE_DLLCHARACTERISTICS_WDM_DRIVER = 0x2000,
    LIBUTIL_NT_IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE = 0x8000
} LIBUTIL_NT_IMAGE_DLLCHARACTERISTICS;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_DATA_DIRECTORY
{
    libutil_u32                                                             RVA;                                    /*+0x000*/
    libutil_u32                                                             Size;                                   /*+0x004*/
} LIBUTIL_NT_IMAGE_DATA_DIRECTORY;

typedef enum _LIBUTIL_NT_IMAGE_DATA_DIRECTORIES
{
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_EXPORT = 0,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_IMPORT,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_RESOURCE,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_EXCEPTION,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_SECURITY,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_BASERELOC,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_DEBUG,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_ARCHITECTURE,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_GLOBALPTR,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_TLS,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_IAT,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_RESERVED,
    LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_COUNT,
    LIBUTIL_NT_DATADIR_COUNT = LIBUTIL_NT_IMAGE_DIRECTORY_ENTRY_COUNT
} LIBUTIL_NT_IMAGE_DATA_DIRECTORIES;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_OPTIONAL_HEADER32
{
    libutil_u16                                                             Magic;                                  /*+0x000*/
    libutil_u8                                                              MajorLinkerVersion;                     /*+0x002*/
    libutil_u8                                                              MinorLinkerVersion;                     /*+0x003*/
    libutil_u32                                                             SizeOfCode;                             /*+0x004*/
    libutil_u32                                                             SizeOfInitializedData;                  /*+0x008*/
    libutil_u32                                                             SizeOfUninitializedData;                /*+0x00C*/
    libutil_u32                                                             AddressOfEntryPoint;                    /*+0x010*/
    libutil_u32                                                             BaseOfCode;                             /*+0x014*/
    libutil_u32                                                             BaseOfData;                             /*+0x018*/
    libutil_u32                                                             ImageBase;                              /*+0x01C*/
    libutil_u32                                                             SectionAlignment;                       /*+0x020*/
    libutil_u32                                                             FileAlignment;                          /*+0x024*/
    libutil_u16                                                             MajorOperatingSystemVersion;            /*+0x028*/
    libutil_u16                                                             MinorOperatingSystemVersion;            /*+0x02A*/
    libutil_u16                                                             MajorImageVersion;                      /*+0x02C*/
    libutil_u16                                                             MinorImageVersion;                      /*+0x02E*/
    libutil_u16                                                             MajorSubsystemVersion;                  /*+0x030*/
    libutil_u16                                                             MinorSubsystemVersion;                  /*+0x032*/
    libutil_u8                                                              Reserved1[4];                           /*+0x034*/
    libutil_u32                                                             SizeOfImage;                            /*+0x038*/
    libutil_u32                                                             SizeOfHeaders;                          /*+0x03C*/
    libutil_u32                                                             CheckSum;                               /*+0x040*/
    libutil_u16                                                             Subsystem;                              /*+0x044*/
    libutil_u16                                                             DllCharacteristics;                     /*+0x046*/
    libutil_u32                                                             SizeOfStackReserve;                     /*+0x048*/
    libutil_u32                                                             SizeOfStackCommit;                      /*+0x04C*/
    libutil_u32                                                             SizeOfHeapReserve;                      /*+0x050*/
    libutil_u32                                                             SizeOfHeapCommit;                       /*+0x054*/
    libutil_u32                                                             LoaderFlags;                            /*+0x058*/
    libutil_u32                                                             NumberOfRvaAndSizes;                    /*+0x05C*/
    LIBUTIL_NT_IMAGE_DATA_DIRECTORY                                         DataDirectory[LIBUTIL_NT_DATADIR_COUNT];/*+0x060*/
} LIBUTIL_NT_IMAGE_OPTIONAL_HEADER32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_NT_HEADERS32
{
    libutil_u32                                                             Signature;                              /*+0x000*/
    LIBUTIL_NT_IMAGE_FILE_HEADER                                            FileHeader;                             /*+0x004*/
    LIBUTIL_NT_IMAGE_OPTIONAL_HEADER32                                      OptionalHeader;                         /*+0x018*/
} LIBUTIL_NT_IMAGE_NT_HEADERS32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_OPTIONAL_HEADER64
{
    libutil_u16                                                             Magic;                                  /*+0x000*/
    libutil_u8                                                              MajorLinkerVersion;                     /*+0x002*/
    libutil_u8                                                              MinorLinkerVersion;                     /*+0x003*/
    libutil_u32                                                             SizeOfCode;                             /*+0x004*/
    libutil_u32                                                             SizeOfInitializedData;                  /*+0x008*/
    libutil_u32                                                             SizeOfUninitializedData;                /*+0x00C*/
    libutil_u32                                                             AddressOfEntryPoint;                    /*+0x010*/
    libutil_u32                                                             BaseOfCode;                             /*+0x014*/
    libutil_u64                                                             ImageBase;                              /*+0x018*/
    libutil_u32                                                             SectionAlignment;                       /*+0x020*/
    libutil_u32                                                             FileAlignment;                          /*+0x024*/
    libutil_u16                                                             MajorOperatingSystemVersion;            /*+0x028*/
    libutil_u16                                                             MinorOperatingSystemVersion;            /*+0x02A*/
    libutil_u16                                                             MajorImageVersion;                      /*+0x02C*/
    libutil_u16                                                             MinorImageVersion;                      /*+0x02E*/
    libutil_u16                                                             MajorSubsystemVersion;                  /*+0x030*/
    libutil_u16                                                             MinorSubsystemVersion;                  /*+0x032*/
    libutil_u8                                                              Reserved1[4];                           /*+0x034*/
    libutil_u32                                                             SizeOfImage;                            /*+0x038*/
    libutil_u32                                                             SizeOfHeaders;                          /*+0x03C*/
    libutil_u32                                                             CheckSum;                               /*+0x040*/
    libutil_u16                                                             Subsystem;                              /*+0x044*/
    libutil_u16                                                             DllCharacteristics;                     /*+0x046*/
    libutil_u64                                                             SizeOfStackReserve;                     /*+0x048*/
    libutil_u64                                                             SizeOfStackCommit;                      /*+0x050*/
    libutil_u64                                                             SizeOfHeapReserve;                      /*+0x058*/
    libutil_u64                                                             SizeOfHeapCommit;                       /*+0x060*/
    libutil_u32                                                             LoaderFlags;                            /*+0x068*/
    libutil_u32                                                             NumberOfRvaAndSizes;                    /*+0x06C*/
    LIBUTIL_NT_IMAGE_DATA_DIRECTORY                                         DataDirectory[LIBUTIL_NT_DATADIR_COUNT];/*+0x070*/
} LIBUTIL_NT_IMAGE_OPTIONAL_HEADER64;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_NT_HEADERS64
{
    libutil_u32                                                             Signature;                              /*+0x000*/
    LIBUTIL_NT_IMAGE_FILE_HEADER                                            FileHeader;                             /*+0x004*/
    LIBUTIL_NT_IMAGE_OPTIONAL_HEADER64                                      OptionalHeader;                         /*+0x018*/
} LIBUTIL_NT_IMAGE_NT_HEADERS64;

typedef enum _LIBUTIL_NT_IMAGE_SECTION_CHARACTERISTICS
{
    LIBUTIL_NT_IMAGE_SCN_TYPE_REG = 0x0,
    LIBUTIL_NT_IMAGE_SCN_TYPE_DSECT = 0x1,
    LIBUTIL_NT_IMAGE_SCN_TYPE_NOLOAD = 0x2,
    LIBUTIL_NT_IMAGE_SCN_TYPE_GROUP = 0x4,
    LIBUTIL_NT_IMAGE_SCN_TYPE_NO_PAD = 0x8,
    LIBUTIL_NT_IMAGE_SCN_TYPE_COPY = 0x10,
    LIBUTIL_NT_IMAGE_SCN_CNT_CODE = 0x20,
    LIBUTIL_NT_IMAGE_SCN_CNT_INITIALIZED_DATA = 0x40,
    LIBUTIL_NT_IMAGE_SCN_CNT_UNINITIALIZED_DATA = 0x80,
    LIBUTIL_NT_IMAGE_SCN_LNK_OTHER = 0x100,
    LIBUTIL_NT_IMAGE_SCN_LNK_INFO = 0x200,
    LIBUTIL_NT_IMAGE_SCN_TYPE_OVER = 0x400,
    LIBUTIL_NT_IMAGE_SCN_LNK_REMOVE = 0x800,
    LIBUTIL_NT_IMAGE_SCN_LNK_COMDAT = 0x1000,
    LIBUTIL_NT_IMAGE_SCN_MEM_FARDATA = 0x8000,
    LIBUTIL_NT_IMAGE_SCN_MEM_PURGEABLE = 0x20000,
    LIBUTIL_NT_IMAGE_SCN_MEM_16BIT = 0x20000,
    LIBUTIL_NT_IMAGE_SCN_MEM_LOCKED = 0x40000,
    LIBUTIL_NT_IMAGE_SCN_MEM_PRELOAD = 0x80000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_1BYTES = 0x100000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_2BYTES = 0x200000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_4BYTES = 0x300000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_8BYTES = 0x400000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_16BYTES = 0x500000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_32BYTES = 0x600000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_64BYTES = 0x700000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_128BYTES = 0x800000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_256BYTES = 0x900000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_512BYTES = 0xA00000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_1024BYTES = 0xB00000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_2048BYTES = 0xC00000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_4096BYTES = 0xD00000,
    LIBUTIL_NT_IMAGE_SCN_ALIGN_8192BYTES = 0xE00000,
    LIBUTIL_NT_IMAGE_SCN_LNK_NRELOC_OVFL = 0x1000000, // IMAGE_SCN_LNK_NRELOC_OVFL indicates that the count of relocations for the section exceeds the 16 bits reserved for it in section header. If the bit is set and the NumberOfRelocations field in the section header is 0xffff, the actual relocation count is stored in the 32-bit VirtualAddress field of the first relocation.
    LIBUTIL_NT_IMAGE_SCN_MEM_DISCARDABLE = 0x2000000,
    LIBUTIL_NT_IMAGE_SCN_MEM_NOT_CACHED = 0x4000000,
    LIBUTIL_NT_IMAGE_SCN_MEM_NOT_PAGED = 0x8000000,
    LIBUTIL_NT_IMAGE_SCN_MEM_SHARED = 0x10000000,
    LIBUTIL_NT_IMAGE_SCN_MEM_EXECUTE = 0x20000000,
    LIBUTIL_NT_IMAGE_SCN_MEM_READ = 0x40000000,
    LIBUTIL_NT_IMAGE_SCN_MEM_WRITE = 0x80000000
} LIBUTIL_NT_IMAGE_SECTION_CHARACTERISTICS;

#define LIBUTIL_NT_FIRST_SECTION_HEADER64(Header, SizeOfHeaders) \
    (((libutil_size)(Header)) + LIBUTIL_OFFSETOF(LIBUTIL_NT_IMAGE_NT_HEADERS64, OptionalHeader) + (SizeOfHeaders))

#define LIBUTIL_NT_FIRST_SECTION_HEADER32(Header, SizeOfHeaders) \
    (((libutil_size)(Header)) + (libutil_size)(LIBUTIL_OFFSETOF(LIBUTIL_NT_IMAGE_NT_HEADERS32, OptionalHeader)) + (libutil_size)(SizeOfHeaders))

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_SECTION_HEADER
{
    char                                                                    Name[8];                                /*+0x000*/
    libutil_u32                                                             VirtualSize;                            /*+0x008*/
    libutil_u32                                                             VirtualAddress;                         /*+0x00C*/
    libutil_u32                                                             SizeOfRawData;                          /*+0x010*/
    libutil_u32                                                             PointerToRawData;                       /*+0x014*/
    libutil_u32                                                             PointerToRelocations;                   /*+0x018*/
    libutil_u32                                                             PointerToLineNumbers;                   /*+0x01C*/
    libutil_u16                                                             NumberOfRelocations;                    /*+0x020*/
    libutil_u16                                                             NumberOfLineNumbers;                    /*+0x022*/
    libutil_u32                                                             Characteristics;                        /*+0x024*/
} LIBUTIL_NT_IMAGE_SECTION_HEADER;

typedef enum _LIBUTIL_IMAGE_NT_RELOCATION_TYPE
{
    LIBUTIL_NT_IMAGE_REL_I386_ABSOLUTE = 0x0,
    LIBUTIL_NT_IMAGE_REL_I386_DIR16 = 0x1,
    LIBUTIL_NT_IMAGE_REL_I386_REL16 = 0x2,
    LIBUTIL_NT_IMAGE_REL_I386_DIR32 = 0x6,
    LIBUTIL_NT_IMAGE_REL_I386_DIR32NB = 0x7,
    LIBUTIL_NT_IMAGE_REL_I386_SEG12 = 0x9,
    LIBUTIL_NT_IMAGE_REL_I386_SECTION = 0xA,
    LIBUTIL_NT_IMAGE_REL_I386_SECREL = 0xB,
    LIBUTIL_NT_IMAGE_REL_I386_REL32 = 0x14,

    LIBUTIL_NT_IMAGE_REL_ARM_ABSOLUTE = 0x0,
    LIBUTIL_NT_IMAGE_REL_ARM_ADDR32 = 0x1,
    LIBUTIL_NT_IMAGE_REL_ARM_ADDR32NB = 0x2,
    LIBUTIL_NT_IMAGE_REL_ARM_BRANCH24 = 0x3,
    LIBUTIL_NT_IMAGE_REL_ARM_BRANCH11 = 0x4,
    LIBUTIL_NT_IMAGE_REL_ARM_SECTION = 0xE,
    LIBUTIL_NT_IMAGE_REL_ARM_SECREL
} LIBUTIL_IMAGE_NT_RELOCATION_TYPE;

#define LIBUTIL_NT_FIRST_IMPORT_HEADER64(Header, SizeOfHeaders) \
    (((libutil_size)(Header)) + LIBUTIL_OFFSETOF(LIBUTIL_NT_IMAGE_NT_HEADERS64, OptionalHeader) + (SizeOfHeaders))

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_RELOCATION
{
    libutil_u32                                                             VirtualAddress;                         /*+0x000*/
    libutil_u32                                                             SymbolTableIndex;                       /*+0x004*/
    libutil_u16                                                             Type;                                   /*+0x008*/
} LIBUTIL_NT_IMAGE_RELOCATION;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_FIXUP_BLOCK
{
    libutil_u32                                                             PageRVA;                                /*+0x000*/
    libutil_u32                                                             BlockSize;                              /*+0x004*/
} LIBUTIL_NT_IMAGE_FIXUP_BLOCK;

typedef enum _LIBUTIL_NT_IMAGE_FIXUP_TYPE
{
    LIBUTIL_NT_IMAGE_REL_BASED_ABSOLUTE = 0x0,
    LIBUTIL_NT_IMAGE_REL_BASED_HIGH,
    LIBUTIL_NT_IMAGE_REL_BASED_LOW,
    LIBUTIL_NT_IMAGE_REL_BASED_HIGHLOW,
    LIBUTIL_NT_IMAGE_REL_BASED_HIGHADJ,
    LIBUTIL_NT_IMAGE_REL_BASED_MIPS_JMPADDR,
    LIBUTIL_NT_IMAGE_REL_BASED_SECTION,
    LIBUTIL_NT_IMAGE_REL_BASED_REL32,
    LIBUTIL_NT_IMAGE_REL_BASED_MIPS_JMPADDR16,
    LIBUTIL_NT_IMAGE_REL_BASED_DIR64,
    LIBUTIL_NT_IMAGE_REL_BASED_HIGH3ADJ
} LIBUTIL_NT_IMAGE_FIXUP_TYPE;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_FIXUP
{
    libutil_u16                                                             Type : 4;                               /*+0x000*/
    libutil_u16                                                             Offset : 12;                            /*+0x000*/
} LIBUTIL_NT_IMAGE_FIXUP;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED  _LIBUTIL_NT_IMAGE_IMPORT_DIRECTORY
{
    libutil_u32                                                             LookupTableRVA;                         /*+0x000*/
    libutil_u32                                                             TimeDateStamp;                          /*+0x004*/
    libutil_u32                                                             ForwarderChain;                         /*+0x008*/
    libutil_u32                                                             NameRVA;                                /*+0x00C*/
    libutil_u32                                                             ImportAddressTableRVA;                  /*+0x010*/
} LIBUTIL_NT_IMAGE_IMPORT_DIRECTORY;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_IMPORT_LOOKUP_TABLE
{
    libutil_u64                                                             ByOrdinal       : 1;                    /*+0x000*/
    libutil_u64                                                             Ordinal_HintRVA : 63;                   /*+0x000*/
} LIBUTIL_NT_IMAGE_IMPORT_LOOKUP_TABLE;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_IMPORT_HINT_TABLE
{
    libutil_u16                                                             Hint;                                   /*+0x000*/
    char                                                                    Name[1];                                /*+0x002*/
} LIBUTIL_NT_IMAGE_IMPORT_HINT_TABLE;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_EXPORT_DIRECTORY
{
    libutil_u32                                                             ExportFlags;                            /*+0x000*/
    libutil_u32                                                             TimeDateStamp;                          /*+0x004*/
    libutil_u16                                                             MajorVersion;                           /*+0x008*/
    libutil_u16                                                             MinorVersion;                           /*+0x00A*/
    libutil_u32                                                             NameRVA;                                /*+0x00C*/
    libutil_u32                                                             OrdinalBase;                            /*+0x010*/
    libutil_u32                                                             EntriesInAddressTable;                  /*+0x014*/
    libutil_u32                                                             NumberOfNamePointers;                   /*+0x018*/
    libutil_u32                                                             ExportAddressTableRVA;                  /*+0x01C*/
    libutil_u32                                                             NamePointerRVA;                         /*+0x020*/
    libutil_u32                                                             OrdinalTableRVA;                        /*+0x024*/
} LIBUTIL_NT_IMAGE_EXPORT_DIRECTORY;

typedef union LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_IMAGE_EXPORT_ADDRESS_TABLE
{
    libutil_u32                                                             ExportRVA;                              /*+0x000*/
    libutil_u32                                                             ForwarderRVA;                           /*+0x000*/
} LIBUTIL_NT_IMAGE_EXPORT_ADDRESS_TABLE;

#ifdef LIBUTIL_MSVC
#pragma pack(pop)
#endif

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Nt_IsValidImage(void *Image, libutil_bool Is64Bit);

#ifdef LIBUTIL_32_BITS
    typedef LIBUTIL_NT_IMAGE_NT_HEADERS32           LIBUTIL_NT_IMAGE_NT_HEADERS;
#elif defined(LIBUTIL_64_BITS)
    typedef LIBUTIL_NT_IMAGE_NT_HEADERS64           LIBUTIL_NT_IMAGE_NT_HEADERS;
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_NT_DOS_HEADER                   lu_nt_dosheader;
    typedef LIBUTIL_NT_IMAGE_FILE_HEADER            lu_nt_fileheader;

    typedef LIBUTIL_NT_IMAGE_FILE_MACHINE           lu_nt_imagefilemachine;
    typedef LIBUTIL_NT_IMAGE_FILE_CHARACTERISTICS   lu_nt_imagefilecharacteristics;
    typedef LIBUTIL_NT_IMAGE_FILE_MAGIC_NUMBERS     lu_nt_imagefilemagic;
    typedef LIBUTIL_NT_IMAGE_SUBSYSTEM              lu_nt_imagesubsystem;
    typedef LIBUTIL_NT_IMAGE_DLLCHARACTERISTICS     lu_nt_imagedllcharacteristics;

    typedef LIBUTIL_NT_IMAGE_DATA_DIRECTORIES       lu_nt_datadirectories;
    typedef LIBUTIL_NT_IMAGE_DATA_DIRECTORY         lu_nt_datadirectory;

    typedef LIBUTIL_NT_IMAGE_OPTIONAL_HEADER32      lu_nt_optionalheader32;
    typedef LIBUTIL_NT_IMAGE_NT_HEADERS32           lu_nt_ntheaders32;

    typedef LIBUTIL_NT_IMAGE_OPTIONAL_HEADER64      lu_nt_optionalheader64;
    typedef LIBUTIL_NT_IMAGE_NT_HEADERS64           lu_nt_ntheaders64;

    typedef LIBUTIL_NT_IMAGE_NT_HEADERS             lu_nt_ntheaders;

    typedef LIBUTIL_NT_IMAGE_SECTION_CHARACTERISTICS lu_nt_imagesectioncharacteristics;
    typedef LIBUTIL_NT_IMAGE_SECTION_HEADER         lu_nt_imagesectionheader;

    typedef LIBUTIL_IMAGE_NT_RELOCATION_TYPE        lu_nt_relocationtype;
    typedef LIBUTIL_NT_IMAGE_RELOCATION             lu_nt_relocation;

    typedef LIBUTIL_NT_IMAGE_FIXUP_BLOCK            lu_nt_fixupblock;
    typedef LIBUTIL_NT_IMAGE_FIXUP_TYPE             lu_nt_fixuptype;
    typedef LIBUTIL_NT_IMAGE_FIXUP                  lu_nt_fixup;

    typedef LIBUTIL_NT_IMAGE_IMPORT_DIRECTORY       lu_nt_importdirectory;
    typedef LIBUTIL_NT_IMAGE_IMPORT_LOOKUP_TABLE    lu_nt_importlookuptable;
    typedef LIBUTIL_NT_IMAGE_IMPORT_HINT_TABLE      lu_nt_importhinttable;

    typedef LIBUTIL_NT_IMAGE_EXPORT_DIRECTORY       lu_nt_exportdirectory;
    typedef LIBUTIL_NT_IMAGE_EXPORT_ADDRESS_TABLE   lu_nt_exportaddresstable;
#endif

#ifdef __cplusplus
    static_assert(sizeof(LIBUTIL_NT_DOS_HEADER) == 0x40, "sizeof(LIBUTIL_NT_DOS_HEADER) == 0x40");
    static_assert(sizeof(LIBUTIL_NT_IMAGE_FILE_HEADER) == 0x14, "sizeof(LIBUTIL_NT_IMAGE_FILE_HEADER) == 0x14");

    static_assert(sizeof(LIBUTIL_NT_IMAGE_DATA_DIRECTORY) == 0x08, "sizeof(LIBUTIL_NT_IMAGE_DATA_DIRECTORY) == 0x08");
    static_assert(sizeof(LIBUTIL_NT_IMAGE_OPTIONAL_HEADER32) == 0xE0, "sizeof(LIBUTIL_NT_IMAGE_OPTIONAL_HEADER32) == 0xE0");

    static_assert(sizeof(LIBUTIL_NT_IMAGE_OPTIONAL_HEADER64) == 0xF0, "sizeof(LIBUTIL_NT_IMAGE_OPTIONAL_HEADER64) == 0xF0");

    static_assert(sizeof(LIBUTIL_NT_IMAGE_SECTION_HEADER) == 0x28, "sizeof(LIBUTIL_NT_IMAGE_SECTION_HEADER) == 0x28");

    static_assert(sizeof(LIBUTIL_NT_IMAGE_RELOCATION) == 0x0A, "sizeof(LIBUTIL_NT_IMAGE_RELOCATION) == 0x0A");
    static_assert(sizeof(LIBUTIL_NT_IMAGE_FIXUP_BLOCK) == 0x08, "sizeof(LIBUTIL_NT_IMAGE_FIXUP_BLOCK) == 0x08");
    static_assert(sizeof(LIBUTIL_NT_IMAGE_FIXUP) == 0x02, "sizeof(LIBUTIL_NT_IMAGE_FIXUP) == 0x02");

    static_assert(sizeof(LIBUTIL_NT_IMAGE_IMPORT_DIRECTORY) == 0x14, "sizeof(LIBUTIL_NT_IMAGE_IMPORT_DIRECTORY) == 0x14");
    static_assert(sizeof(LIBUTIL_NT_IMAGE_IMPORT_LOOKUP_TABLE) == 0x08, "sizeof(LIBUTIL_NT_IMAGE_IMPORT_LOOKUP_TABLE) == 0x08");
    static_assert(sizeof(LIBUTIL_NT_IMAGE_IMPORT_HINT_TABLE) == 0x03, "sizeof(LIBUTIL_NT_IMAGE_IMPORT_HINT_TABLE) == 0x03");

    static_assert(sizeof(LIBUTIL_NT_IMAGE_EXPORT_DIRECTORY) == 0x28, "sizeof(LIBUTIL_NT_IMAGE_EXPORT_DIRECTORY) == 0x08");
    static_assert(sizeof(LIBUTIL_NT_IMAGE_EXPORT_ADDRESS_TABLE) == 0x04, "sizeof(LIBUTIL_NT_IMAGE_EXPORT_ADDRESS_TABLE) == 0x04");
#endif

#endif
