/*  «Сапер» 
Вам необходимо построить поле для игры «Сапер» по его конфигурации — размерам и координатам расставленных на нём мин.
Вкратце напомним правила построения поля для игры «Сапер»:
Поле состоит из клеток с минами и пустых клеток
Клетки с миной обозначаются символом *
Пустые клетки содержат число 
≤8 — количество мин на соседних клетках. Соседними клетками являются восемь клеток, имеющих смежный угол или сторону.
Формат ввода
В первой строке содержатся три числа: 
N,1≤N≤100 - количество строк на поле, 
M,1≤M≤100 - количество столбцов на поле, 
K,0≤K≤N⋅M - количество мин на поле.
В следующих 
K строках содержатся по два числа с координатами мин: 
p,1≤p≤N - номер строки мины, 
q,1≤1≤M - номер столбца мины.
Формат вывода
Выведите построенное поле, разделяя строки поля переводом строки, а столбцы - пробелом.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100  // максимальные размеры для примера
#define MAX_M 100
#define MAX_MINES 10000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

//структура поля
struct Field {
    unsigned width;
    unsigned height;
    unsigned mines;
    unsigned **cells;
};

void initField(struct Field *field, unsigned widht, unsigned height, unsigned mines) {
    field->width = widht;
    field->height = height;
    field->mines = mines;
    //init array
    field->cells = calloc(field->height, sizeof(unsigned*));
    for (int i = 0; i < field->height; i++){
        field->cells[i] = calloc(field->width,  sizeof(unsigned));
    }
    //initMines
    unsigned mineLocations[field->mines][2];
    for (size_t i = 0; i < field->mines; i++) {
        unsigned x; scanf("%d", &x);
        unsigned y; scanf("%d", &y);
        x = max(0, x - 1); mineLocations[i][0] = x;
        y = max(0, y - 1); mineLocations[i][1] = y;
        field->cells[x][y] = -1;
    }    
    //подсчет окружения
    for (size_t i = 0; i < field->height; i++) {
        for (size_t j = 0; j < field->width; j++) {
            if (field->cells[i][j] == -1) continue;
            int adjacentMine = 0;
            for (int r = max(0, i - 1); r <= min(field->height - 1, i + 1); r++) {
                for (int c = max(0, j - 1); c <= min (field->height - 1, j + 1); c++) {
                    if (field->cells[r][c] == -1 ) {
                        adjacentMine++;
                    }
                }
            }
            field->cells[i][j] = adjacentMine;
        }
    }
}

void printField(struct Field *field){
    for (int i = 0; i < field->height; i++) {
        for (int j = 0; j < field->width; j++) {
            if (field->cells[i][j] > 8) {
                printf("* ");
            } else {
                printf("%d ", field->cells[i][j]);
            }
        }
        printf("\n"); 
    }

}

int main() {
    struct Field field;
    unsigned N,M,K;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &K); 

    initField(&field, M, N, K);

    printField(&field);

    return EXIT_SUCCESS;
}