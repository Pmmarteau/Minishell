/*
** EPITECH PROJECT, 2018
** shell.c
** File description:
** ...
*/

#include "../include/my.h"

int check_access_command(char **path, char **buf)
{
    int i = 0;
    int check = 0;

    while (path[i] != NULL) {
        my_strcat(path[i], "/");
        my_strcat(path[i], buf[0]);
        if (access(path[i], F_OK) != -1)
            check++;
        i++;
    }
    if (check > 0)
        return (0);
    my_putstr(buf[0]);
    my_putstr(": Command not found.\n");
    return (84);
}

int my_fork(char **my_buf, char **env, char *my_path)
{
    int cd;
    pid_t pid;
    int check;
    char **path = str_to_array(my_path, ' ');

    cd = check_cd(my_buf);
    if (cd == 1 || cd == 84)
        return (0);
    check = check_access_command(path, my_buf);
    if (check == 84)
        return (84);
    if (cd == 0) {
        pid = fork();
        if (pid == 0)
            do_command(path, my_buf, env);
        else
            wait(0);
    }
    return (0);
}

void my_shell(char **env, char *buffer, size_t bufsize, char *path)
{
    int init;

    my_putstr("[pierre-marie.marteau]$ ");
    while (getline(&buffer, &bufsize, stdin) != -1) {
        if (buffer[0] == '\n')
            my_shell(env, buffer, bufsize, path);
        exit_shell(buffer);
        init = init_command(buffer, env, path);
        if (init == 84)
            my_shell(env, buffer, bufsize, path);
        my_putstr("[pierre-marie.marteau]$ ");
    }
}

void exit_shell(char *buffer)
{
    if (buffer[0] == 'e' && buffer[1] == 'x' &&
        buffer[2] == 'i' && buffer[3] == 't' && buffer[4] == '\n')
        exit(0);
}

void do_command(char **path, char **buffer, char **env)
{
    int i = 0;

    while (path[i] != NULL) {
        execve(path[i], &buffer[0], env);
        i++;
    }
}
