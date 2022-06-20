/*
** EPITECH PROJECT, 2022
** mini_shell1
** File description:
** main.c
*/

#include "minishell.h"
#include "lib.h"

int main(int ac, UNUSED char **av, char **env)
{
    mysh_t mysh = init_params(env);

    if (error_handling(ac) == 84)
        return 84;
    prompt();
    main_loop(&mysh);
    free_all(&mysh);
    return 0;
}

void main_loop(mysh_t *mysh)
{
    int a = 0;

    while (getline(&mysh->line, &mysh->len, stdin) != -1) {
        if (mysh->line != NULL)
            mysh->line[my_strlen(mysh->line) - 1] = '\0';
        if (checker(mysh) == false) {
            mysh->params = my_str_to_word_array(mysh->line, " \n\t");
            if (parsing_path(mysh->path, mysh->params[0], mysh) == 1 &&
            my_strcmp(mysh->params[0], "env") != 0 &&
            my_strcmp(mysh->params[0], "cd") != 0)
                different_command(mysh, mysh->node);
            else if (mysh->params[0] && (mysh->params[0][0] == '.' ||
            mysh->params[0][0] == '/'))
                a = other_commands(mysh, mysh->node);
            else
                exception(mysh, mysh->node);
        } else
            execute_command(mysh, mysh->node);
        if (WIFSIGNALED(a))
            check_segf(a);
        getcwd(mysh->pwd, sizeof(mysh->pwd));
        prompt();
    }
}

int other_commands(mysh_t *mysh, env_t *t_env)
{
    pid_t child = fork();
    int status = 0;

    if (child == 0)
        execve(mysh->params[0], mysh->params, my_env_to_array(&t_env));
    else
        waitpid(child, &status, WUNTRACED);
    return status;
}

void free_all(mysh_t *mysh)
{
    free(mysh->line);
    free(mysh->real_path);
}

int prompt(void)
{
    char pwd[1024];

    if (isatty(0) == 1)
        my_printf("hugo: %s> ", getcwd(pwd, sizeof(pwd)));
    return 0;
}
