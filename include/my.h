/*
** EPITECH PROJECT, 2023
** Main Header
** File description:
** Lib principale
*/

#include <stdarg.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "struct_args.h"
#include "struct_args_l.h"
#include "struct_date.h"

#ifndef MY_H_
    #define MY_H_

int mini_printf(const char *format, ...);
int my_putchar(char c);
int my_put_nbr(int number_put);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *str1, const char *str2);
int my_getnbr(char const *str);
void reverse_string(char *str);
void my_long_to_string(long num, char *str);
void digit_to_str(int digit, char *str);
void sort(char *arr[], int n);
void refa_sort(char *arr[], int j, char *temp);
void sort_t(char *arr[], int n, const char *dirpath);
void refa_sort_t(char *arr[], int j, const char *dirpath);
void sort_r(char *arr[], int n);
void refa_sort_r(char *arr[], int j);
int count_files(const char *directory);
int count_a_files(const char *directory);
void populate_files_list(DIR *dir, char **fileslist, int count);
void refac_popu(DIR *dirc, char **fileslist, struct dirent *file, int *index);
void populate_files_list_a(DIR *dir, char **fileslist, int count);
void refac_pop_a(DIR *dirc, char **fileslist, struct dirent *file, int *index);
char **cre_f_ls(const char *directory, int count);
char **cre_f_ls_a(const char *directory, int count);
void free_files_list(char **fileslist, int count);
time_t get_mtime(const char *dir, const char *filename);
void concat_path(char *destination, const char *path1, const char *path2);
void format_time(time_t mod_time, char *time_str);
void get_perm(mode_t mode, char *perms);
void flags_l(const char *dir, int ct, const char *filename);
int parse_flags(const char *arg, Flags *flags);
int parse_args(int argc, char **argv, refa_arg *refa_arg);
int check_flags_d(const char *dir, Flags flags);
int order_flags(const char *dir, Flags flags, int lastdir);
void print_directory_contents(const char *dir, Flags flags);
long calculate_total_blocks(const char *dir, Flags flags);
long refa_cal(const char *dir, struct dirent *dir_entry, Flags flags);
void set_flag(char flag, Flags *flags);
void refa_main(const char **directories, int dircount, Flags flags);
int refa_parse_arg(const char *arg, refa_arg *refa_arg);
void local_time(time_t time, date *date);

#endif
