#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Преобразование строки в unsigned long
    char *endptr;
    unsigned long mode = strtoul(argv[1], &endptr, 8);

    // Проверка ошибок преобразования
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Invalid mode: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Изменение прав доступа к файлу
    if (chmod(argv[2], (mode_t)mode) == -1) {
        fprintf(stderr, "Error changing mode of %s: %s\n", argv[2], strerror(errno));
        return EXIT_FAILURE;
    }

    printf("Successfully changed mode of %s to %o\n", argv[2], mode);
    return EXIT_SUCCESS;
}
