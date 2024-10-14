#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Проверяем количество аргументов
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <octal mode> <file>\n", argv[0]);
        return 1;
    }

    // Преобразуем строку с режимом в целое число
    char *endptr;
    mode_t mode = strtoul(argv[1], &endptr, 8);  // Строку преобразуем в число в 8-ричной системе

    // Проверяем корректность ввода
    if (*endptr != '\0') {
        fprintf(stderr, "Invalid mode: %s\n", argv[1]);
        return 1;
    }

    // Проверяем, что переданное значение находится в корректном диапазоне для прав доступа
    if (mode > 07777) {
        fprintf(stderr, "Mode out of range: %s\n", argv[1]);
        return 1;
    }

    // Пытаемся изменить права доступа к файлу
    if (chmod(argv[2], mode) != 0) {
        perror("chmod");
        return 1;
    }

    printf("Mode changed successfully for file: %s\n", argv[2]);
    return 0;
}

