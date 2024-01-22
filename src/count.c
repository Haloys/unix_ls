/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Count_files
*/

#include "../include/my.h"

int count_files(const char *dirc)
{
    DIR *dir = opendir(dirc);
    struct dirent *file;
    int count = 0;

    if (dir == NULL) {
        perror("my_ls: cannot access");
    return -1;
    }
    file = readdir(dir);
    while (file != NULL) {
        if (file->d_name[0] != '.') {
        count++;
        }
        file = readdir(dir);
    }
    closedir(dir);
    return count;
}
