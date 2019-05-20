/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** ...
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>

char *get_path(char **);
int check_file(char **path);
char *get_stdin(void);
void do_command(char **, char **, char **);
void exit_shell(char *);
void my_shell(char **, char *, size_t, char *);
void find_dir(char *);
int check_cd(char **);
int check_setenv(char **, char **);
int check_access_command(char **, char **);
int my_fork(char **, char **, char *);
int init_command(char *, char **, char *);
int check_line(char *);
int dir_exists(const char *);

void my_putchar(char);
void my_putstr(char *);
int my_getnbr(char const *);
int my_put_nbr(int);
char **str_to_array(char *, char);
char *my_strcpy(char *, char const *);
char *my_strcat(char *, char const *);
int my_strlen(char const *);
int my_str_count(char *, char);
int my_str_is_alpha(char, char);

#endif
