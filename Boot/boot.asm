; boot/boot.asm
BITS 16
ORG 0x7c00

; setăm modul video text
mov ah, 0x0e
mov al, 'H'
int 0x10
mov al, 'i'
int 0x10

; încărcăm kernelul (simplificat)
mov bx, 0x1000
mov es, bx
mov bx, 0x0000
mov dl, [BOOT_DRIVE]
mov ah, 0x02
mov al, 1
mov ch, 0
mov cl, 2
mov dh, 0
int 0x13

jmp 0x1000:0000

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xAA55
