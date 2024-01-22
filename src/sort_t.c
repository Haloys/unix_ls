/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Sort_t
*/

#include "../include/my.h"

void concat_path(char *destination, const char *path1, const char *path2)
{
    my_strcpy(destination, path1);
    my_strcat(destination, "/");
    my_strcat(destination, path2);
}

time_t get_mtime(const char *dir, const char *filename)
{
    char fullpath[PATH_MAX];
    struct stat statbuf;

    concat_path(fullpath, dir, filename);
    if (stat(fullpath, &statbuf) == -1) {
        perror("Failed to get file stats");
        exit(EXIT_FAILURE);
    }
    return statbuf.st_mtime;
}

void sort_t(char *arr[], int n, const char *dirpath)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            refa_sort_t(arr, j, dirpath);
        }
    }
}

void refa_sort_t(char *arr[], int j, const char *dirpath)
{
    char *temp;

    if (get_mtime(dirpath, arr[j]) < get_mtime(dirpath, arr[j + 1])) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
    }
}
