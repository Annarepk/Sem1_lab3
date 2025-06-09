///Implementation of the basic functions of the array

#include "menu.h"

int main() {
    int len = 0, *array = NULL;

    if (menu(&len, &array) == -1) {
        free(array);
        printf("some error in main\n");
        return -1;
    }
    free(array);

    return 0;
}