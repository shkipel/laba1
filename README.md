#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <permissions> <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strlen(argv[1]) > 5) {
        fprintf(stderr, "Error: Invalid permission string: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *endptr;
    long mode = strtol(argv[1], &endptr, 8);

    if (*endptr != '\0' || mode < 0 || mode > 07777) {
        fprintf(stderr, "Error: Incorrect permission format: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (chmod(argv[2], (mode_t)mode) == -1) {
        perror("Failed to update file permissions");
        return EXIT_FAILURE;
    }

    printf("File permissions for '%s' successfully set to %04lo\n", argv[2], mode);
    return EXIT_SUCCESS;
}
