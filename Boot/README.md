# GameOS

Un mic sistem de operare scris de la zero pentru învățare.

## Structură
- `boot/boot.asm` – bootloader simplu
- `kernel/kernel.c` – codul kernel-ului
- `drivers/screen.c` – afișare text pe ecran
- `Makefile` – script de build

## Build & Run
Pe Linux sau Termux:
```bash
sudo apt install nasm gcc make qemu-system-x86
make
qemu-system-x86_64 -drive format=raw,file=os-image.bin
