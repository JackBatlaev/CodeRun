#include <stdio.h>
#include <string.h>

int main() {
    char input[5];
    int x, y, z, N, i, buttonsToAdd = 0;

    // Считываем строку с тремя числами
    fgets(input, 5, stdin);
    sscanf(input, "%c%c%c", &x, &y, &z);

    // Проверяем, можно ли ввести число N с помощью имеющихся кнопок
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') continue; // Пропускаем пробелы
        if (input[i] >= '0' && input[i] <= '9') {
            buttonsToAdd = N % 10; // Если последняя цифра числа N присутствует среди кнопок, добавляем ее
            break;
        }
    }

    // Если число можно ввести, выводим 0
    if (buttonsToAdd == 0) {
        printf("%d\n", 0);
        return 0;
    }

    // Вычисляем минимальное количество кнопок, которые нужно добавить
    while (N > 0) {
        if ((N % 10) == x || (N % 10) == y || (N % 10) == z) {
            N /= 10;
        } else {
            buttonsToAdd++;
            N /= 10;
        }
    }

    printf("%d\n", buttonsToAdd);
    return 0;
}