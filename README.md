#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Проверяем количество аргументов
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <octal_mode> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Конвертируем строку с режимом в число
    char *endptr;
    errno = 0; // Сбрасываем значение errno перед вызовом strtoul
    unsigned long mode = strtoul(argv[1], &endptr, 8); // Основание 8 для восьмеричного числа

    // Проверяем наличие ошибок при конвертации
    if (errno != 0 || *endptr != '\0' || mode > 0777) {
        fprintf(stderr, "Error: invalid mode '%s'. Please provide a valid octal number (0000-0777).\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Применяем режим доступа к файлу с помощью системного вызова chmod
    if (chmod(argv[2], (mode_t)mode) == -1) {
        perror("chmod");
        return EXIT_FAILURE;
    }

    printf("Mode changed successfully for file %s to %04lo\n", argv[2], mode);
    return EXIT_SUCCESS;
}
