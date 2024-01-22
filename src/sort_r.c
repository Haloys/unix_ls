/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Sort_r
*/

#include "../include/my.h"

void sort_r(char *arr[], int n)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            refa_sort_r(arr, j);
        }
    }
}

void refa_sort_r(char *arr[], int j)
{
    char *temp;

    if (my_strcmp(arr[j], arr[j + 1]) < 0) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
    }
}
