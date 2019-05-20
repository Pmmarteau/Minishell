/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** ...
*/

#include "../include/my.h"

char *env_to_path(char *tab, char *path)
{
    int j = 5;
    int k = 0;

    while (tab[j] != '\0') {
        if (tab[j] == ':' || tab[j] == '.')
            path[k] = ' ';
        else if (tab[j] == '.')
            j++;
        else
            path[k] = tab[j];
        j++;
        k++;
    }
    return (path);
}

char *get_path(char **env)
{
    int i = 0;
    char *tab;
    char *path;

    while (env[i] != 0) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T') {
            tab = malloc(sizeof(char) * my_strlen(env[i]));
            tab = env[i];
        }
        i++;
    }
    path = malloc(sizeof(char) * my_strlen(tab));
    path = env_to_path(tab, path);
    return (path);
}

void start_shell(char **env)
{
    char *buffer = malloc(sizeof(char));
    size_t bufsize = 0;
    char *path = get_path(env);

    my_shell(env, buffer, bufsize, path);
}

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./mysh\n");
}

int main(int argc, char **argv, char **env)
{
    if (argc != 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            print_help();
            return (EXIT_SUCCESS);
        } else
            return (EXIT_FAILURE);
    }
    start_shell(env);
    return (EXIT_SUCCESS);
}
