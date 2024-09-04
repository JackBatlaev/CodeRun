/* 7. Наибольшее произведение трех чисел
В данном массиве из n целых чисел найдите три числа, произведение которых максимально.
Формат ввода 
В единственной строке расположено 𝑛 (3≤𝑛≤10^5) чисел 𝑎𝑖 (−10^6≤𝑎𝑖≤10^6) - элементы массива.
Формат вывода
Выведите три элемента массива, дающих наибольшее произведение, в любом порядке.


 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int arr[], int size) {
    int i,j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


int main() {

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Считывание строки
    read = getline(&line, &len, stdin);
    if (read == -1) {
        printf("Ошибка при чтении строки.\n");
        exit(EXIT_FAILURE);
    }
    if (line[read - 1] == '\n') {
        line[read - 1] = '\0';
    }
    //
    char *token = strtok(line, " ");
    int numbers[100000];
    int count = 0;
    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }


    bubbleSort(numbers,count);

    for (size_t k = count - 1; count - 4 < k; k--){
        printf("%d ", numbers[k]);
    }
    printf("\n");
    
    free(line);

}