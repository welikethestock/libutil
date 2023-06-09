#ifndef __LIBUTIL_PLATFORM_NT_TEB__
#define __LIBUTIL_PLATFORM_NT_TEB__

#include "../../common/decl.h"
#include "common.h"
#include "tib.h"

LIBUTIL_EXTERN_C_BLOCK_START

#ifdef LIBUTIL_MSVC
#pragma pack(push, 1)
#endif

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_GDI_TEB_BATCH32
{
    libutil_u32                                                 Offset : 31;                    /*+0x0000*/
    libutil_u32                                                 HasRenderingCommand : 1;        /*+0x0000*/
    libutil_u32                                                 HDC;                            /*+0x0004*/
    libutil_u32                                                 Buffer[310];                    /*+0x0008*/
} LIBUTIL_NT_GDI_TEB_BATCH32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_TEB32
{
    LIBUTIL_NT_TIB32                                                TIB;                            /*+0x0000*/
    libutil_u32                                                     EnviromentPointer;              /*+0x001C*/
    struct /*_CLIENT_ID*/
    {
        libutil_u32                                                 UniqueProcess;                  /*+0x0020*/
        libutil_u32                                                 UniqueThread;                   /*+0x0020*/
    } ClientID;
    libutil_u32                                                 ActiveRpcHandle;                    /*+0x0028*/
    libutil_u32                                                 ThreadLocalStoragePointer;          /*+0x002C*/
    libutil_u32         /*_PEB* */                              ProcessEnvironmentBlock;            /*+0x0030*/
    libutil_u32                                                 LastErrorValue;                     /*+0x0034*/
    libutil_u32                                                 CountOfOwnedCriticalSections;       /*+0x0038*/
    libutil_u32                                                 CsrClientThread;                    /*+0x003C*/
    libutil_u32                                                 Win32ThreadInfo;                    /*+0x0040*/
    libutil_u32                                                 User32Reserved[26];                 /*+0x0044*/
    libutil_u32                                                 UserReserved[5];                    /*+0x00AC*/
    libutil_u32                                                 WOW32Reserved;                      /*+0x00C0*/
    libutil_u32                                                 CurrentLocale;                      /*+0x00C4*/
    libutil_u32                                                 FpSoftwareStatusRegister;           /*+0x00C8*/
    libutil_u32                                                 ReservedForDbgerInstrumentation[16];/*+0x00CC*/
    libutil_u32                                                 SystemReserved1[26];                /*+0x010C*/
    libutil_u8                                                  PlaceholderCompatibilityMode;       /*+0x0174*/
    libutil_u8                                                  PlaceholderHydrationAlwaysExplicit; /*+0x0175*/
    libutil_u8                                                  PlaceholderReserved[10];            /*+0x0176*/
    libutil_u32                                                 ProxiedProcessId;                   /*+0x0180*/
    LIBUTIL_NT_ACTIVATION_CONTEXT_STACK32                       _ActivationStack;                   /*+0x0184*/
    libutil_u8                                                  WorkingOnBehalfTicket[8];           /*+0x019C*/
    libutil_u32                                                 ExceptionCode;                      /*+0x01A4*/
    libutil_u32         /*_ACTIVATION_CONTEXT_STACK* */         ActivationContextStackPointer;      /*+0x01A8*/
    libutil_u32                                                 InstrumentationCallbackSp;          /*+0x01AC*/
    libutil_u32                                                 InstrumentationCallbackPreviousPc;  /*+0x01B0*/
    libutil_u32                                                 InstrumentationCallbackPreviousSp;  /*+0x01B4*/
    libutil_u8                                                  InstrumentationCallbackDisabled;    /*+0x01B8*/
    libutil_u8                                                  SpareBytes[23];                     /*+0x01B9*/
    libutil_u32                                                 TxFsContext;                        /*+0x01D0*/
    LIBUTIL_NT_GDI_TEB_BATCH32                                  GdiTebBatch;                        /*+0x01D4*/
    struct /*_CLIENT_ID*/
    {
        libutil_u32                                                 UniqueProcess;                  /*+0x06B4*/
        libutil_u32                                                 UniqueThread;                   /*+0x06B4*/
    } RealClientId;
    libutil_u32                                                 GdiCachedProcessHandle;             /*+0x06BC*/
    libutil_u32                                                 GdiClientPID;                       /*+0x06C0*/
    libutil_u32                                                 GdiClientTID;                       /*+0x06C4*/
    libutil_u32                                                 GdiThreadLocalInfo;                 /*+0x06C8*/
    libutil_u32                                                 Win32ClientInfo[62];                /*+0x06CC*/
    libutil_u32                                                 glDispatchTable[233];               /*+0x07C4*/
    libutil_u32                                                 glReserved1[29];                    /*+0x0B68*/
    libutil_u32                                                 glReserved2;                        /*+0x0BDC*/
    libutil_u32                                                 glSectionInfo;                      /*+0x0BE0*/
    libutil_u32                                                 glSection;                          /*+0x0BE4*/
    libutil_u32                                                 glTable;                            /*+0x0BE8*/
    libutil_u32                                                 glCurrentRC;                        /*+0x0BEC*/
    libutil_u32                                                 glContext;                          /*+0x0BF0*/
    libutil_u32                                                 LastStatusValue;                    /*+0x0BF4*/
    LIBUTIL_NT_UNICODE_STRING32                                 StaticUnicodeString;                /*+0x0BF8*/
    libutil_wchar                                               StaticUnicodeBuffer[261];           /*+0x0C00*/
    libutil_u8                                                  Padding1[2];                        /*+0x0E0A*/
    libutil_u32                                                 DeallocationStack;                  /*+0x0E0C*/
    libutil_u32                                                 TlsSlots[64];                       /*+0x0E10*/
    LIBUTIL_NT_LIST_ENTRY32                                     TlsLinks;                           /*+0x0F10*/
    libutil_u32                                                 Vdm;                                /*+0x0F18*/
    libutil_u32                                                 ReservedForNtRpc;                   /*+0x0F1C*/
    libutil_u32                                                 DbgSsReserved[2];                   /*+0x0F20*/
    libutil_u32                                                 HardErrorMode;                      /*+0x0F28*/
    libutil_u32                                                 Instrumentation[9];                 /*+0x0F2C*/
    LIBUTIL_NT_GUID                                             ActivityId;                         /*+0x0F50*/
    libutil_u32                                                 SubProcessTag;                      /*+0x0F60*/
    libutil_u32                                                 PerflibData;                        /*+0x0F64*/
    libutil_u32                                                 EtwTraceData;                       /*+0x0F68*/
    libutil_u32                                                 WinSockData;                        /*+0x0F6C*/
    libutil_u32                                                 GdiBatchCount;                      /*+0x0F70*/
    struct
    {
        libutil_u8                                                  ReservedPad0;                   /*+0x0F74*/
        libutil_u8                                                  ReservedPad1;                   /*+0x0F75*/
        libutil_u8                                                  ReservedPad2;                   /*+0x0F76*/
        libutil_u8                                                  IdealProcessor;                 /*+0x0F77*/
    } CurrentIdealProcessor;
    libutil_u32                                                 GuaranteedStackBytes;               /*+0x0F78*/
    libutil_u32                                                 ReservedForPerf;                    /*+0x0F7C*/
    libutil_u32                                                 ReservedForOle;                     /*+0x0F80*/
    libutil_u32                                                 WaitingOnLoaderLock;                /*+0x0F84*/
    libutil_u32                                                 SavedPriorityState;                 /*+0x0F88*/
    libutil_u32                                                 ReservedForCodeCoverage;            /*+0x0F8C*/
    libutil_u32                                                 ThreadPoolData;                     /*+0x0F90*/
    libutil_u32         /*void** */                             TlsExpansionSlots;                  /*+0x0F94*/
    libutil_u32                                                 MuiGeneration;                      /*+0x0F98*/
    libutil_u32                                                 IsImpersonating;                    /*+0x0F9C*/
    libutil_u32                                                 NlsCache;                           /*+0x0FA0*/
    libutil_u32                                                 pShimData;                          /*+0x0FA4*/
    union
    {
        struct
        {
            libutil_u16                                                 HeapVirtualAffinity;        /*+0x0FA8*/
            libutil_u16                                                 LowFragHeapDataSlot;        /*+0x0FAA*/
        };
        libutil_u32                                                 HeapData;                       /*+0x0FA8*/
    };
    libutil_u32                                                 CurrentTransactionHandle;           /*+0x0FAC*/
    libutil_u32         /*_TEB_ACTIVE_FRAME* */                 ActiveFrame;                        /*+0x0FB0*/
    libutil_u32                                                 FlsData;                            /*+0x0FB4*/
    libutil_u32                                                 PreferredLanguages;                 /*+0x0FB8*/
    libutil_u32                                                 UserPrefLanguages;                  /*+0x0FBC*/
    libutil_u32                                                 MergedPrefLanguages;                /*+0x0FC0*/
    libutil_u32                                                 MuiImpersonation;                   /*+0x0FC4*/
    struct
    {
        libutil_u16                                                 SpareCrossTebBits : 16;         /*+0x0FC8*/
    } CrossTebFlags;
    struct
    {
        libutil_bool                                                SafeThunkCall : 1;              /*+0x0FCA*/
        libutil_bool                                                InDebugPrint : 1;               /*+0x0FCA*/
        libutil_bool                                                HasFiberData : 1;               /*+0x0FCA*/
        libutil_bool                                                SkipThreadAttach : 1;           /*+0x0FCA*/
        libutil_bool                                                WerInShipAssertCode : 1;        /*+0x0FCA*/
        libutil_bool                                                RanProcessInit : 1;             /*+0x0FCA*/
        libutil_bool                                                ClonedThread : 1;               /*+0x0FCA*/
        libutil_bool                                                SuppressDebugMsg : 1;           /*+0x0FCA*/
        libutil_bool                                                DisableUserStackWalk : 1;       /*+0x0FCA*/
        libutil_bool                                                RtlExceptionAttached : 1;       /*+0x0FCA*/
        libutil_bool                                                InitialThread : 1;              /*+0x0FCA*/
        libutil_bool                                                SessionAware : 1;               /*+0x0FCA*/
        libutil_bool                                                LoadOwner : 1;                  /*+0x0FCA*/
        libutil_bool                                                LoaderWorker : 1;               /*+0x0FCA*/
        libutil_bool                                                SkipLoaderInit : 1;             /*+0x0FCA*/
        libutil_bool                                                SkipFileAPIBrokering : 1;       /*+0x0FCA*/
    } SameTebFlags;
    libutil_u32                                                 TxnScopeEnterCallback;              /*+0x0FCC*/
    libutil_u32                                                 TxnScopeExitCallback;               /*+0x0FD0*/
    libutil_u32                                                 TxnScopeContext;                    /*+0x0FD4*/
    libutil_u32                                                 LockCount;                          /*+0x0FD8*/
    libutil_u32                                                 WowTebOffset;                       /*+0x0FDC*/
    libutil_u32                                                 ResourceRetValue;                   /*+0x0FE0*/
    libutil_u32                                                 ReservedForWdf;                     /*+0x0FE4*/
        // Taken from Win11
    libutil_u64                                                 ReservedForCrt;                     /*+0x0FE8*/
    LIBUTIL_NT_GUID                                             EffectiveContainerId;               /*+0x0FF0*/
    libutil_u64                                                 LastSleepCounter;                   /*+0x1000*/
    libutil_u32                                                 SpinCallCount;                      /*+0x1008*/
    libutil_u8                                                  Padding9[4];                        /*+0x100C*/
    libutil_u64                                                 ExtendedFeatureDisableMask;         /*+0x1010*/
} LIBUTIL_NT_TEB32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_GDI_TEB_BATCH64
{
    libutil_u32                                                 Offset : 31;                        /*+0x0000*/
    libutil_u32                                                 HasRenderingCommand : 1;            /*+0x0000*/
    libutil_u8                                                  Padding0[4];                        /*+0x0004*/
    libutil_u64                                                 HDC;                                /*+0x0008*/
    libutil_u32                                                 Buffer[310];                        /*+0x0010*/
} LIBUTIL_NT_GDI_TEB_BATCH64;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_TEB64
{
    LIBUTIL_NT_TIB64                                                TIB;                            /*+0x0000*/
    libutil_u64                                                     EnviromentPointer;              /*+0x0038*/
    struct /*_CLIENT_ID*/
    {
        libutil_u64                                                 UniqueProcess;                  /*+0x0040*/
        libutil_u64                                                 UniqueThread;                   /*+0x0048*/
    } ClientID;
    libutil_u64                                                 ActiveRpcHandle;                    /*+0x0050*/
    libutil_u64                                                 ThreadLocalStoragePointer;          /*+0x0058*/
    libutil_u64         /*_PEB* */                              ProcessEnvironmentBlock;            /*+0x0060*/
    libutil_u32                                                 LastErrorValue;                     /*+0x0068*/
    libutil_u32                                                 CountOfOwnedCriticalSections;       /*+0x006C*/
    libutil_u64                                                 CsrClientThread;                    /*+0x0070*/
    libutil_u64                                                 Win32ThreadInfo;                    /*+0x0078*/
    libutil_u32                                                 User32Reserved[26];                 /*+0x0080*/
    libutil_u32                                                 UserReserved[5];                    /*+0x00E8*/
    libutil_u8                                                  Padding0[4];                        /*+0x00FC*/
    libutil_u64                                                 WOW32Reserved;                      /*+0x0100*/
    libutil_u32                                                 CurrentLocale;                      /*+0x0108*/
    libutil_u32                                                 FpSoftwareStatusRegister;           /*+0x010C*/
    libutil_u64                                                 ReservedForDbgerInstrumentation[16];/*+0x0110*/
    libutil_u64                                                 SystemReserved1[30];                /*+0x0190*/
    libutil_u8                                                  PlaceholderCompatibilityMode;       /*+0x0280*/
    libutil_u8                                                  PlaceholderHydrationAlwaysExplicit; /*+0x0281*/
    libutil_u8                                                  PlaceholderReserved[10];            /*+0x0282*/
    libutil_u32                                                 ProxiedProcessId;                   /*+0x028C*/
    LIBUTIL_NT_ACTIVATION_CONTEXT_STACK64                       _ActivationStack;                   /*+0x0290*/
    libutil_u8                                                  WorkingOnBehalfTicket[8];           /*+0x02B8*/
    libutil_u32                                                 ExceptionCode;                      /*+0x02C0*/
    libutil_u8                                                  Padding1[4];                        /*+0x02C4*/
    libutil_u64         /*_ACTIVATION_CONTEXT_STACK* */         ActivationContextStackPointer;      /*+0x02C8*/
    libutil_u64                                                 InstrumentationCallbackSp;          /*+0x02D0*/
    libutil_u64                                                 InstrumentationCallbackPreviousPc;  /*+0x02D8*/
    libutil_u64                                                 InstrumentationCallbackPreviousSp;  /*+0x02E0*/
    libutil_u32                                                 TxFsContext;                        /*+0x02E8*/
    libutil_u8                                                  Padding2[4];                        /*+0x02EC*/
    LIBUTIL_NT_GDI_TEB_BATCH64                                  GdiTebBatch;                        /*+0x02F0*/
    struct /*_CLIENT_ID*/
    {
        libutil_u64                                                 UniqueProcess;                  /*+0x07D8*/
        libutil_u64                                                 UniqueThread;                   /*+0x07E0*/
    } RealClientId;
    libutil_u64                                                 GdiCachedProcessHandle;             /*+0x07E8*/
    libutil_u32                                                 GdiClientPID;                       /*+0x07F0*/
    libutil_u32                                                 GdiClientTID;                       /*+0x07F4*/
    libutil_u64                                                 GdiThreadLocalInfo;                 /*+0x07F8*/
    libutil_u64                                                 Win32ClientInfo[62];                /*+0x0800*/
    libutil_u64                                                 glDispatchTable[233];               /*+0x09F0*/
    libutil_u64                                                 glReserved1[29];                    /*+0x1138*/
    libutil_u64                                                 glReserved2;                        /*+0x1220*/
    libutil_u64                                                 glSectionInfo;                      /*+0x1228*/
    libutil_u64                                                 glSection;                          /*+0x1230*/
    libutil_u64                                                 glTable;                            /*+0x1238*/
    libutil_u64                                                 glCurrentRC;                        /*+0x1240*/
    libutil_u64                                                 glContext;                          /*+0x1248*/
    libutil_u32                                                 LastStatusValue;                    /*+0x1250*/
    libutil_u8                                                  Padding3[4];                        /*+0x1254*/
    LIBUTIL_NT_UNICODE_STRING64                                 StaticUnicodeString;                /*+0x1258*/
    libutil_wchar                                               StaticUnicodeBuffer[261];           /*+0x1268*/
    libutil_u8                                                  Padding4[6];                        /*+0x1472*/
    libutil_u64                                                 DeallocationStack;                  /*+0x1478*/
    libutil_u64                                                 TlsSlots[64];                       /*+0x1480*/
    LIBUTIL_NT_LIST_ENTRY64                                     TlsLinks;                           /*+0x1680*/
    libutil_u64                                                 Vdm;                                /*+0x1690*/
    libutil_u64                                                 ReservedForNtRpc;                   /*+0x1698*/
    libutil_u64                                                 DbgSsReserved[2];                   /*+0x16A0*/
    libutil_u32                                                 HardErrorMode;                      /*+0x16B0*/
    libutil_u8                                                  Padding5[4];                        /*+0x16B4*/
    libutil_u64                                                 Instrumentation[11];                /*+0x16B8*/
    LIBUTIL_NT_GUID                                             ActivityId;                         /*+0x1710*/
    libutil_u64                                                 SubProcessTag;                      /*+0x1720*/
    libutil_u64                                                 PerflibData;                        /*+0x1728*/
    libutil_u64                                                 EtwTraceData;                       /*+0x1730*/
    libutil_u64                                                 WinSockData;                        /*+0x1738*/
    libutil_u32                                                 GdiBatchCount;                      /*+0x1740*/
    struct
    {
        libutil_u8                                                  ReservedPad0;                   /*+0x1744*/
        libutil_u8                                                  ReservedPad1;                   /*+0x1745*/
        libutil_u8                                                  ReservedPad2;                   /*+0x1746*/
        libutil_u8                                                  IdealProcessor;                 /*+0x1747*/
    } CurrentIdealProcessor;
    libutil_u32                                                 GuaranteedStackBytes;               /*+0x1748*/
    libutil_u8                                                  Padding6[4];                        /*+0x174C*/
    libutil_u64                                                 ReservedForPerf;                    /*+0x1750*/
    libutil_u64                                                 ReservedForOle;                     /*+0x1758*/
    libutil_u32                                                 WaitingOnLoaderLock;                /*+0x1760*/
    libutil_u8                                                  Padding7[4];                        /*+0x1764*/
    libutil_u64                                                 SavedPriorityState;                 /*+0x1768*/
    libutil_u64                                                 ReservedForCodeCoverage;            /*+0x1770*/
    libutil_u64                                                 ThreadPoolData;                     /*+0x1778*/
    libutil_u64         /*void** */                             TlsExpansionSlots;                  /*+0x1780*/
    union
    {
        struct
        {
            libutil_u64                                                 DeallocationBStore;         /*+0x1788*/
            libutil_u64                                                 BStoreLimit;                /*+0x1790*/
        };
        struct
        {
            libutil_u64                                                 ChpeV2CpuAreaInfo;          /*+0x1788*/
            libutil_u64                                                 Unused;                     /*+0x1790*/
        };
    };
    libutil_u32                                                 MuiGeneration;                      /*+0x1798*/
    libutil_u32                                                 IsImpersonating;                    /*+0x179C*/
    libutil_u64                                                 NlsCache;                           /*+0x17A0*/
    libutil_u64                                                 pShimData;                          /*+0x17A8*/
    union
    {
        struct
        {
            libutil_u16                                                 HeapVirtualAffinity;        /*+0x17B0*/
            libutil_u16                                                 LowFragHeapDataSlot;        /*+0x17B2*/
        };
        libutil_u32                                                 HeapData;                       /*+0x17B0*/
    };
    libutil_u8                                                  Padding8[4];                        /*+0x17B4*/
    libutil_u64                                                 CurrentTransactionHandle;           /*+0x17B8*/
    libutil_u64         /*_TEB_ACTIVE_FRAME* */                 ActiveFrame;                        /*+0x17C0*/
    libutil_u64                                                 FlsData;                            /*+0x17C8*/
    libutil_u64                                                 PreferredLanguages;                 /*+0x17D0*/
    libutil_u64                                                 UserPrefLanguages;                  /*+0x17D8*/
    libutil_u64                                                 MergedPrefLanguages;                /*+0x17E0*/
    libutil_u32                                                 MuiImpersonation;                   /*+0x17E8*/
    struct
    {
        libutil_u16                                                 SpareCrossTebBits : 16;         /*+0x17EC*/
    } CrossTebFlags;
    struct
    {
        libutil_bool                                                SafeThunkCall : 1;              /*+0x17EE*/
        libutil_bool                                                InDebugPrint : 1;               /*+0x17EE*/
        libutil_bool                                                HasFiberData : 1;               /*+0x17EE*/
        libutil_bool                                                SkipThreadAttach : 1;           /*+0x17EE*/
        libutil_bool                                                WerInShipAssertCode : 1;        /*+0x17EE*/
        libutil_bool                                                RanProcessInit : 1;             /*+0x17EE*/
        libutil_bool                                                ClonedThread : 1;               /*+0x17EE*/
        libutil_bool                                                SuppressDebugMsg : 1;           /*+0x17EE*/
        libutil_bool                                                DisableUserStackWalk : 1;       /*+0x17EE*/
        libutil_bool                                                RtlExceptionAttached : 1;       /*+0x17EE*/
        libutil_bool                                                InitialThread : 1;              /*+0x17EE*/
        libutil_bool                                                SessionAware : 1;               /*+0x17EE*/
        libutil_bool                                                LoadOwner : 1;                  /*+0x17EE*/
        libutil_bool                                                LoaderWorker : 1;               /*+0x17EE*/
        libutil_bool                                                SkipLoaderInit : 1;             /*+0x17EE*/
        libutil_bool                                                SkipFileAPIBrokering : 1;       /*+0x17EE*/
    } SameTebFlags;
    libutil_u64                                                 TxnScopeEnterCallback;              /*+0x17F0*/
    libutil_u64                                                 TxnScopeExitCallback;               /*+0x17F8*/
    libutil_u64                                                 TxnScopeContext;                    /*+0x1800*/
    libutil_u32                                                 LockCount;                          /*+0x1808*/
    libutil_i32                                                 WowTebOffset;                       /*+0x180C*/
    libutil_u64                                                 ResourceRetValue;                   /*+0x1810*/
    libutil_u64                                                 ReservedForWdf;                     /*+0x1818*/
    // Taken from Win11
    libutil_u64                                                 ReservedForCrt;                     /*+0x1820*/
    LIBUTIL_NT_GUID                                             EffectiveContainerId;               /*+0x1828*/
    libutil_u64                                                 LastSleepCounter;                   /*+0x1838*/
    libutil_u32                                                 SpinCallCount;                      /*+0x1840*/
    libutil_u8                                                  Padding9[4];                        /*+0x1844*/
    libutil_u64                                                 ExtendedFeatureDisableMask;         /*+0x1848*/
} LIBUTIL_NT_TEB64;

#ifdef LIBUTIL_MSVC
#pragma pack(pop)
#endif

#ifdef LIBUTIL_WINDOWS
    #ifdef LIBUTIL_X86
        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_TEB32    *LibUtil_Nt_GetTeb32();

        LIBUTIL_API LIBUTIL_IMPORT
        libutil_u64         LibUtil_Nt_GetTeb64();

        LIBUTIL_API LIBUTIL_IMPORT
        libutil_bool        LibUtil_Nt_ReadTeb64(LIBUTIL_NT_TEB64 *TEB);
    #elif defined(LIBUTIL_64_BITS)
        LIBUTIL_API LIBUTIL_IMPORT
        LIBUTIL_NT_TEB64    *LibUtil_Nt_GetTeb64();
    #endif
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_NT_GDI_TEB_BATCH32  lu_nt_gditebbatch32;
    typedef LIBUTIL_NT_TEB32            lu_nt_teb32;

    typedef LIBUTIL_NT_GDI_TEB_BATCH64  lu_nt_gditebbatch64;
    typedef LIBUTIL_NT_TEB64            lu_nt_teb64;

    #ifdef LIBUTIL_WINDOWS
        #ifdef LIBUTIL_32_BITS
            #define lu_nt_getteb                LibUtil_Nt_GetTeb32
            #define lu_nt_getteb64              LibUtil_Nt_GetTeb64
            #define lu_nt_readteb64             LibUtil_Nt_ReadTeb64

            #define LibUtil_Nt_GetTeb           LibUtil_Nt_GetTeb32
        #else
            #define lu_nt_getteb                LibUtil_Nt_GetTeb64
            #define lu_nt_getteb64              LibUtil_Nt_GetTeb64

            #define LibUtil_Nt_GetTeb           LibUtil_Nt_GetTeb64
        #endif
    #endif
#endif

#ifdef LIBUTIL_32_BITS
    typedef lu_nt_gditebbatch32         lu_nt_gditebbatch;
    typedef lu_nt_teb32                 lu_nt_teb;
#else
    typedef lu_nt_gditebbatch64         lu_nt_gditebbatch;
    typedef lu_nt_teb64                 lu_nt_teb;
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#ifdef __cplusplus
    static_assert(sizeof(LIBUTIL_NT_TEB32) == 0x1018, "sizeof(LIBUTIL_NT_TEB32) == 0x1018");
    static_assert(sizeof(LIBUTIL_NT_TEB64) == 0x1850, "sizeof(LIBUTIL_NT_TEB64) == 0x1850");
#endif

#endif
