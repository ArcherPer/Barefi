#include "Uefi.h"

EFI_STATUS efi_main() {
    EFI_STATUS Status = gST->ConOut->OutputString(gST->ConOut,u"This is an example application\r\n");
    return Status;
}
