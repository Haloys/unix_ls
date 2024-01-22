/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Sort
*/

#include "../include/my.h"

void sort(char *arr[], int n)
{
    int i;
    int j;
    char *temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            refa_sort(arr, j, temp);
        }
    }
}

void refa_sort(char *arr[], int j, char *temp)
{
    if (my_strcmp(arr[j], arr[j + 1]) > 0) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
    }
}
