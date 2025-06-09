#ifndef MOSQUITO_MORON_ARRAY_H
#define MOSQUITO_MORON_ARRAY_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "checker.h"

void printArray(int *array, int len);

int inputArray(int *len, int **array);

int addNumber(int **array, int *len);

int talkingRemove(int len, int *index);



void printArray(int *array, int len) {
    if (len == 0) {
        printf("Empty\n");
        return;
    }
    printf("array: ");
    for (int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");
}

int inputArray(int *len, int **array) {
    printf("Enter len of array: ");

    if (errors(len, 1, INT_MAX) == -1) {
        printf("EOF in init array, loh;)\n");
        return -1;
    }
    *array = (int *) realloc(*array, *len * sizeof(int));

    if (!(*array) && *len != 0) {
        printf("alloc error in input\n");
        return -1;
    }

    printf("Enter elements of array:\n");
    for (int i = 0; i < *len; i++) {
        printf("array[%d] = ", i);

        if (errors(&((*array)[i]), INT_MIN, INT_MAX) == -1) {
            printf("EOF in init array, loh;)\n");
            return -1;
        }
    }
    printArray(*array, *len);
    return 0;
}

int addNumber(int **array, int *len) {
    int ind = 0, value = 0;
    printf("Enter index \"-1\" for finish\n");
    while (1) {
        printf("\nEnter index: ");

        if (errors(&ind, -1, INT_MAX) == -1) {
            printf("EOF in add array, loh\n");
            return -1;
        }

        if (ind == -1) return 0;

        printf("Enter number: ");
        if (errors(&value, INT_MIN, INT_MAX) == -1) {
            printf("EOF in add array, loh\n");
            return -1;
        }

        ++(*len);

        *array = (int *) realloc(*array, *len * sizeof(int));

        if (!(*array) && *len != 0) {
            printf("alloc error in add");
            return -1;
        }

        if (ind >= *len) ind = *len - 1;
        else for (int i = *len - 1; i > ind; i--) (*array)[i] = (*array)[i - 1];

        (*array)[ind] = value;
        printArray(*array, *len);
    }
    return 0;
}

int talkingRemove(int len, int *index) {
    if (len == 0) {
        printf("There are no elements in the array\n");
        return 1;
    }
    printf("Enter index of element for removing: ");
    if (errors(index, 0, len) == -1) {
        printf("EOF in remove\n");
        return -1;
    }
    return 0;
}

#endif