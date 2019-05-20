/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** ...
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_str_is_alpha(char c, char sep)
{
    if (c < ' ' || c >= 127 || c == sep)
        return (0);
    return (1);
}

int my_str_count(char *str, char sep)
{
    int i = 0;
    int j = 0;

    while (str != NULL && str[i]) {
        if (my_str_is_alpha(str[i], sep) == 1 &&
            my_str_is_alpha(str[i + 1], sep) == 0)
            j++;
        i++;
    }
    return (j);
}
