/*
** EPITECH PROJECT, 2023
** My_ls
** File description:
** Main
*/

#include "../include/my.h"

int parse_flags(const char *arg, Flags *flags)
{
    for (int i = 1; arg[i] != '\0'; i++) {
        if (arg[i] == 'a' || arg[i] == 'r' || arg[i] == 'd' ||
            arg[i] == 't' || arg[i] == 'l') {
            set_flag(arg[i], flags);
        } else {
            mini_printf("my_ls: invalid option -- '%c'\n", arg[i]);
            return 1;
        }
    }
    return 0;
}

void refa_print_dir(char **fileslist, int ct, const char *dir, Flags flags)
{
    if (flags.flag_t) {
        sort_t(fileslist, ct, dir);
    } else if (flags.flag_r) {
        sort_r(fileslist, ct);
    } else {
        sort(fileslist, ct);
    }
    for (int i = 0; i < ct; i++) {
        if (flags.flag_l) {
            flags_l(dir, ct, fileslist[i]);
        } else {
            mini_printf("%s  ", fileslist[i]);
        }
    }
    if (!flags.flag_l) {
    mini_printf("\n");
    }
}

void print_directory_contents(const char *dir, Flags flags)
{
    int ct = flags.flag_a ? count_a_files(dir) : count_files(dir);
    char **fileslist = flags.flag_a ? cre_f_ls_a(dir, ct) : cre_f_ls(dir, ct);
    char total_blocks_str[20];
    long total_blocks;

    if (flags.flag_l) {
        total_blocks = calculate_total_blocks(dir, flags);
        if (total_blocks == -1) {
            return;
        }
        my_long_to_string(total_blocks / 2, total_blocks_str);
        mini_printf("total %s\n", total_blocks_str);
    }
    if (ct <= 0) {
        mini_printf("Empty or inaccessible directory\n");
    } else {
        refa_print_dir(fileslist, ct, dir, flags);
    }
    free_files_list(fileslist, ct);
}

void refa_main(const char **directories, int dircount, Flags flags)
{
    for (int i = 0; i < dircount; i++) {
        if (dircount > 1 && !flags.flag_d) {
            mini_printf("%s:\n", directories[i]);
        }
        order_flags(directories[i], flags, i == dircount - 1);
        if (i < dircount - 1 && !flags.flag_d) {
            mini_printf("\n");
        }
    }
}

int main(int argc, char **argv)
{
    int dircount = 0;
    Flags flags = {0};
    const char *directories[argc];
    refa_arg refa_args = {{0}, &dircount, directories};

    if (parse_args(argc, argv, &refa_args) != 0) {
        return 1;
    }
    if (dircount == 0) {
        order_flags(".", refa_args.flags, 1);
    } else {
        refa_main(directories, dircount, refa_args.flags);
    }
    return 0;
}
