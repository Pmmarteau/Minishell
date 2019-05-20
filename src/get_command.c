/*
** EPITECH PROJECT, 2018
** get_command.c
** File description:
** ...
*/

#include "../include/my.h"

int check_line(char *buf)
{
    int i = 0;
    int len = my_strlen(buf);
    int check = 0;

    while (buf[i] != '\0') {
        if (buf[i] == ' ' || buf[i] == '\t')
            check++;
        i++;
    } if (check == len - 1)
        return (84);
    return (0);
}

char **remove_begin_space(char **tab)
{
    char **arr = malloc(sizeof(char *) * sizeof(tab));
    int i = 0;
    int j = 0;
    int k = 0;

    while (tab[i] != NULL) {
        arr[i] = malloc(sizeof(char) * my_strlen(tab[i]));
        if (tab[i][j] == ' ') {
            while (tab[i][j] == ' ')
                j++;
        } while (tab[i][j] != '\0') {
            arr[i][k] = tab[i][j];
            k++;
            j++;
        }
        k = 0;
        j = 0;
        i++;
    }
    return (arr);
}

int init_command(char *buf, char **env, char *path)
{
    char **tab = malloc(sizeof(char *) * my_str_count(buf, ';') + 1);
    char **temp;
    int i = 0;
    int fork;
    int check;

    check = check_line(buf);
    if (check != 0)
        return (84);
    tab = str_to_array(buf, ';');
    tab = remove_begin_space(tab);
    while (tab[i] != NULL) {
        temp = str_to_array(tab[i], ' ');
        fork = my_fork(temp, env, path);
        if (fork != 0) {
            return (84);
        }
        i++;
    }
    return (0);
}
