/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** my_setenv
*/

#include "minishell.h"
#include "lib.h"

void check_key(mysh_t *mysh, env_t *t_env)
{
    int check = 0;

    while (t_env != NULL) {
        if (my_strcmp(t_env->key, mysh->params[1]) == 0) {
            check = 1;
            t_env->value = mysh->params[2];
            break;
        }
        if (t_env->next == NULL && check == 0) {
            add_node_at_back(&t_env, mysh->params[1], mysh->params[2]);
        }
        t_env = t_env->next;
    }
}

void check_value(mysh_t *mysh, env_t *t_env)
{
    int check = 0;

    while (t_env != NULL) {
        if (my_strcmp(t_env->key, mysh->params[1]) == 0) {
            check = 1;
            t_env->value = "";
            break;
        }
        if (t_env->next == NULL && check == 0) {
            add_node_at_back(&t_env, mysh->params[1], "");
        }
        t_env = t_env->next;
    }
}

void check_error(mysh_t *mysh)
{
    if (is_alpha(mysh->params[1][0]) == 1 && is_num(mysh->params[1][0]) == 1) {
        my_printf("%s: Variable name must begin with a letter.\n",
        mysh->params[0]);
        return;
    }
    if (str_isalpha(mysh->params[1]) == 1) {
        my_printf("%s: Variable name must contain alphanumeric characters.\n",
        mysh->params[0]);
        return;
    }
    if (str_isalpha(mysh->params[2]) == 1 && str_isnum(mysh->params[2]) == 1 &&
        check_non_alpha(mysh->params[2]) == 1) {
        my_printf("%s: No match.\n", mysh->params[2]);
        return;
    }
    if (mysh->params[3] != NULL) {
        my_printf("%s: Too many arguments.\n", mysh->params[0]);
        return;
    }
}

void my_setenv(mysh_t *mysh, env_t *t_env)
{
    if (mysh->params[1] == NULL) {
        my_env(t_env);
    }
    if (mysh->params[1] != NULL && mysh->params[2] != NULL) {
        check_error(mysh);
        check_key(mysh, t_env);
    }
    if (mysh->params[2] == NULL && mysh->params[1] != NULL) {
        check_value(mysh, t_env);
    }
}
