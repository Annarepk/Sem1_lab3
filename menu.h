#include <stdio.h>
#include "array.h"
#include "changing.h"
#include "checker.h"

void printMenu() {
    printf("What do you want to do?\n"
           "1. Enter list of numbers. (If the list already exists, it is deleted and a new one is created)\n"
           "2. Add numbers to list\n"
           "3. Get changed list\n"
           "4. Print array\n"
           "5. Remove element\n"
           "6. Exit\n"
           ">");
}


int menu(int *count, int **data) {     // count - count of elements in array (data)
    int res = 0, countCommands = 6, command = 0, ind = -1;
    while (1) {
        printMenu();
        res = errors(&command, 1, countCommands + 1);
        if (res == -1) {
            printf("input error in menu\n");
            return -1;
        }

        switch (command) {
            case 1:
                res = inputArray(count, data);
                if (res == -1){
                    printf("input error in menu\n");
                    return -1;
                }
                break;

            case 2:
                res = addNumber(data, count);
                if (res == -1){
                    printf("some error in menu\n");
                    return -1;
                }
                break;

            case 3:
                res = changeArray(data, count);
                if (res == -1){
                    printf("some error in menu\n");
                    return -1;
                }
                break;

            case 4:
                printArray(*data, *count);
                break;

            case 5:
                res = talkingRemove(*count, &ind);
                if (res == -1){
                    printf("some error in menu\n");
                    return -1;
                }

                if (res == 1) {
                    break;
                }

                res = removeElement(data, count, ind);
                if (res == -1){
                    printf("some error in menu\n");
                    return -1;
                }

                printArray(*data, *count);

                break;
            case 6:
                return 0;

            default:
                printf("Unknown cmd\n");
        }
        printf("\n");
    }
    return 0;
}