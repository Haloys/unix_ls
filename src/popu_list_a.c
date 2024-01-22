/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Popu_list_a
*/

#include "../include/my.h"

void populate_files_list_a(DIR *dirc, char **fileslist, int count)
{
    struct dirent *file;
    int i = 0;

    file = readdir(dirc);
    while (file != NULL && i < count) {
        refac_pop_a(dirc, fileslist, file, &i);
        file = readdir(dirc);
    }
}

void refac_pop_a(DIR *dirc, char **fileslist, struct dirent *file, int *i)
{
    fileslist[*i] = (char *)malloc(my_strlen(file->d_name) + 1);
    if (fileslist[*i] == NULL) {
        free_files_list(fileslist, *i);
        closedir(dirc);
        exit(84);
    }
    my_strcpy(fileslist[*i], file->d_name);
    (*i)++;
}
