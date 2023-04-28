/*
Includes all required Headers for UEFI development and defines an entry point
that allocates the Image Handle and System Table of the image to global variables.

If a user wishes to use their own custom entry point System/SystemTable.h can be included instead of this file
*/

#ifndef __EFI_LIB__
#define __EFI_LIB__

// DEPENDENCIES

#ifndef __EFI_SYSTEM_TABLE__
#include "System/SystemTable.h"
#endif //__EFI_SYSTEM_TABLE__

// ENTRY POINT

EFI_STATUS efi_main(); // Forward declaration of user's entry point

EFI_HANDLE gIH;
EFI_SYSTEM_TABLE *gST;
#define gBS gST->BootServices
#define gRT gST->RuntimeServices

/*
This is the main entry point for Barefi. It updates the global variables gIH and gST with the image's System Table pointer and Image Handle.
Afterwards it calls the user's entry point function efi_main(). This function should not be used for any circumstance other than a image's entry point.
*/
EFI_STATUS efi_entry_point(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    gIH = ImageHandle;
    gST = SystemTable;
    return efi_main();
}

#endif //__EFI_LIB__