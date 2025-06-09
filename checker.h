#ifndef MOSQUITO_MORON_CHECKER_H
#define MOSQUITO_MORON_CHECKER_H

#include <stdio.h>
#include <stdlib.h>

int errors(int *number, int start, int finish) {
    while (1) {
        int stat = scanf("%d", number);

        if (stat == EOF) {
            printf("EOF cought\n");
            scanf("%*[^\n]");

            return -1;
        }

        if (stat == 1 && *number < finish && *number >= start) return 0;

        scanf("%*[^\n]");
        printf("Error. Enter integer in range (%d, %d): ", start, finish); // вывести вверх в main: EOF завершает работу программы; неверный ввод - исправление ввода
    }
    return 0;
}

#endif
