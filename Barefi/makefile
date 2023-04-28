# This is a very simple example of how to compile c source code to UEFI application (only tested on windows systems)

# Example use: make eficompile file=PATH_TO_FILE
# Make sure to exclude the file extension

CC = clang
CFLAGS = -target x86_64-unknown-windows -ffreestanding -mno-red-zone -fno-stack-protector -fno-stack-check -fshort-wchar

LL = lld
LFLAGS = -flavor link -subsystem:efi_application -entry:efi_entry_point

eficompile: 
	$(CC) $(CFLAGS) -c -o $(file).o $(file).c
	$(LL) $(LFLAGS) -out:$(file).efi $(file).o
	erase $(file).o