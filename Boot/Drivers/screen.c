// drivers/screen.c
#define VIDEO_MEMORY 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f

int cursor_row = 0;
int cursor_col = 0;

void print_char(char c, int row, int col, char attr) {
    unsigned char *vidmem = (unsigned char*) VIDEO_MEMORY;
    int offset = (row * MAX_COLS + col) * 2;
    vidmem[offset] = c;
    vidmem[offset + 1] = attr;
}

void print(char *msg) {
    while (*msg) {
        print_char(*msg, cursor_row, cursor_col, WHITE_ON_BLACK);
        cursor_col++;
        if (cursor_col >= MAX_COLS) {
            cursor_col = 0;
            cursor_row++;
        }
        msg++;
    }
}

void clear_screen() {
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            print_char(' ', row, col, WHITE_ON_BLACK);
        }
    }
    cursor_row = 0;
    cursor_col = 0;
}
