// Defines the HII Package List Header

#ifndef __EFI_HII_PACKAGE_LIST_HEADER__
#define __EFI_HII_PACKAGE_LIST_HEADER__

// DEPENDENCIES

#ifndef __EFI_DATA_TYPES__
#include "HeaderPkg.h"
#endif //__EFI_DATA_TYPES__

// PROTOTYPES

typedef struct {
    EFI_GUID PackageListGuid;
    UINT32 PackageLength;
} EFI_HII_PACKAGE_LIST_HEADER;

#endif //__EFI_HII_PACKAGE_LIST_HEADER__