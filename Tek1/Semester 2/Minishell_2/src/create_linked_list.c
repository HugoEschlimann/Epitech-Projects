/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** linked_list
*/

#include "minishell.h"
#include "lib.h"

env_t *create_linked_list(char **str)
{
    env_t *node = NULL;
    int count = 0;
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    if (str == NULL)
        return NULL;
    for (; str[i] != NULL; i++) {
        for (j = 0, count = 0; str[i][j] != '='; j++)
            count += 1;
        tmp = my_strndup(str[i], count);
        add_node_at_back(&node, tmp, str[i] + count + 1);
    }
    return node;
}

env_t *add_node_at_back(env_t **node, char *key, char *value)
{
    env_t *new_node = malloc(sizeof(env_t));
    env_t *last_node = NULL;
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if ((*node) == NULL)
        (*node) = new_node;
    else {
        last_node = (*node);
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
    }
    return new_node;
}

void print_list_key(env_t *node)
{
    while (node != NULL) {
        my_printf("%s -> ", node->key);
        node = node->next;
    }
}

void print_list_value(env_t *node)
{
    while (node != NULL) {
        my_printf("%s -> ", node->value);
        node = node->next;
    }
}
