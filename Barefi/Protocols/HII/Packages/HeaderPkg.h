// Defines the HII Header Package

#ifndef __EFI_HII_PACKAGE_HEADER__
#define __EFI_HII_PACKAGE_HEADER__

// DEPENDENCIES

#ifndef __EFI_DATA_TYPES__
#include "../../../System/DataTypes.h"
#endif //__EFI_DATA_TYPES__

// RELATED DEFINITIONS

#define EFI_HII_PACKAGE_TYPE_ALL 0x00
#define EFI_HII_PACKAGE_TYPE_GUID 0x01
#define EFI_HII_PACKAGE_FORMS 0x02
#define EFI_HII_PACKAGE_STRINGS 0x04
#define EFI_HII_PACKAGE_FONTS 0x05
#define EFI_HII_PACKAGE_IMAGES 0x06
#define EFI_HII_PACKAGE_SIMPLE_FONTS 0x07
#define EFI_HII_PACKAGE_DEVICE_PATH 0x08
#define EFI_HII_PACKAGE_KEYBOARD_LAYOUT 0x09
#define EFI_HII_PACKAGE_ANIMATIONS 0x0A
#define EFI_HII_PACKAGE_END 0xDF
#define EFI_HII_PACKAGE_TYPE_SYSTEM_BEGIN 0xE0
#define EFI_HII_PACKAGE_TYPE_SYSTEM_END 0xFF

// PROTOTYPES

typedef struct {
    UINT32 Length:24;
    UINT32 Type:8;
    UINT8 Data[];
} EFI_HII_PACKAGE_HEADER;

#endif //__EFI_HII_PACKAGE_HEADER__
