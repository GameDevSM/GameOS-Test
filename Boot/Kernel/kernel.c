// kernel/kernel.c
#include "kernel.h"
#include "../drivers/screen.c"

void main() {
    clear_screen();
    print("Welcome to GameOS!\n");
    print("Hello World from the kernel!\n");
    while (1);
}
