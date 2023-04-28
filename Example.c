#include "Uefi.h"

EFI_STATUS efi_main() {
    EFI_STATUS Status = gST->ConOut->OutputString(gST->ConOut,u"This is an example application\r\n");
    return Status;
}

// clang -target x86_64-unknown-windows -ffreestanding -mno-red-zone -fno-stack-protector -fshort-wchar -c -o object.o Example.c