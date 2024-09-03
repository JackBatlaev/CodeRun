
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int is_sym(const int* first, const int* last) {
    if (first >= last) return 1;
    if (*first != *last) return 0;
    return is_sym(first+1,last-1);
}

int main() {

    unsigned N = 0;
    unsigned count = 0;

    //vvod N
    scanf("%d", &N);
    //Proverka N
    if ((N < 1) || (N > 100)) {
        return EXIT_FAILURE;
    }
    //videlenie pamyati
    unsigned *array = (unsigned*)malloc(N * sizeof(int));
    unsigned *start = array;
    //inizializaciya massiva
    memset(array, 0, N);
    //vvod i proverka massiva 
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &array[i]);
        if ((array[i] < 1 || (array[i] > 9))) {
            return EXIT_FAILURE;
        }
    }
    //proverka massiva na uslovie
        while (!is_sym(start,array + N - 1)) {
            ++count;
            ++start;
        }
        printf("%d\n",count);
        for (int i = count - 1; i >= 0; i--) {
            printf("%d ",array[i]);
        }
        //
    return EXIT_SUCCESS;
}