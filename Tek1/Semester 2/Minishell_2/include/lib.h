/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF
    #define MY_PRINTF

    #include <stdarg.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <assert.h>
    #include <string.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <time.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <signal.h>
    #include <ucontext.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <sys/types.h>

// !PRINTF
int my_printf(char *str, ...);
void check_arg(char *str, va_list ap, int i);

// !LIB
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_printf(char *str, ...);
int my_intlen(int nb);
int my_strcmp(char const *s1, char const *s2);
char *my_itoa(int nb);
char *my_strndup(char *str, int nb);
int my_str_isupper(char const *str);
char *my_strupcase(char *str);
char *my_strdup(char const *src);
int print_spaces(char *str);
char **my_str_to_word_array(char *str, char *sep);
int nb_arg(char *str, char *sep);
char **alloc_2d_array(char *str, char *sep);
int size_words(int n, char *str);
char *my_strcat(char *dest, char const *src);
int my_str_isalpha(char const *str);
int str_isalpha(char *str);
int str_isnum(char *str);
int str_non_alpha(char *str);
int is_num(char c);
int is_alpha(char c);
int is_non_alpha(char c);
int check_non_alpha(char *str);
char *clear_string(char *str);

#endif /* MY_PRINTF */
