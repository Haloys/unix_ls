/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Set_flag
*/

#include "../include/my.h"

void set_flag(char flag, Flags *flags)
{
    switch (flag) {
        case 'a':
            flags->flag_a = 1;
            break;
        case 'r':
            flags->flag_r = 1;
            break;
        case 'd':
            flags->flag_d = 1;
            break;
        case 't':
            flags->flag_t = 1;
            break;
        case 'l':
            flags->flag_l = 1;
            break;
    }
}
