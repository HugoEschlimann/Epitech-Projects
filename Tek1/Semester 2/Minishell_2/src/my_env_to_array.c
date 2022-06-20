/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** my_env_to_array
*/

#include "minishell.h"
#include "lib.h"

char **my_env_to_array(env_t **env)
{
    env_t *tmp = *env;
    char **new_env = NULL;
    char *str = NULL;
    int cpt = 0;
    int i = 0;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->key != NULL)
            cpt++;
    tmp = *env;
    new_env = malloc(sizeof(char *) * (cpt + 1));
    for (; tmp != NULL; tmp = tmp->next, i++) {
        str = my_strcat(tmp->key, my_strcat("=", tmp->value));
        new_env[i] = my_strdup(str);
    }
    new_env[i] = NULL;
    return new_env;
}
