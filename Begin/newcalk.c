#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   
    int tmp[7];
    int count = 0;
    int size = 3; // Изначальный размер массива
    int *array = (int *)malloc(size * sizeof(int));

    // Проверяем, успешно ли выделена память
    if (!array) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        return 1;
    }

    // Заполнение массива начальными значениями
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]); // Пример заполнения массива
    }

    int N;
    scanf("%d", &N);

    // Создаем массив для хранения цифр числа N
    int digits[4];
    int j = 0;
    do {
        digits[j] = N % 10; // Получаем последнюю цифру числа N
        N /= 10;
        j++;           // Удаляем последнюю цифру из числа N
    } while ((N != 0) && (j < 5));
    for (int i = 0; i < 7; i++)
    {
        tmp[i] = array[1];
    }
    
    for  (int i = 0; i < j; i++) {   
        if ((digits[i] == array[0]) || (digits[i] == array[1]) || (digits[i] == array[2]) || (digits[i] == tmp[i]) || (digits[i] == tmp[i + 1])) {}
        else {
            count++;
            tmp[i] = digits[i];
        }        
    }
    printf("%d\n", count);

    return 0;
}