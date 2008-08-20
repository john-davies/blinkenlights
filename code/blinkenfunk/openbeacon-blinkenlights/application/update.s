.global bootloader
.global bootloader_orig
.global bootloader_orig_end

.section .bootloader,"ax"
         .code 32
         .align 0

bootloader:
	 .incbin "application/update/AT91SAM7S64-bootloader.bin"

.section .rodata
         .data 32
         .align 0

bootloader_orig:
	 .incbin "application/update/AT91SAM7S64-bootloader-orig.bin"
bootloader_orig_end:
