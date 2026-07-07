//this library created by me and used by me
#include <stdio.h>
#include <string.h>
#include "myc.h"

int get_name_stdin(char* name, size_t buffer_size) {
    if (!name || buffer_size == 0) return 0;

    if (fgets(name, buffer_size, stdin)) {
        // Check if we have a newline
        char* newline = strchr(name, '\n');

        if (newline) {
            *newline = '\0';  // Remove newline
        }
        else {
            // No newline found → input was truncated
            // Clear stdin completely
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        return 1;
    }

    name[0] = '\0';
    return 0;
}
void empty_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void clear_screen(void) {
    printf("\033[2J\033[H");
    fflush(stdout);
}