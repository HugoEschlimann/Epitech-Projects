/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** my_cd
*/

#include "lib.h"
#include "minishell.h"

void my_cd_menu(mysh_t *mysh, env_t *t_env)
{
    if (mysh->params[1] == NULL || my_strcmp(mysh->params[1], "~") == 0) {
        my_cd(t_env);
        return;
    }
    if (mysh->params[2] != NULL) {
        my_printf("%s: Too many arguments.\n", mysh->params[0]);
        return;
    } else if (my_strcmp(mysh->params[1], "-") == 0) {
        my_cd_tiret(t_env);
        return;
    } else {
        my_cd_indirect(mysh, t_env);
        return;
    }
}

void my_cd(env_t *t_env)
{
    char *path = NULL;
    char *tmp = getcwd(path, 1024);

    while (t_env != NULL) {
        if (my_strcmp(t_env->key, "HOME") == 0) {
            chdir(t_env->value);
        }
        if (my_strcmp(t_env->key, "OLDPWD") == 0) {
            t_env->value = tmp;
        }
        t_env = t_env->next;
    }
}

void my_cd_tiret(env_t *t_env)
{
    char *path = NULL;
    char *tmp = getcwd(path, 1024);

    while (t_env != NULL) {
        if (my_strcmp(t_env->key, "OLDPWD") == 0 && t_env->value != NULL) {
            chdir(t_env->value);
            t_env->value = tmp;
        }
        if (my_strcmp(t_env->key, "PWD") == 0) {
            t_env->value = tmp;
        }
        t_env = t_env->next;
    }
}

void my_cd_indirect(mysh_t *mysh, env_t *t_env)
{
    char *path = NULL;

    path = getcwd(path, 1024);
    chdir(mysh->params[1]);
    while (t_env != NULL) {
        if (my_strcmp(t_env->key, "OLDPWD") == 0)
            t_env->value = path;
        t_env = t_env->next;
    }
}
