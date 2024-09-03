
#include<stdio.h>
#include<stdlib.h>

int main() {
    size_t  N = 0;
    scanf("%ld", &N);

    int *array = (int*)malloc(N * sizeof(int));

    for (size_t i = 0; i <= N; i++) {
        array[i] = i + 1;
    }
    

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            printf("%d", array[j]);
        }
        array[i] = 0;
        printf("\n");
        
    }
    return EXIT_SUCCESS;
}