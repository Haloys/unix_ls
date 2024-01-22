/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Flag_d
*/

#include "../include/my.h"

int check_flags_d(const char *dir, Flags flags)
{
    DIR *dirp = opendir(dir);

    if (flags.flag_d) {
        if (dirp == NULL) {
            perror("opendir failed");
            return -1;
        }
    }
    closedir(dirp);
    return 0;
}
