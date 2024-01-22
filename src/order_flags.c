/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Order_flags.c
*/

#include "../include/my.h"

int order_flags(const char *dir, Flags flags, int lastdir)
{
    if (check_flags_d(dir, flags) == -1) {
        return -1;
    }
    if (flags.flag_l && flags.flag_d) {
        flags_l(".", 0, dir);
        return 0;
    }
    if (flags.flag_d) {
        mini_printf("%s  ", dir);
        if (lastdir) {
            mini_printf("\n");
        }
        return 0;
    }
    print_directory_contents(dir, flags);
    return 0;
}
