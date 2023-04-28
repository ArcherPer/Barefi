// Defines the Table header used by the System Table and Services

#ifndef __EFI_TABLE_HEADER__
#define __EFI_TABLE_HEADER__

// DEPENDENCIES

#ifndef __EFI_DATA_TYPES__
#include "../DataTypes.h"
#endif //__EFI_DATA_TYPES__

// PROTOTYPES

typedef struct _EFI_TABLE_HEADER {
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;

#endif //__EFI_TABLE_HEADER__