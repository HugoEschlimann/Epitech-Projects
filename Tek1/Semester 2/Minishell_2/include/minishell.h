/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** minishell1.h
*/

#ifndef MINISHELL
    #define MINISHELL
    #define UNUSED __attribute__((unused))

    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <string.h>
    #include <signal.h>
    #include <ucontext.h>
    #include <time.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <stdbool.h>

typedef struct env_s {
    char *key;
    char *value;
    struct env_s *next;
} env_t;

typedef struct mysh_s {
    char *line;
    char *real_path;
    char **params;
    size_t len;
    char pwd[1024];
    char *path;
    char *env_line;
    env_t *node;
} mysh_t;

void main_loop(mysh_t *mysh);

env_t *create_linked_list(char **str);
void print_list_key(env_t *node);
void print_list_value(env_t *node);
env_t *add_node_at_back(env_t **node, char *key, char *value);
char *find_command_path(env_t *env);
int error_handling(int ac);

int check_command(mysh_t *mysh, env_t *t_env);
int check_command2(mysh_t *mysh, env_t *t_env);
int different_command(mysh_t *mysh, env_t *t_env);
int command_root(mysh_t *mysh, char **av, char **env);
void my_env(env_t *env);
void my_setenv(mysh_t *mysh, env_t *t_env);
void my_unsetenv(mysh_t *mysh, env_t *t_env);
int prompt(void);
void my_exit(mysh_t *mysh);
int parsing_path(char *str, void *a, mysh_t *mysh);
int exception(mysh_t *mysh, env_t *t_env);
mysh_t init_params(char **env);

void my_cd(env_t *t_env);
void my_cd_menu(mysh_t *mysh, env_t *t_env);
void my_cd_tiret(env_t *t_env);
void my_cd_direct(env_t *t_env);
void my_cd_indirect(mysh_t *mysh, env_t *t_env);
void check_segf(int a);
int other_commands(mysh_t *mysh, env_t *t_env);
char **my_env_to_array(env_t **env);
void free_all(mysh_t *mysh);
bool checker(mysh_t *mysh);
void execute_command(mysh_t *mysh, env_t *env);
void execute_command_2(mysh_t *mysh, env_t *env, int i);
void separator(mysh_t *mysh, env_t *env);
void simple_redirection_right(mysh_t *mysh, env_t *env);
void simple_redirection_left(mysh_t *mysh, env_t *env);
void double_redirection_right(mysh_t *mysh, env_t *env);
void double_redirection_left(mysh_t *mysh, env_t *env);
void pipe_redirection(mysh_t *mysh, env_t *env);
void pipe_1(mysh_t *mysh, env_t *env);

#endif /* MINISHELL */
