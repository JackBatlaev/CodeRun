#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для проверки монотонного возрастания массива
int isMonotonicallyIncreasing(int arr[], int n) {
    int i;

    // Проверяем, является ли массив монотонно возрастающим
    for (i = 1; i < n; ++i) {
        if (arr[i] <= arr[i - 1]) {
            return 0; // Если элемент меньше или равен предыдущему, массив не монотонно возрастающий
        }
    }

    return 1; // Если цикл пройден без возврата 0, массив монотонно возрастает
}

int main()
{   
    int arr[20];
    int i = 0;
    
    

    return 0;
}