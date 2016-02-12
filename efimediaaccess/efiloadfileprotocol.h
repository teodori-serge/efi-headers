#ifndef EFI_LOAD_FILE_PROTOCOL_H
#define EFI_LOAD_FILE_PROTOCOL_H

#define EFI_LOAD_FILE_PROTOCOL_GUID {0x56EC3091,0x954C,0x11d2,{0x8e,0x3f,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef EFI_STATUS (EFIAPI *EFI_LOAD_FILE)(
	IN EFI_LOAD_FILE_PROTOCOL *This,
	IN EFI_DEVICE_PATH_PROTOCOL *FilePath,
	IN BOOLEAN BootPolicy,
	IN OUT UINTN *BufferSize,
	IN VOID *Buffer OPTIONAL
);

typedef struct _EFI_LOAD_FILE_PROTOCOL{
	EFI_LOAD_FILE LoadFile;
} EFI_LOAD_FILE_PROTOCOL;

#endif