/*
** EPITECH PROJECT, 2021
** Day06 Task06
** File description:
** Reproduce the behavior of the my_strcmp function
*/

#include "../include/lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    if (!s1 || !s2)
        return -1;
    for (;s1[i] == s2[j] && s1[i] != '\0'; i++, j++);
    if (s1[i] != s2[j]) {
        if (s1[i] > s2[j])
            return 1;
        else if (s1[i] < s2[j])
            return -1;
        else
            return 0;
    }
    return 0;
}
