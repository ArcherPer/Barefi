// Defines common UEFI data types

#ifndef __EFI_DATA_TYPES__
#define __EFI_DATA_TYPES__

// DEPENDENCIES

#include <stdint.h>

// PROTOTYPES

typedef int8_t BOOLEAN;
#define TRUE 1
#define FALSE 0

typedef intmax_t INTN;
typedef uintmax_t UINTN;

typedef int8_t INT8;
typedef uint8_t UINT8;

typedef int16_t INT16;
typedef uint16_t UINT16;

typedef int32_t INT32;
typedef uint32_t UINT32;

typedef int64_t INT64;
typedef uint64_t UINT64;

typedef int64_t INT128[2];
typedef uint64_t UINT128[2];

typedef uint8_t CHAR8;
typedef uint16_t CHAR16;

typedef void VOID;

#ifndef NULL
#define NULL ((VOID*)0)
#endif //NULL

typedef UINTN EFI_STATUS;
typedef VOID* EFI_HANDLE;
typedef VOID* EFI_EVENT;

typedef struct EFI_GUID {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_GUID;

#define IN
#define OUT
#define OPTIONAL
#define CONST
#define EFIAPI

#endif //__EFI_DATA_TYPES__