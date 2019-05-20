/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** ...
*/

#include "../include/my.h"

char *my_strncpy(char *str, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        str[i] = src[i];
        i = i + 1;
    }
    if (n <= i)
        str[i] = '\0';
    return (str);
}

char *my_strcat(char *str, char const *src)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
        i = i + 1;
    while (src[j] != '\0') {
        str[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    str[i] = '\0';
    return (str);
}

char	**str_to_array(char *str, char sep)
{
    int	i = 0;
    int	j = 0;
    int	len = 0;
    char	**my_tab;

    my_tab = malloc(sizeof(char *) * my_str_count(str, sep) + 1);
    while (str != NULL && str[i]) {
        if (my_str_is_alpha(str[i], sep))
  	        len = len + 1;
        if (my_str_is_alpha(str[i], sep) == 1 &&
            my_str_is_alpha(str[i + 1], sep) == 0) {
            my_tab[j] = malloc(len + 1);
            my_strncpy(my_tab[j], &str[i - len + 1], len);
            len = 0;
            j = j + 1;
        }
        i = i + 1;
    }
    my_tab[j] = NULL;
    return (my_tab);
}

int my_strcmp_no_end(char const *str1, char const *str2)
{
    int i = 0;
    int bool = 1;

    while (bool && str1[i] != '\0'
        && str2[i] != '\0'
        && (str1[i] == str2[i]
        || (str1[i] == '*' || str2[i] == '*')) && str2[i] != '\0') {
        bool = (str1[i] == str2[i]);
        if (str1[i] == '*' || str2[i] == '*')
            return (1);
        i = i + 1;
    }
    return (((str1[i] == '\0') || str1[i] == '*')
    && ((str2[i] == '\0') || str2[i] == '*'));
}
