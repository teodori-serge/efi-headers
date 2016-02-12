#ifndef EFI_DISK_IO2_PROTOCOL_H
#define EFI_DISK_IO2_PROTOCOL_H

#define EFI_DISK_IO2_PROTOCOL_GUID {0x151c8eae,0x7f2c,0x472c,{0x9e,0x54,0x98,0x28,0x19,0x4f,0x6a,0x88}}

#define EFI_DISK_IO2_PROTOCOL_REVISION 0x00020000

typedef struct{
	EFI_EVENT Event;
	EFI_STATUS TransactionStatus;
} EFI_DISK_IO2_TOKEN;

typedef EFI_STATUS (EFIAPI *EFI_DISK_CANCEL_EX)(
	IN EFI_DISK_IO2_PROTOCOL *This
);

typedef EFI_STATUS (EFIAPI *EFI_DISK_READ_EX)(
	IN EFI_DISK_IO2_PROTOCOL *This,
	IN UINT32 MediaId,
	IN UINT64 Offset,
	IN OUT EFI_DISK_IO2_TOKEN *Token,
	IN UINTN BufferSize,
	OUT VOID *Buffer
);

typedef EFI_STATUS (EFIAPI *EFI_DISK_WRITE_EX)(
	IN EFI_DISK_IO2_PROTOCOL *This,
	IN UINT32 MediaId,
	IN UINT64 Offset,
	IN OUT EFI_DISK_IO2_TOKEN *Token,
	IN UINTN BufferSize,
	IN VOID *Buffer
);

typedef EFI_STATUS (EFIAPI *EFI_DISK_FLUSH_EX)(
	IN EFI_DISK_IO2_PROTOCOL *This,
	IN OUT EFI_DISK_IO2_TOKEN *Token
);

typedef struct _EFI_DISK_IO2_PROTOCOL{
	UINT64 Revision;
	EFI_DISK_CANCEL_EX Cancel;
	EFI_DISK_READ_EX ReadDiskEx;
	EFI_DISK_WRITE_EX WriteDiskEx;
	EFI_DISK_FLUSH_EX FlushDiskEx;
} EFI_DISK_IO2_PROTOCOL;

#endif