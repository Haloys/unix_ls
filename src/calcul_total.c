/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Calcul_total
*/

#include "../include/my.h"

long calculate_total_blocks(const char *dir, Flags flags)
{
    DIR *d;
    struct dirent *dir_entry;
    long total_blocks = 0;

    d = opendir(dir);
    if (d == NULL) {
        return -1;
    }
    dir_entry = readdir(d);
    while (dir_entry != NULL) {
        total_blocks += refa_cal(dir, dir_entry, flags);
        dir_entry = readdir(d);
    }
    closedir(d);
    return total_blocks;
}

long refa_cal(const char *dir, struct dirent *dir_entry, Flags flags)
{
    struct stat statbuf;
    char fullpath[PATH_MAX];
    long block_count = 0;

    if (!flags.flag_a && dir_entry->d_name[0] == '.') {
        return 0;
    }
    concat_path(fullpath, dir, dir_entry->d_name);
    if (stat(fullpath, &statbuf) == -1) {
        return 0;
    }
    block_count = statbuf.st_blocks;
    return block_count;
}
