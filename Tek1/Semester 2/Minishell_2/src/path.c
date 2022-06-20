/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** path
*/

#include "minishell.h"
#include "lib.h"

char *find_command_path(env_t *env)
{
    env_t *tmp = env;
    char *path = NULL;

    if (env == NULL)
        return NULL;
    while (tmp != NULL) {
        if (my_strcmp(tmp->key, "PATH") == 0)
            break;
        tmp = tmp->next;
    }
    path = tmp->value;
    path[my_strlen(tmp->value)] = '\0';
    return path;
}

int parsing_path(char *path, void *str, mysh_t *mysh)
{
    char *tmp_path = my_strdup(path);
    char *sep = ":";
    char *tmp = NULL;
    char *my_strtok = strtok(tmp_path, sep);

    if (!path)
        return -1;
    while (my_strtok != NULL) {
        tmp = my_strtok;
        my_strtok = strtok(NULL, sep);
        mysh->real_path = my_strcat(tmp, my_strcat("/", str));
        if (mysh->real_path == NULL)
            continue;
        if (access(mysh->real_path, X_OK) == 0) {
            return 1;
        }
    }
    return 0;
}
