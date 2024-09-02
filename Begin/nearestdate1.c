/* Напишите программу, которая находит в массиве элемент, самый близкий по величине к данному числу.
Формат ввода
В первой строке задается одно натуральное число 𝑁
N, не превосходящее 1000 — размер массива. Во второй строке содержатся 𝑁
N чисел — элементы массива, целые числа, не превосходящие по модулю 1000. В третьей строке вводится одно целое число 𝑥
x, не превосходящее по модулю 1000.
Формат вывода
Вывести значение элемента массива, ближайшее к 𝑥
x. Если таких чисел несколько, выведите любое из них. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000u
#define MAX 1000u
#define MIN 0u

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int x,N; x = N = 0;
    unsigned i,j; i = j = 0;
    int tmp, diff; tmp = diff = 0;
    //ввод N, проверка, выделение памяти под массив.
    scanf("%d", &N);
    if ((N > MIN) && (N < MAX)){
    } else {
        return 1;
    }
    int *array = (int *)malloc(N * sizeof(int));
    //заполнение массива
    for (; i < N; i++) {
        scanf("%d", &array[i]);     
    }
    //сортировка массива
    bubbleSort(array,N);

    //ввод x 
    scanf("%d", &x);
    if ((x > -1000) && (x < MAX)){
    } else {
        return 1;
    }
    //
    diff = array[0] - abs(x);
    //
    // проход по числам массива
    for (i = 0; i < N; i++) {
        tmp = array[i] - abs(x);
        if (abs(tmp) <= abs(diff)) 
        diff = tmp;
        if(tmp == 0) break;
        /*  printf("%d ", tmp);
         printf("%d ", diff);      */  
    } 
    printf("\n%d", diff + abs(x));
    
    if (array == NULL) {
        return 1;
    }else {
    free(array);
    }
    return 0;
}