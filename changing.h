///Move all even digits to the beginning of the number

#include <stdlib.h>
#include "array.h"


int sortArray(int *array, int len) {
    int indMin = 0;

    for (int i = 0; i < len - 1; i++) {
        int maxElement = INT_MIN;
        for (int j = i; j < len; j++) {
            if (array[j] > maxElement) maxElement = array[j], indMin = j;
        }
        array[indMin] = array[i];
        array[i] = maxElement;
    }
    return 0;
}


int changeElement(int element) {
    int *numbers = NULL, ind = -1, newNumber = 0;

    while (element > 0) {
        ind++;
        numbers = (int *) realloc(numbers, (ind + 1) * sizeof(int));

        if (!(numbers) && (ind + 1) != 0) {
            printf("alloc error in numbers changing\n");
            return -1;
        }

        numbers[ind] = element % 10;
        element /= 10;
    }
    ind++;  // now it's length
    sortArray(numbers, ind);

    for (int i = 0; i < ind; i++) newNumber = newNumber * 10 + numbers[i];

    free(numbers);
    return newNumber;
}


int removeElement(int **dat, int *counter, int index) {
    for (int j = index; j < *counter - 1; ++j) (*dat)[j] = (*dat)[j + 1];
    --(*counter);

    *dat = (int *) realloc(*dat, *counter * sizeof(int));

    if (!(*dat) && *counter != 0) {
        printf("alloc error in remove element\n");
        return -1;
    }

    return 0;
}


int changeArray(int **array, int *len) {
    printf("from ");
    printArray(*array, *len);
    int newElement = 0;

    for (int i = 0; i < *len; ++i) {
        if ((*array)[i] < 0) newElement = (-1) * changeElement((*array)[i] * (-1));
        else newElement = changeElement((*array)[i]);
        if ((*array)[i] == newElement) {
            if (removeElement(array, len, i) == -1) printf("alloc error in charray\n");
            --i;
        }
        else (*array)[i] = newElement;
    }
    printf("to ");
    printArray(*array, *len);

    return 0;
}