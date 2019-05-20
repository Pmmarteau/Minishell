/*
** EPITECH PROJECT, 2018
** my_cd.c
** File description:
** ...
*/

#include "../include/my.h"

int check_cd(char **buf)
{
    int i = 0;
    int error = 0;

    while (buf[i] != NULL) {
        if (buf[i][0] == 'c' && buf[i][1] == 'd') {
            error = dir_exists(buf[i + 1]);
            if (error == 84) {
                my_putstr("Folder ");
                my_putstr(buf[i + 1]);
                my_putstr(" does not exist\n");
                return (84);
            }
            chdir(buf[i + 1]);
            return (1);
        }
        i = i + 1;
    }
    return (0);
}

int dir_exists(const char *file)
{
    struct stat buffer;
    int exists = stat(file, &buffer);

    if (exists == 0)
        return (0);
    else
        return (84);
}
