#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

// Функция для подсчета количества уникальных слов
int countUniqueWords(const char *text) {
    int uniqueWordsCount = 0;
    char *words[1000]; // Предполагаем, что слов не больше 1000
    char *word = strtok(text, " \n");
    int wordIndex = 0;

    while (word != NULL) {
        words[wordIndex++] = word;
        word = strtok(NULL, " \n");
    }

    // Сортировка слов
    qsort(words, wordIndex, sizeof(char*), compareStrings);

    // Проход по отсортированному списку слов    
    for (int i = 0; i < wordIndex - 1; ++i) {
        if (strcmp(words[i], words[i + 1]) == 0) {
            // Слово повторяется, увеличиваем счетчик
            uniqueWordsCount++;
        }
    }
    return wordIndex - uniqueWordsCount;
}

// Функция сравнения строк для qsort


int main() {
    char buffer[1000]; // Предполагаем, что длина текста не больше 100000 символов
    FILE *inputFile = fopen("input.txt", "r");

    // Считывание всего текста в буфер
    fread(buffer, sizeof(char), 1000, inputFile);
    fclose(inputFile);

    // Подсчет количества уникальных слов
    int uniqueWordsCount = countUniqueWords(buffer);
    printf("%d\n", uniqueWordsCount);

    return 0;
}