/*
** EPITECH PROJECT, 2023
** Main Lib
** File description:
** Free_files
*/

#include "../include/my.h"

void free_files_list(char **fileslist, int count)
{
    for (int i = 0; i < count; i++) {
        free(fileslist[i]);
    }
    free(fileslist);
}
