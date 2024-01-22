/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Create_files
*/

#include "../include/my.h"

char **cre_f_ls(const char *dirc, int count)
{
    DIR *dir = opendir(dirc);
    char **fileslist;

    fileslist = (char **)malloc(sizeof(char *) * count);
    if (fileslist == NULL) {
    perror("my_ls: cannot access");
    closedir(dir);
    return NULL;
    }
    populate_files_list(dir, fileslist, count);
    closedir(dir);
    return fileslist;
}
