/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Flag_l
*/

#include "../include/my.h"

static const char *month_names[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

int refa_flag_l_error(const char *fullpath, struct stat *statbuf)
{
    if (stat(fullpath, statbuf) == -1) {
        perror("Failed to get file stats");
        return -1;
    }
    return 0;
}

void print_file_info(fileinfo *fileinfo)
{
    mini_printf("%s ", fileinfo->perms);
    mini_printf("%d ", fileinfo->link_count);
    mini_printf("%s ", fileinfo->pw_name ? fileinfo->pw_name : "???");
    mini_printf("%s ", fileinfo->gr_name ? fileinfo->gr_name : "???");
    mini_printf("%d ", fileinfo->file_size);
    mini_printf("%s ", fileinfo->time_str);
    mini_printf("%s", fileinfo->filename);
    mini_printf("\n");
}

void flags_l(const char *dir, int ct, const char *filename)
{
    fileinfo fileinfo;
    char fullpath[PATH_MAX];
    struct stat statbuf;
    struct passwd *pw;
    struct group  *gr;

    concat_path(fullpath, dir, filename);
    if (refa_flag_l_error(fullpath, &statbuf) != 0) {
        exit(EXIT_FAILURE);
    }
    get_perm(statbuf.st_mode, fileinfo.perms);
    format_time(statbuf.st_mtime, fileinfo.time_str);
    pw = getpwuid(statbuf.st_uid);
    gr = getgrgid(statbuf.st_gid);
    fileinfo.link_count = (int)statbuf.st_nlink;
    fileinfo.file_size = (int)statbuf.st_size;
    fileinfo.pw_name = pw ? pw->pw_name : "???";
    fileinfo.gr_name = gr ? gr->gr_name : "???";
    fileinfo.filename = filename;
    print_file_info(&fileinfo);
}

void get_perm(mode_t mode, char *perms)
{
    my_strcpy(perms, "----------");
    if (S_ISDIR(mode)) {
        perms[0] = 'd' ;
    } else if (S_ISLNK(mode)) {
        perms[0] = 'l';
    }
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';
}

void format_time(time_t mod_time, char *time_str)
{
    date date;
    char temp[5];

    local_time(mod_time, &date);
    my_strcpy(time_str, month_names[date.month]);
    my_strcat(time_str, " ");
    digit_to_str(date.day, temp);
    my_strcat(time_str, temp);
    my_strcat(time_str, " ");
    digit_to_str(date.hour, temp);
    my_strcat(time_str, temp);
    my_strcat(time_str, ":");
    digit_to_str(date.minute, temp);
    my_strcat(time_str, temp);
}
