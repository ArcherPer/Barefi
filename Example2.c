#include "System/SystemTable.h" // Does not use the custom Barefi entry point

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    EFI_STATUS Status = SystemTable->ConOut->OutputString(SystemTable->ConOut,u"This is an example application\r\n");
    return Status;
}