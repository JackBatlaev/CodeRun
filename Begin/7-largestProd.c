#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {

    char line[100000]; // Буфер для хранения строки
    char* read;

    // Считывание строки
    read = fgets(line, sizeof(line), stdin);
    if (read == NULL) {
        printf("Ошибка при чтении строки.\n");
        exit(EXIT_FAILURE);
    }

    // Удаление символа новой строки, если он присутствует
    if (line[strcspn(line, "\n")] == '\n') {
        line[strcspn(line, "\n")] = '\0';
    }

    // Разделение строки на числа и сохранение их в массив
    char *token = strtok(line, " ");
    int numbers[100000]; // Предполагаем, что в строке не более 100000 чисел
    int count = 0;
    while (token != NULL) {
        char *endeptr;
        long number = strtol(token, &endeptr, 10);
        if(*endeptr == '\0') {
        numbers[count++] = number;
        }
        token = strtok(NULL, " ");
    }

    bubbleSort(numbers, count);

    for (size_t k = 0 ; k < 3; k++) {
        printf("%d ", numbers[k]);
    }
    return 0;
}