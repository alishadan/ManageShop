//this library created by me and used by me
#include <stdio.h>
#include <string.h>
#include "myc.h"
#include <errno.h>


#ifdef _WIN32
    #include <direct.h>
    #include <sys/stat.h>
    #define mkdir(path) _mkdir(path)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif



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


int create_folder(const char* folder,int* status) {
    struct stat st;
    
    // Check if folder already exists
    if (stat(folder, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            // It's a directory, so it exists
            return 0;  // Success
        }
        else {
            // A file exists with the same name
            //printf("A file named '%s' already exists\n", folder);
            *status=1;
            return -1;
        }
    }
    
    // Create the directory
    #ifdef _WIN32
        if (_mkdir(folder) == -1) {
    #else
        if (mkdir(folder, 0755) == -1) {
    #endif
        //printf("Failed to create folder '%s': %s\n", folder, strerror(errno));
        *status=2;
        return -1;
    }
    
    return 0;  // Success
}