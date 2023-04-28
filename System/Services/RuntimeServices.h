// Defines UEFI Runtime Services

#ifndef __EFI_RUNTIME_SERVICES__
#define __EFI_RUNTIME_SERVICES__

typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;
#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

// DEPENDENCIES

#ifndef __EFI_DATA_TYPES__
#include "../DataTypes.h"
#endif //__EFI_DATA_TYPES__

#ifndef __EFI_BOOT_SERVICES__
#include "BootServices.h"
#endif //__EFI_BOOT_SERVICES__

// VARIABLE

#define EFI_VARIABLE_NON_VOLATILE 0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS 0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD 0x00000008
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS 0x00000010
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 0x00000020
#define EFI_VARIABLE_APPEND_WRITE 0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS 0x00000080

typedef EFI_STATUS (EFIAPI *EFI_GET_VARIABLE) (
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    OUT UINT32 *Attributes OPTIONAL,
    IN OUT UINTN *DataSize,
    OUT VOID *Data OPTIONAL
);

typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_VARIABLE_NAME) (
    IN OUT UINTN *VariableNameSize,
    IN OUT CHAR16 *VariableName,
    IN OUT EFI_GUID *VendorGuid
);

typedef EFI_STATUS (EFIAPI *EFI_SET_VARIABLE) (
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    IN UINT32 Attributes,
    IN UINTN DataSize,
    IN VOID *Data
);

typedef EFI_STATUS (EFIAPI *EFI_QUERY_VARIABLE_INFO) (
    IN UINT32 Attributes,
    OUT UINT64 *MaximumVariableStorageSize,
    OUT UINT64 *RemainingVariableStorageSize,
    OUT UINT64 *MaximumVariableSize
);

// TIME

#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

typedef struct {
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 Pad2;
} EFI_TIME;

typedef struct {
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef EFI_STATUS (EFIAPI *EFI_GET_TIME) (
    OUT EFI_TIME *Time,
    OUT EFI_TIME_CAPABILITIES *Capabilities OPTIONAL
);

typedef EFI_STATUS (EFIAPI *EFI_SET_TIME) (
    IN EFI_TIME *Time
);

typedef EFI_STATUS (EFIAPI *EFI_GET_WAKEUP_TIME) (
    OUT BOOLEAN *Enabled,
    OUT BOOLEAN *Pending,
    OUT EFI_TIME *Time
);

typedef EFI_STATUS (EFIAPI *EFI_SET_WAKEUP_TIME) (
    IN BOOLEAN Enable,
    IN EFI_TIME *Time OPTIONAL
);

// VIRTUAL MEMORY

#define EFI_OPTIONAL_PTR 0x00000001

typedef EFI_STATUS (EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP) (
    IN UINTN MemoryMapSize,
    IN UINTN DescriptorSize,
    IN UINT32 DescriptorVersion,
    IN EFI_MEMORY_DESCRIPTOR *VirtualMap
);

typedef EFI_STATUS (EFIAPI *EFI_CONVERT_POINTER) (
    IN UINTN DebugDisposition,
    IN VOID **Address
);

// MISCELLANEOUS

typedef enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef VOID (EFIAPI *EFI_RESET_SYSTEM) (
    IN EFI_RESET_TYPE ResetType,
    IN EFI_STATUS ResetStatus,
    IN UINTN DataSize,
    IN VOID *ResetData OPTIONAL
);

typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT) (
    OUT UINT32 *HighCount
);

// CAPSULE

typedef struct {
    UINT64 Length;
    union {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    }Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct {
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

typedef struct {
    UINT32 CapsuleArrayNumber;
    VOID* CapsulePtr[1];
} EFI_CAPSULE_TABLE;

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

typedef EFI_STATUS (EFIAPI *EFI_UPDATE_CAPSULE) (
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL
);

typedef EFI_STATUS (EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES) (
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    OUT UINT64 *MaximumCapsuleSize,
    OUT EFI_RESET_TYPE *ResetType
);

// RUNTIME SERVICES

struct _EFI_RUNTIME_SERVICES {
    EFI_TABLE_HEADER Hdr;
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;
    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;
    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
};

#endif //__EFI_RUNTIME_SERVICES__