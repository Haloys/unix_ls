/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Parse_args
*/

#include "../include/my.h"

int parse_args(int argc, char **argv, refa_arg *refa_arg)
{
    int i;

    *(refa_arg->dircount) = 0;
    for (i = 1; i < argc; i++) {
        if (refa_parse_arg(argv[i], refa_arg) != 0) {
            return 1;
        }
    }
    return 0;
}

int refa_parse_arg(const char *arg, refa_arg *refa_arg)
{
    if (arg[0] == '-') {
        return parse_flags(arg, &(refa_arg->flags));
    } else {
        refa_arg->directories[*(refa_arg->dircount)] = arg;
        (*(refa_arg->dircount))++;
        return 0;
    }
}
