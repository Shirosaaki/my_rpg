/*
** EPITECH PROJECT, 2024
** str
** File description:
** str
*/
#include "../include/my.h"

char **my_str_to_word_array(char *str, char separator)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **array = malloc((strlen(str) + 1) * sizeof(char *));

    array[0] = malloc((strlen(str) + 1) * sizeof(char));
    for (i = 0; i <= strlen(str); i++) {
        if (str[i] == separator || str[i] == '\0') {
            array[j][k] = '\0';
            j++;
            k = 0;
            array[j] = malloc((strlen(str) + 1) * sizeof(char));
        } else {
            array[j][k] = str[i];
            k++;
        }
    }
    array[j] = NULL;
    return array;
}
