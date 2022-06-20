/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** my_str_to_word_array
*/

#include "../include/lib.h"

char **my_str_to_word_array(char *str, char *sep)
{
    char *str_cpy = my_strdup(str);
    int nb_args = nb_arg(str_cpy, sep);
    char **av = malloc(sizeof(char *) * nb_args);

    if (!str)
        return NULL;
    av[0] = my_strdup(strtok(str_cpy, sep));
    for (int i = 1; i < nb_args; i++) {
        av[i] = my_strdup(strtok(NULL, sep));
    }
    return av;
}

int nb_arg(char *str, char *sep)
{
    int cpt = 0;
    char *dup = my_strdup(str);
    char *tmp = malloc(sizeof(char) * my_strlen(str));

    tmp = strtok(dup, sep);
    cpt++;
    while (tmp) {
        tmp = strtok(NULL, sep);
        cpt++;
    }
    return cpt;
}
