/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Struct_args_l
*/

#ifndef STRUCT_ARGS_L_H
    #define STRUCT_ARGS_L_H

typedef struct fileinfo {
    char perms[11];
    int link_count;
    char *pw_name;
    char *gr_name;
    int file_size;
    char time_str[18];
    const char *filename;
} fileinfo;

#endif
