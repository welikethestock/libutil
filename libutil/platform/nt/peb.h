#ifndef __LIBUTIL_PLATFORM_NT_PEB__
#define __LIBUTIL_PLATFORM_NT_PEB__

#include "../../common/decl.h"
#include "common.h"

LIBUTIL_EXTERN_C_BLOCK_START

#ifdef LIBUTIL_MSVC
#pragma pack(push, 1)
#endif

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_PEB32
{
    libutil_u8                  InheritedAddressSpace;                                                                  /*+0x000*/
    libutil_u8                  ReadImageFileExecOptions;                                                               /*+0x001*/
    libutil_u8                  BeingDebugged;                                                                          /*+0x002*/
    struct
    {
        libutil_bool                ImageUsesLargePages : 1;
        libutil_bool                IsProtectedProcess : 1;
        libutil_bool                IsImageDynamicallyRelocated : 1;
        libutil_bool                SkipPatchingUser32Forwarders : 1;
        libutil_bool                IsPackagedProcess : 1;
        libutil_bool                IsAppContainer : 1;
        libutil_bool                IsProtectedProcessLight : 1;
        libutil_u8                  SpareBits : 1;
    } BitField;                                                                                                         /*+0x003*/
    libutil_u32                 Mutant;                                                                                 /*+0x004*/
    libutil_u32                 ImageBaseAddress;                                                                       /*+0x008*/
    libutil_u32                 Ldr;                                                /*_PEB_LDR_DATA* */                 /*+0x00C*/
    libutil_u32                 ProcessParameters;                                  /*_RTL_USER_PROCESS_PARAMETERS* */  /*+0x010*/
    libutil_u32                 SubSystemData;                                                                          /*+0x014*/
    libutil_u32                 ProcessHeap;                                                                            /*+0x018*/
    libutil_u32                 FastPebLock;                                        /* _RTL_CRITICAL_SESSION* */        /*+0x01C*/
    libutil_u32                 AtlThunkSListPtr;                                                                       /*+0x020*/
    libutil_u32                 IFEOKey;                                                                                /*+0x024*/
    struct
    {
        libutil_bool                ProcessInJob : 1;
        libutil_bool                ProcessInitializing : 1;
        libutil_bool                ProcessUsingVEH : 1;
        libutil_bool                ProcessUsingVCH : 1;
        libutil_bool                ProcessUsingFTH : 1;
        libutil_u8                  ReservedBits0 : 3;
        libutil_u8                  ReservedBits1 : 8;
        libutil_u8                  ReservedBits2 : 8;
        libutil_u8                  ReservedBits3 : 8;
    } CrossProcessFlags;                                                                                                /*+0x028*/
    union
    {
        libutil_u32                 KernelCallbackTable;                                                                /*+0x02C*/
        libutil_u32                 UserSharedInfoPtr;                                                                  /*+0x02C*/
    };
    libutil_u32                 SystemReserved[1];                                                                      /*+0x030*/
    libutil_u32                 AtlThunkSListPtr32;                                                                     /*+0x034*/
    libutil_u32                 ApiSetMap;                                                                              /*+0x038*/
    libutil_u32                 TlsExpansionCounter;                                                                    /*+0x03C*/
    libutil_u32                 TlsBitmap;                                                                              /*+0x040*/
    libutil_u32                 TlsBitmapBits[2];                                                                       /*+0x044*/
    libutil_u32                 ReadOnlySharedMemoryBase;                                                               /*+0x04C*/
    libutil_u32                 SparePvoid0;                                                                            /*+0x050*/
    libutil_u32                 ReadOnlyStaticServerData;                           /*void** */                         /*+0x054*/
    libutil_u32                 AnsiCodePageData;                                                                       /*+0x058*/
    libutil_u32                 OemCodePageData;                                                                        /*+0x05C*/
    libutil_u32                 UnicodeCaseTableData;                                                                   /*+0x060*/
    libutil_u32                 NumberOfProcessors;                                                                     /*+0x064*/
    libutil_u32                 NtGlobalFlag;                                                                           /*+0x068*/
    libutil_u8                  Padding1[4];                                                                            /*+0x06C*/
    LIBUTIL_NT_LARGE_INTEGER    CriticalSectionTimeout;                                                                 /*+0x070*/
    libutil_u32                 HeapSegmentReserve;                                                                     /*+0x078*/
    libutil_u32                 HeapSegmentCommit;                                                                      /*+0x07C*/
    libutil_u32                 HeapDeCommitTotalFreeThreshold;                                                         /*+0x080*/
    libutil_u32                 HeapDeCommitFreeBlockThreshold;                                                         /*+0x084*/
    libutil_u32                 NumberOfHeaps;                                                                          /*+0x088*/
    libutil_u32                 MaximumNumberOfHeaps;                                                                   /*+0x08C*/
    libutil_u32                 ProcessHeaps;                                       /*libutil_u32* */                   /*+0x090*/
    libutil_u32                 GdiSharedHandleTable;                                                                   /*+0x094*/
    libutil_u32                 ProcessStarterHelper;                                                                   /*+0x098*/
    libutil_u32                 GdiDCAttributeList;                                                                     /*+0x09C*/
    libutil_u32                 LoaderLock;                                         /*_RTL_CRITICAL_SESSION* */         /*+0x0A0*/
    libutil_u32                 OSMajorVersion;                                                                         /*+0x0A4*/
    libutil_u32                 OSMinorVersion;                                                                         /*+0x0A8*/
    libutil_u16                 OSBuildNumber;                                                                          /*+0x0AC*/
    libutil_u16                 OSCSDVersion;                                                                           /*+0x0AE*/
    libutil_u32                 OSPlatformId;                                                                           /*+0x0B0*/
    libutil_u32                 ImageSubsystem;                                                                         /*+0x0B4*/
    libutil_u32                 ImageSubsystemMajorVersion;                                                             /*+0x0B8*/
    libutil_u32                 ImageSubsystemMinorVersion;                                                             /*+0x0BC*/
    libutil_u32                 ActiveProcessAffinityMask;                                                              /*+0x0C0*/
    libutil_u32                 GdiHandleBuffer[34];                                                                    /*+0x0C4*/
    libutil_u32                 PostProcessInitRoutine;                                                                 /*+0x14C*/
    libutil_u32                 TlsExpansionBitmap;                                                                     /*+0x150*/
    libutil_u32                 TlsExpansionBitmapBits[32];                                                             /*+0x154*/
    libutil_u32                 SessionId;                                                                              /*+0x1D4*/
    LIBUTIL_NT_ULARGE_INTEGER   AppCompatFlags;                                                                         /*+0x1D8*/
    LIBUTIL_NT_ULARGE_INTEGER   AppCompatFlagsUser;                                                                     /*+0x1E0*/
    libutil_u32                 ShimData;                                                                               /*+0x1E8*/
    libutil_u32                 AppCompatInfo;                                                                          /*+0x1EC*/
    LIBUTIL_NT_UNICODE_STRING32 CSDVersion;                                                                             /*+0x1F0*/
    libutil_u32                 ActivationContextData;                              /*_ACTIVATION_CONTEXT_DATA* */      /*+0x1F8*/
    libutil_u32                 ProcessAssemblyStorageMap;                          /*_ASSEMBLY_STORAGE_MAP* */         /*+0x1FC*/
    libutil_u32                 SystemDefaultActivationContextData;                 /*_ACTIVATION_CONTEXT_DATA* */      /*+0x200*/
    libutil_u32                 SystemAssemblyStorageMap;                           /*_ASSEMBLY_STORAGE_MAP* */         /*+0x204*/
    libutil_u32                 MinimumStackCommit;                                                                     /*+0x208*/
    libutil_u32                 FlsCallback;                                        /*_FLS_CALLBACK_INFO* */            /*+0x20C*/
    LIBUTIL_NT_LIST_ENTRY32     FlsListHead;                                                                            /*+0x210*/
    libutil_u32                 FlsBitmap;                                                                              /*+0x218*/
    libutil_u32                 FlsBitmapBits[4];                                                                       /*+0x21C*/
    libutil_u32                 FlsHighIndex;                                                                           /*+0x22C*/
    libutil_u32                 WerRegistrationData;                                                                    /*+0x230*/
    libutil_u32                 WerShipAssertPtr;                                                                       /*+0x234*/
    libutil_u32                 pUnused;                                                                                /*+0x238*/
    libutil_u32                 pImageHeaderHash;                                                                       /*+0x23C*/
    struct
    {
        libutil_bool                HeapTracingEnabled : 1;
        libutil_bool                CritSecTracingEnabled : 1;
        libutil_bool                LibLoaderTracingEnabled : 1;
        libutil_u8                  SpareTracingBits0 : 5;
        libutil_u8                  SpareTracingBits1 : 8;
        libutil_u8                  SpareTracingBits2 : 8;
        libutil_u8                  SpareTracingBits3 : 8;
    } TracingFlags;                                                                                                     /*+0x240*/
    libutil_u8                  Padding2[4];                                                                            /*+0x244*/
    libutil_u64                 CsrServerReadOnlySharedMemoryBase;                                                      /*+0x248*/
} LIBUTIL_NT_PEB32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_PEB64
{
    libutil_u8                  InheritedAddressSpace;                                                                  /*+0x000*/
    libutil_u8                  ReadImageFileExecOptions;                                                               /*+0x001*/
    libutil_u8                  BeingDebugged;                                                                          /*+0x002*/
    struct
    {
        libutil_bool                ImageUsesLargePages : 1;
        libutil_bool                IsProtectedProcess : 1;
        libutil_bool                IsImageDynamicallyRelocated : 1;
        libutil_bool                SkipPatchingUser32Forwarders : 1;
        libutil_bool                IsPackagedProcess : 1;
        libutil_bool                IsAppContainer : 1;
        libutil_bool                IsProtectedProcessLight : 1;
        libutil_u8                  SpareBits : 1;
    } BitField;                                                                                                         /*+0x003*/
    libutil_u8                  Padding0[4];                                                                            /*+0x004*/
    libutil_u64                 Mutant;                                                                                 /*+0x008*/
    libutil_u64                 ImageBaseAddress;                                                                       /*+0x010*/
    libutil_u64                 Ldr;                                                /*_PEB_LDR_DATA* */                 /*+0x018*/
    libutil_u64                 ProcessParameters;                                  /*_RTL_USER_PROCESS_PARAMETERS* */  /*+0x020*/
    libutil_u64                 SubSystemData;                                                                          /*+0x028*/
    libutil_u64                 ProcessHeap;                                                                            /*+0x030*/
    libutil_u64                 FastPebLock;                                        /* _RTL_CRITICAL_SESSION* */        /*+0x038*/
    libutil_u64                 AtlThunkSListPtr;                                                                       /*+0x040*/
    libutil_u64                 IFEOKey;                                                                                /*+0x048*/
    struct
    {
        libutil_bool                ProcessInJob : 1;
        libutil_bool                ProcessInitializing : 1;
        libutil_bool                ProcessUsingVEH : 1;
        libutil_bool                ProcessUsingVCH : 1;
        libutil_bool                ProcessUsingFTH : 1;
        libutil_u8                  ReservedBits0 : 3;
        libutil_u8                  ReservedBits1 : 8;
        libutil_u8                  ReservedBits2 : 8;
        libutil_u8                  ReservedBits3 : 8;
    } CrossProcessFlags; /*+0x050*/
    libutil_u8                      Padding1[4];                                                                        /*+0x054*/
    union
    {
        libutil_u64                 KernelCallbackTable;                                                                /*+0x058*/
        libutil_u64                 UserSharedInfoPtr;                                                                  /*+0x058*/
    };
    libutil_u32                 SystemReserved[1];                                                                      /*+0x060*/
    libutil_u32                 AtlThunkSListPtr32;                                                                     /*+0x064*/
    libutil_u64                 ApiSetMap;                                                                              /*+0x068*/
    libutil_u32                 TlsExpansionCounter; /*+0x070*/
    libutil_u8                  Padding2[4];                                                                            /*+0x074*/
    libutil_u64                 TlsBitmap;                                                                              /*+0x078*/
    libutil_u32                 TlsBitmapBits[2];                                                                       /*+0x080*/
    libutil_u64                 ReadOnlySharedMemoryBase;                                                               /*+0x088*/
    libutil_u64                 SparePvoid0;                                                                            /*+0x090*/
    libutil_u64                 ReadOnlyStaticServerData;                           /*void** */                         /*+0x098*/
    libutil_u64                 AnsiCodePageData;                                                                       /*+0x0AO*/
    libutil_u64                 OemCodePageData;                                                                        /*+0x0A8*/
    libutil_u64                 UnicodeCaseTableData;                                                                   /*+0x0B0*/
    libutil_u32                 NumberOfProcessors;                                                                     /*+0x0B8*/
    libutil_u32                 NtGlobalFlag;                                                                           /*+0x0BC*/
    LIBUTIL_NT_LARGE_INTEGER    CriticalSectionTimeout;                                                                 /*+0x0C0*/
    libutil_u64                 HeapSegmentReserve;                                                                     /*+0x0C8*/
    libutil_u64                 HeapSegmentCommit;                                                                      /*+0x0D0*/
    libutil_u64                 HeapDeCommitTotalFreeThreshold;                                                         /*+0x0D8*/
    libutil_u64                 HeapDeCommitFreeBlockThreshold;                                                         /*+0x0E0*/
    libutil_u32                 NumberOfHeaps;                                                                          /*+0x0E8*/
    libutil_u32                 MaximumNumberOfHeaps;                                                                   /*+0x0EC*/
    libutil_u64                 ProcessHeaps;                                       /*void** */                         /*+0x0F0*/
    libutil_u64                 GdiSharedHandleTable;                                                                   /*+0x0F8*/
    libutil_u64                 ProcessStarterHelper;                                                                   /*+0x100*/
    libutil_u32                 GdiDCAttributeList;                                                                     /*+0x108*/
    libutil_u8                  Padding3[4];                                                                            /*+0x10C*/
    libutil_u64                 LoaderLock;                                         /*_RTL_CRITICAL_SESSION* */         /*+0x110*/
    libutil_u32                 OSMajorVersion;                                                                         /*+0x118*/
    libutil_u32                 OSMinorVersion;                                                                         /*+0x11C*/
    libutil_u16                 OSBuildNumber;                                                                          /*+0x120*/
    libutil_u16                 OSCSDVersion;                                                                           /*+0x122*/
    libutil_u32                 OSPlatformId;                                                                           /*+0x124*/
    libutil_u32                 ImageSubsystem;                                                                         /*+0x128*/
    libutil_u32                 ImageSubsystemMajorVersion;                                                             /*+0x12C*/
    libutil_u32                 ImageSubsystemMinorVersion;                                                             /*+0x130*/
    libutil_u8                  Padding4[4];                                                                            /*+0x134*/
    libutil_u64                 ActiveProcessAffinityMask;                                                              /*+0x138*/
    libutil_u32                 GdiHandleBuffer[60];                                                                    /*+0x140*/
    libutil_u64                 PostProcessInitRoutine;                                                                 /*+0x230*/
    libutil_u64                 TlsExpansionBitmap;                                                                     /*+0x238*/
    libutil_u32                 TlsExpansionBitmapBits[32];                                                             /*+0x240*/
    libutil_u32                 SessionId;                                                                              /*+0x2C0*/
    libutil_u8                  Padding5[4];                                                                            /*+0x2C4*/
    LIBUTIL_NT_ULARGE_INTEGER   AppCompatFlags;                                                                         /*+0x2C8*/
    LIBUTIL_NT_ULARGE_INTEGER   AppCompatFlagsUser;                                                                     /*+0x2D0*/
    libutil_u64                 ShimData;                                                                               /*+0x2D8*/
    libutil_u64                 AppCompatInfo;                                                                          /*+0x2E0*/
    LIBUTIL_NT_UNICODE_STRING64 CSDVersion;                                                                             /*+0x2E8*/
    libutil_u64                 ActivationContextData;                              /*_ACTIVATION_CONTEXT_DATA* */      /*+0x2F8*/
    libutil_u64                 ProcessAssemblyStorageMap;                          /*_ASSEMBLY_STORAGE_MAP* */         /*+0x300*/
    libutil_u64                 SystemDefaultActivationContextData;                 /*_ACTIVATION_CONTEXT_DATA* */      /*+0x308*/
    libutil_u64                 SystemAssemblyStorageMap;                           /*_ASSEMBLY_STORAGE_MAP* */         /*+0x310*/
    libutil_u64                 MinimumStackCommit;                                                                     /*+0x318*/
    libutil_u64                 FlsCallback;                                        /*_FLS_CALLBACK_INFO* */            /*+0x320*/
    LIBUTIL_NT_LIST_ENTRY64     FlsListHead;                                                                            /*+0x328*/
    libutil_u64                 FlsBitmap;                                                                              /*+0x338*/
    libutil_u32                 FlsBitmapBits[4];                                                                       /*+0x340*/
    libutil_u32                 FlsHighIndex;                                                                           /*+0x350*/
    libutil_u64                 WerRegistrationData;                                                                    /*+0x358*/
    libutil_u64                 WerShipAssertPtr;                                                                       /*+0x360*/
    libutil_u8                  Padding6[4];                                                                            /*+0x364*/
    libutil_u64                 pUnused;                                                                                /*+0x368*/
    libutil_u64                 pImageHeaderHash;                                                                       /*+0x370*/
    struct
    {
        libutil_bool                HeapTracingEnabled : 1;
        libutil_bool                CritSecTracingEnabled : 1;
        libutil_bool                LibLoaderTracingEnabled : 1;
        libutil_u8                  SpareTracingBits0 : 5;
        libutil_u8                  SpareTracingBits1 : 8;
        libutil_u8                  SpareTracingBits2 : 8;
        libutil_u8                  SpareTracingBits3 : 8;
    } TracingFlags;                                                                                                     /*+0x378*/
    libutil_u8                  Padding7[4];                                                                            /*+0x37C*/
    libutil_u64                 CsrServerReadOnlySharedMemoryBase;                                                      /*+0x380*/
} LIBUTIL_NT_PEB64;

#ifdef LIBUTIL_MSVC
#pragma pack(pop)
#endif

#ifdef LIBUTIL_WINDOWS
    #ifdef LIBUTIL_X86
        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_PEB32    *LibUtil_Nt_GetPeb32();

        LIBUTIL_API LIBUTIL_IMPORT
        libutil_u64         LibUtil_Nt_GetPeb64();

        LIBUTIL_API LIBUTIL_IMPORT
        libutil_bool        LibUtil_Nt_ReadPeb64(LIBUTIL_NT_PEB64 *PEB);
    #elif definded(LIBUTIL_X86_64)
        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_PEB64    *LibUtil_Nt_GetPeb64();
    #endif
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_NT_PEB32    lu_nt_peb32;
    typedef LIBUTIL_NT_PEB64    lu_nt_peb64;
#endif

#ifdef LIBUTIL_32_BITS
    typedef LIBUTIL_NT_PEB32    lu_nt_peb;
#else
    typedef LIBUTIL_NT_PEB64    lu_nt_peb;
#endif

#ifdef LIBUTIL_WINDOWS
    #ifndef LIBUTIL_DISABLE_SHORT_NAMES
        #ifdef LIBUTIL_32_BITS
            #define lu_nt_getpeb                LibUtil_Nt_GetPeb32
            #define lu_nt_getpeb64              LibUtil_Nt_GetPeb64
            #define lu_nt_readpeb64             LibUtil_Nt_ReadPeb64

            #define LibUtil_Nt_GetPeb           LibUtil_Nt_GetPeb32
        #else
            #define lu_nt_getpeb                LibUtil_Nt_GetPeb64
            #define lu_nt_getpeb64              LibUtil_Nt_GetPeb64

            #define LibUtil_Nt_GetPeb           LibUtil_Nt_GetPeb64
        #endif
    #endif
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#ifdef __cplusplus
    static_assert(sizeof(LIBUTIL_NT_PEB32) == 0x250, "sizeof(LIBUTIL_NT_PEB64) == 0x250");
    static_assert(sizeof(LIBUTIL_NT_PEB64) == 0x388, "sizeof(LIBUTIL_NT_PEB64) == 0x388");
#endif

#endif
