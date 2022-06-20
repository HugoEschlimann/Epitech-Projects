/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** separator
*/

#include "lib.h"
#include "minishell.h"

void separator(mysh_t *mysh, env_t *env)
{
    pid_t child = 0;
    int status = 0;
    char **arr = my_str_to_word_array(mysh->line, ";");
    char **tmp = NULL;

    for (int i = 0; arr[i]; i++) {
        tmp = my_str_to_word_array(arr[i], " ");
        if (parsing_path(mysh->path, tmp[0], mysh) == 1) {
            child = fork();
            if (child == 0)
                execve(mysh->real_path, tmp, my_env_to_array(&env));
            else
                waitpid(child, &status, WUNTRACED);
        } else
            my_printf("%s: Command not found.\n", tmp[0]);
    }
}
