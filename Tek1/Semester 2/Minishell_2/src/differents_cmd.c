/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** differents_cmd
*/

#include "minishell.h"
#include "lib.h"

int different_command(mysh_t *mysh, env_t *t_env)
{
    pid_t child = fork();
    int status = 0;

    if (child == 0) {
        execve(mysh->real_path, mysh->params, my_env_to_array(&t_env));
    } else
        waitpid(child, &status, WUNTRACED);
    return status;
}

int check_command(mysh_t *mysh, env_t *t_env)
{
    if (!mysh->params[0])
        return 0;
    if (my_strcmp(mysh->params[0], "exit") == 0) {
        my_exit(mysh);
        return 0;
    }
    if (my_strcmp(mysh->params[0], "setenv") == 0) {
        my_setenv(mysh, t_env);
        return 0;
    }
    if (check_command2(mysh, t_env) == 0)
        return 0;
    return 1;
}

int check_command2(mysh_t *mysh, env_t *t_env)
{
    if (my_strcmp(mysh->params[0], "cd") == 0) {
        my_cd_menu(mysh, t_env);
        return 0;
    }
    if (my_strcmp(mysh->params[0], "env") == 0) {
        my_env(t_env);
        return 0;
    }
    if (my_strcmp(mysh->params[0], "unsetenv") == 0) {
        my_unsetenv(mysh, t_env);
        return 0;
    }
    return 1;
}

int exception(mysh_t *mysh, env_t *t_env)
{
    if (check_command(mysh, t_env) != 0)
        my_printf("%s: Command not found.\n", mysh->params[0]);
    return 1;
}

void check_segf(int a)
{
    if (WIFSIGNALED(a)) {
        my_printf("Segmentation fault %s\n",
        WCOREDUMP(a) ? "(core dumped)" : "");
    }
}
