// Defines the UEFI Device Path Protocol

#ifndef __EFI_DEVICE_PATH_PROTOCOL__
#define __EFI_DEVICE_PATH_PROTOCOL__

typedef struct _EFI_DEVICE_PATH_PROTOCOL EFI_DEVICE_PATH_PROTOCOL;
#define EFI_DEVICE_PATH_PROTOCOL_GUID {0x09576e91,0x6d3f,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

// DEPENDENCIES

#ifndef __EFI_DATA_TYPES__
#include "../../System/DataTypes.h"
#endif //__EFI_DATA_TYPES__

// RELATED DEFINITIONS

#define EFI_DEVICE_PATH_TYPE_HARDWARE 0x01
#define EFI_DEVICE_PATH_TYPE_ACPI 0x02
#define EFI_DEVICE_PATH_TYPE_MESSAGING 0x03
#define EFI_DEVICE_PATH_TYPE_MEDIA 0x04
#define EFI_DEVICE_PATH_TYPE_BIOS 0x05
#define EFI_DEVICE_PATH_TYPE_END_OF_HARDWARE 0x7F

// PROTOTYPES

struct _EFI_DEVICE_PATH_PROTOCOL {
    UINT8 Type;
    UINT8 SubType;
    UINT8 Length[2];
};

#endif //__EFI_DEVICE_PATH_PROTOCOL__