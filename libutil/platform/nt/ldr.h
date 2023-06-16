#ifndef __LIBUTIL_PLATFORM_NT_LDR__
#define __LIBUTIL_PLATFORM_NT_LDR__

#include "../../common/decl.h"
#include "common.h"

LIBUTIL_EXTERN_C_BLOCK_START

#ifdef LIBUTIL_MSVC
#pragma pack(push, 1)
#endif

typedef enum _LIBUTIL_NT_BASE_NAME_HASH_VALUES
{
    LIBUTIL_NT_BASE_NAME_HASH_NTDLL = 0xCE4A7546,
    LIBUTIL_NT_BASE_NAME_HASH_KERNEL32 = 0xDDBCDC44
} LIBUTIL_NT_BASE_NAME_HASH_VALUES;

typedef enum _LIBUTIL_NT_LDR_DLL_LOAD_REASON
{
    LIBUTIL_NT_LoadReasonStaticDependency = 0,
    LIBUTIL_NT_LoadReasonStaticForwarderDependency,
    LIBUTIL_NT_LoadReasonDynamicForwarderDependency,
    LIBUTIL_NT_LoadReasonDelayloadDependency,
    LIBUTIL_NT_LoadReasonDynamicLoad,
    LIBUTIL_NT_LoadReasonAsImageLoad,
    LIBUTIL_NT_LoadReasonAsDataLoad,
    LIBUTIL_NT_LoadReasonEnclavePrimary,
    LIBUTIL_NT_LoadReasonEnclaveDependency,
    LIBUTIL_NT_LoadReasonPatchImage,
    LIBUTIL_NT_LoadReasonUnknown = -1
} LIBUTIL_NT_LDR_DLL_LOAD_REASON;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_PEB_LDR_DATA32
{
    libutil_u32                             Length;                                                         /*+0x000*/
    libutil_u32                             Initialized;                                                    /*+0x004*/
    libutil_u32                             SsHandle;                                                       /*+0x008*/
    LIBUTIL_NT_LIST_ENTRY32                 InLoadOrderModuleList;                                          /*+0x00C*/
    LIBUTIL_NT_LIST_ENTRY32                 InMemoryOrderModuleList;                                        /*+0x014*/
    LIBUTIL_NT_LIST_ENTRY32                 InInitializationOrderModuleList;                                /*+0x01C*/
    libutil_u32                             EntryInProgress;                                                /*+0x024*/
    libutil_u32                             ShutdownInProgress;                                             /*+0x028*/
    libutil_u32                             ShutdownThreadId;                                               /*+0x02C*/
} LIBUTIL_NT_PEB_LDR_DATA32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32
{
    LIBUTIL_NT_LIST_ENTRY32             InLoadOrderMemoryLinks;                                             /*+0x000*/
    LIBUTIL_NT_LIST_ENTRY32             InMemoryOrderModuleLinks;                                           /*+0x008*/
    union
    {
        LIBUTIL_NT_LIST_ENTRY32             InInitializationOrderLinks;                                     /*+0x010*/
        LIBUTIL_NT_LIST_ENTRY32             InProgessLinks;                                                 /*+0x010*/
    };
    libutil_u32                         DllBase;                                                            /*+0x018*/
    libutil_u32                         EntryPoint;                                                         /*+0x01C*/
    libutil_u32                         SizeOfImage;                                                        /*+0x020*/
    LIBUTIL_NT_UNICODE_STRING32         FullDllName;                                                        /*+0x024*/
    LIBUTIL_NT_UNICODE_STRING32         BaseDllName;                                                        /*+0x02C*/
    union
    {
        libutil_u8                          FlagGroup[4];                                                   /*+0x034*/
        struct
        {
            libutil_bool                        PackagedBinary : 1;                                         /*+0x034*/
            libutil_bool                        MarkedForRemoval : 1;                                       /*+0x034*/
            libutil_bool                        ImageDll : 1;                                               /*+0x034*/
            libutil_bool                        LoadNotificationsSent : 1;                                  /*+0x034*/
            libutil_bool                        TelemetryEntryProcessed : 1;                                /*+0x034*/
            libutil_bool                        ProcessStaticImport : 1;                                    /*+0x034*/
            libutil_bool                        InLegacyLists : 1;                                          /*+0x034*/
            libutil_bool                        InIndexes : 1;                                              /*+0x034*/
            libutil_bool                        ShimDll : 1;                                                /*+0x035*/
            libutil_bool                        InExceptionTable : 1;                                       /*+0x035*/
            libutil_bool                        ReservedFlags1 : 2;                                         /*+0x035*/
            libutil_bool                        LoadInProgress : 1;                                         /*+0x035*/
            libutil_bool                        LoadConfigProcessed : 1;                                    /*+0x035*/
            libutil_bool                        EntryProcessed : 1;                                         /*+0x035*/
            libutil_bool                        ProtectDelayLoad : 1;                                       /*+0x035*/
            libutil_bool                        ReservedFlags3 : 2;                                         /*+0x036*/
            libutil_bool                        DontCallForThreads : 1;                                     /*+0x036*/
            libutil_bool                        ProcessAttachCalled : 1;                                    /*+0x036*/
            libutil_bool                        ProcessAttachFailed : 1;                                    /*+0x036*/
            libutil_bool                        CorDeferredValidate : 1;                                    /*+0x036*/
            libutil_bool                        CorImage : 1;                                               /*+0x036*/
            libutil_bool                        DontRelocate : 1;                                           /*+0x036*/
            libutil_bool                        CorILOnly : 1;                                              /*+0x037*/
            libutil_bool                        ChpeImage : 1;                                              /*+0x037*/
            libutil_bool                        ChpeEmulatorImage : 1;                                      /**0x037*/
            libutil_bool                        ReservedFlags5 : 1;                                         /*+0x037*/
            libutil_bool                        Redirected : 1;                                             /*+0x037*/
            libutil_bool                        ReservedFlags6 : 2;                                         /*+0x037*/
            libutil_bool                       CompatDatabaseProcessed : 1;                                 /*+0x037*/
        } Flags;
    };
    libutil_u16                             ObsoleteLoadCount;                                              /*+0x038*/
    libutil_u16                             TlsIndex;                                                       /*+0x03A*/
    LIBUTIL_NT_LIST_ENTRY32                 HashLinks;                                                      /*+0x03C*/
    libutil_u32                             TimeDateStamp;                                                  /*+0x044*/
    libutil_u32                             EntryPointActivationContext;    /*_ACTIVATION_CONTEXT* */       /*+0x048*/
    libutil_u32                             Lock;                                                           /*+0x04C*/
    libutil_u32                             DdagNode;                       /*_LDR_DDAG_NODE* */            /*+0x050*/
    LIBUTIL_NT_LIST_ENTRY32                 NodeModuleLink;                                                 /*+0x058*/
    union
    {
        libutil_u32                             SnapContext;                    /*_LDR_DLL_SNAP_CONTEXT* */ /*+0x05C*/
        libutil_u32                             LoadContext;                    /*_LDR_LOAD_CONTEXT* */     /*+0x05C*/
    };
    libutil_u32                             ParentDllBase;                                                  /*+0x060*/
    libutil_u32                             SwitchBackContext;                                              /*+0x064*/
    LIBUTIL_NT_RTL_BALANCED_NODE32          BaseAddressIndexNode;                                           /*+0x06C*/
    LIBUTIL_NT_RTL_BALANCED_NODE32          MappingInfoIndexNode;                                           /*+0x076*/
    libutil_u64                             OriginalBase;                                                   /*+0x080*/
    LIBUTIL_NT_LARGE_INTEGER                LoadTime;                                                       /*+0x088*/
    libutil_u32                             BaseNameHashValue;                                              /*+0x090*/
    LIBUTIL_NT_LDR_DLL_LOAD_REASON          LoadReason;                                                     /*+0x094*/
    libutil_u32                             ImplicitPathOptions;                                            /*+0x098*/
    // Taken from Win11
    libutil_u32                             ReferenceCount;                                                 /*+0x09C*/
    libutil_u32                             DependentLoadFlags;                                             /*+0x0A0*/
    libutil_u8                              SigningLevel;                                                   /*+0x0A4*/
    libutil_u8                              Padding1[3];                                                    /*+0x0A5*/
    libutil_u32                             CheckSum;                                                       /*+0x0A8*/
    libutil_u32                             ActivePatchImageBase;                                           /*+0x0AC*/
    libutil_u32                             HotPatchState;                      /*_LDR_HOT_PATCH_STATE*/    /*+0x0B0*/
} LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_PEB_LDR_DATA64
{
    libutil_u32                         Length;                                                             /*+0x000*/
    libutil_u32                         Initialized;                                                        /*+0x004*/
    libutil_u64                         SsHandle;                                                           /*+0x008*/
    LIBUTIL_NT_LIST_ENTRY64             InLoadOrderModuleList;                                              /*+0x010*/
    LIBUTIL_NT_LIST_ENTRY64             InMemoryOrderModuleList;                                            /*+0x020*/
    LIBUTIL_NT_LIST_ENTRY64             InInitializationOrderModuleList;                                    /*+0x030*/
    libutil_u64                         EntryInProgress;                                                    /*+0x040*/
    libutil_u32                         ShutdownInProgress;                                                 /*+0x048*/
    libutil_u8                          Padding0[4];                                                        /*+0x04C*/
    libutil_u64                         ShutdownThreadId;                                                   /*+0x050*/
} LIBUTIL_NT_PEB_LDR_DATA64;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64
{
    LIBUTIL_NT_LIST_ENTRY64             InLoadOrderMemoryLinks;                                             /*+0x000*/
    LIBUTIL_NT_LIST_ENTRY64             InMemoryOrderModuleLinks;                                           /*+0x010*/
    union
    {
        LIBUTIL_NT_LIST_ENTRY64             InInitializationOrderLinks;                                     /*+0x020*/
        LIBUTIL_NT_LIST_ENTRY64             InProgessLinks;                                                 /*+0x020*/
    };
    libutil_u64                         DllBase;                                                            /*+0x030*/
    libutil_u64                         EntryPoint;                                                         /*+0x038*/
    libutil_u32                         SizeOfImage;                                                        /*+0x040*/
    libutil_u8                          Padding0[4];                                                        /*+0x044*/
    LIBUTIL_NT_UNICODE_STRING64         FullDllName;                                                        /*+0x048*/
    LIBUTIL_NT_UNICODE_STRING64         BaseDllName;                                                        /*+0x058*/
    union
    {
        libutil_u8                          FlagGroup[4];                                                   /*+0x068*/
        struct
        {
            libutil_bool                        PackagedBinary : 1;                                         /*+0x068*/
            libutil_bool                        MarkedForRemoval : 1;                                       /*+0x068*/
            libutil_bool                        ImageDll : 1;                                               /*+0x068*/
            libutil_bool                        LoadNotificationsSent : 1;                                  /*+0x068*/
            libutil_bool                        TelemetryEntryProcessed : 1;                                /*+0x068*/
            libutil_bool                        ProcessStaticImport : 1;                                    /*+0x068*/
            libutil_bool                        InLegacyLists : 1;                                          /*+0x068*/
            libutil_bool                        InIndexes : 1;                                              /*+0x068*/
            libutil_bool                        ShimDll : 1;                                                /*+0x069*/
            libutil_bool                        InExceptionTable : 1;                                       /*+0x069*/
            libutil_bool                        ReservedFlags1 : 2;                                         /*+0x069*/
            libutil_bool                        LoadInProgress : 1;                                         /*+0x069*/
            libutil_bool                        LoadConfigProcessed : 1;                                    /*+0x069*/
            libutil_bool                        EntryProcessed : 1;                                         /*+0x069*/
            libutil_bool                        ProtectDelayLoad : 1;                                       /*+0x069*/
            libutil_bool                        ReservedFlags3 : 2;                                         /*+0x06A*/
            libutil_bool                        DontCallForThreads : 1;                                     /*+0x06A*/
            libutil_bool                        ProcessAttachCalled : 1;                                    /*+0x06A*/
            libutil_bool                        ProcessAttachFailed : 1;                                    /*+0x06A*/
            libutil_bool                        CorDeferredValidate : 1;                                    /*+0x06A*/
            libutil_bool                        CorImage : 1;                                               /*+0x06A*/
            libutil_bool                        DontRelocate : 1;                                           /*+0x06A*/
            libutil_bool                        CorILOnly : 1;                                              /*+0x06B*/
            libutil_bool                        ChpeImage : 1;                                              /*+0x06B*/
            libutil_bool                        ChpeEmulatorImage : 1;                                      /**0x06B*/
            libutil_bool                        ReservedFlags5 : 1;                                         /*+0x06B*/
            libutil_bool                        Redirected : 1;                                             /*+0x06B*/
            libutil_bool                        ReservedFlags6 : 2;                                         /*+0x06B*/
            libutil_bool                       CompatDatabaseProcessed : 1;                                 /*+0x06B*/
        } Flags;
    };
    libutil_u16                             ObsoleteLoadCount;                                              /*+0x06C*/
    libutil_u16                             TlsIndex;                                                       /*+0x06E*/
    LIBUTIL_NT_LIST_ENTRY64                 HashLinks;                                                      /*+0x070*/
    libutil_u32                             TimeDateStamp;                                                  /*+0x080*/
    libutil_u8                              Padding1[4];                                                    /*+0x084*/
    libutil_u64                             EntryPointActivationContext;    /*_ACTIVATION_CONTEXT* */       /*+0x088*/
    libutil_u64                             Lock;                                                           /*+0x090*/
    libutil_u64                             DdagNode;                       /*_LDR_DDAG_NODE* */            /*+0x098*/
    LIBUTIL_NT_LIST_ENTRY64                 NodeModuleLink;                                                 /*+0x0A0*/
    union
    {
        libutil_u64                             SnapContext;                    /*_LDR_DLL_SNAP_CONTEXT* */ /*+0x0B0*/
        libutil_u64                             LoadContext;                    /*_LDR_LOAD_CONTEXT* */     /*+0x0B0*/
    };
    libutil_u64                             ParentDllBase;                                                  /*+0x0B8*/
    libutil_u64                             SwitchBackContext;                                              /*+0x0C0*/
    LIBUTIL_NT_RTL_BALANCED_NODE64          BaseAddressIndexNode;                                           /*+0x0C8*/
    LIBUTIL_NT_RTL_BALANCED_NODE64          MappingInfoIndexNode;                                           /*+0x0E0*/
    libutil_u64                             OriginalBase;                                                   /*+0x0F8*/
    LIBUTIL_NT_LARGE_INTEGER                LoadTime;                                                       /*+0x100*/
    libutil_u32                             BaseNameHashValue;                                              /*+0x108*/
    LIBUTIL_NT_LDR_DLL_LOAD_REASON          LoadReason;                                                     /*+0x10C*/
    libutil_u32                             ImplicitPathOptions;                                            /*+0x110*/
    // Taken from Win11
    libutil_u32                             ReferenceCount;                                                 /*+0x114*/
    libutil_u32                             DependentLoadFlags;                                             /*+0x118*/
    libutil_u8                              SigningLevel;                                                   /*+0x11C*/
    libutil_u8                              Padding2[3];                                                    /*+0x11D*/
    libutil_u32                             CheckSum;                                                       /*+0x120*/
    libutil_u8                              Padding3[4];                                                    /*+0x124*/
    libutil_u64                             ActivePatchImageBase;                                           /*+0x128*/
    libutil_u32                             HotPatchState;                      /*_LDR_HOT_PATCH_STATE*/    /*+0x130*/
    libutil_u8                              Padding4[4];                                                    /*+0x134*/
} LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64;

#ifdef LIBUTIL_MSVC
#pragma pack(pop)
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_NT_LDR_DLL_LOAD_REASON      lu_nt_ldrloadreason;

    typedef LIBUTIL_NT_PEB_LDR_DATA32           lu_nt_ldrdata32;
    typedef LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32   lu_nt_ldrdataentry32;

    typedef LIBUTIL_NT_PEB_LDR_DATA64           lu_nt_ldrdata64;
    typedef LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64   lu_nt_ldrdataentry64;

    #ifdef LIBUTIL_32_BITS
        typedef LIBUTIL_NT_PEB_LDR_DATA32           lu_nt_ldrdata;
        typedef LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32   lu_nt_ldrdataentry;
    #else
        typedef LIBUTIL_NT_PEB_LDR_DATA64           lu_nt_ldrdata;
        typedef LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64   lu_nt_ldrdataentry;
    #endif
#endif

#ifdef LIBUTIL_WINDOWS
    #ifdef LIBUTIL_X86
        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_PEB_LDR_DATA32           *LibUtil_Nt_GetLdrData32();

        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32   *LibUtil_Nt_ReadLdrDataEntry32();

        #ifndef LIBUTIL_X86_PURE32
            LIBUTIL_API LIBUTIL_IMPORT
            libutil_u64                         LibUtil_Nt_GetLdrData64();

            LIBUTIL_API LIBUTIL_IMPORT
            libutil_bool                        LibUtil_Nt_ReadLdrData64(LIBUTIL_NT_PEB_LDR_DATA64 *Ldr);

            LIBUTIL_API LIBUTIL_IMPORT
            libutil_u64                         LibUtil_Nt_GetLdrDataEntry64();

            LIBUTIL_API LIBUTIL_IMPORT
            libutil_bool                        LibUtil_Nt_ReadLdrDataEntry64(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64 *Entry, libutil_u64 Address);
        #endif

        LIBUTIL_API LIBUTIL_IMPORT
        void                                    *LibUtil_Nt_GetLdrModuleExport32(void *Module, libutil_u32 Hash);

        LIBUTIL_API LIBUTIL_IMPORT
        void                                    *LibUtil_Nt_GetLdrExport32(libutil_u32 ModuleHash, libutil_u32 Hash);
    #elif defined(LIBUTIL_X86_64)
        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_PEB_LDR_DATA64           *LibUtil_Nt_GetLdrData64();

        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64   *LibUtil_Nt_GetLdrDataEntry64();
    #endif
#endif

#ifdef LIBUTIL_WINDOWS
    #ifdef LIBUTIL_32_BITS
        #define LibUtil_Nt_GetLdrData       LibUtil_Nt_GetLdrData32
        #define LibUtil_Nt_GetLdrDataEntry  LibUtil_Nt_GetLdrDataEntry32
    #else
        #define LibUtil_Nt_GetLdrData       LibUtil_Nt_GetLdrData64
        #define LibUtil_Nt_GetLdrDataEntry  LibUtil_Nt_GetLdrDataEntry64
    #endif

    #ifndef LIBUTIL_DISABLE_SHORT_NAMES
        #ifdef LIBUTIL_32_BITS
            #define lu_nt_getldrdata            LibUtil_Nt_GetLdrData32
            #define lu_nt_getldrdataentry       LibUtil_Nt_GetLdrDataEntry32

            #ifndef LIBUTIL_X86_PURE32
                #define lu_nt_getldrdata64          LibUtil_Nt_GetLdrData64
                #define lu_nt_readldrdata64         LibUtil_Nt_ReadLdrData64
                #define lu_nt_readldrdataentry64    LibUtil_Nt_ReadLdrDataEntry64
            #endif
        #else
            #define lu_nt_getldrdata            LibUtil_Nt_GetLdrData64
            #define lu_nt_getldrdata64          LibUtil_Nt_GetLdrData64

            #define lu_nt_getldrdataentry       LibUtil_Nt_GetLdrDataEntry64
            #define lu_nt_getldrdataentry64     LibUtil_Nt_GetLdrDataEntry64
        #endif
    #endif
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#ifdef __cplusplus
    static_assert(sizeof(LIBUTIL_NT_PEB_LDR_DATA32) == 0x30, "sizeof(LIBUTIL_NT_PEB_LDR_DATA32) == 0x30");
    static_assert(sizeof(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32) == 0xB4, "sizeof(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32) == 0xB4");

    static_assert(sizeof(LIBUTIL_NT_PEB_LDR_DATA64) == 0x58, "sizeof(LIBUTIL_NT_PEB_LDR_DATA64) == 0x58");
    static_assert(sizeof(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64) == 0x138, "sizeof(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64) == 0x138");
#endif

#endif
