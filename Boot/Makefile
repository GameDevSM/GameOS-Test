# Makefile
ASM = nasm
CC = i386-elf-gcc
LD = i386-elf-ld

all: boot.bin kernel.bin os-image.bin

boot.bin: boot/boot.asm
	$(ASM) -f bin boot/boot.asm -o boot.bin

kernel.o: kernel/kernel.c
	$(CC) -ffreestanding -c kernel/kernel.c -o kernel.o

kernel.bin: kernel.o
	$(LD) -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary

os-image.bin: boot.bin kernel.bin
	cat boot.bin kernel.bin > os-image.bin

clean:
	rm -f *.bin *.o
