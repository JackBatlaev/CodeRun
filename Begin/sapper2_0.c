#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


#define MAX_N 100  // максимальные размеры для примера
#define MAX_M 100

int result[MAX_N][MAX_M];
int neighbors[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

void add_neighbors(int n, int m, int i, int j) {
    result[i][j] = -1;  // Используем -1 для обозначения мины
    for (int d = 0; d < 8; d++) {
        int n_i = i + neighbors[d][0];
        int n_j = j + neighbors[d][1];
        if (n_i >= 0 && n_i < n && n_j >= 0 && n_j < m && result[n_i][n_j] != -1) {
            result[n_i][n_j]++;
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // Инициализация результата нулями
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;  // Переход на 0-индексацию
        y--;
        add_neighbors(n, m, x, y);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", result[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
