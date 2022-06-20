/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** my_env
*/

#include "minishell.h"
#include "lib.h"

void my_env(env_t *env)
{
    while (env != NULL) {
        my_printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
}
