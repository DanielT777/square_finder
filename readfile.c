/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** read from a file
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

int my_getnbr_bsq(char const *str, error_t *err)
{
    int i = 0;
    int nb1 = 0;
    int minus = 1;

    while (str[i] != '\n') {
        if (str[i] >= 48 && str[i] <= 57) {
            nb1 = nb1 * 10 + (str[i] - 48);
        } else if (str[i] == 45) {
            minus = minus*-1;
            } else {
                nb1 = nb1 * minus;
            }
        i++;
    }
    err->strlenint = i;
    return (nb1);
}

int my_strlen_bsq(char const *str)
{
    int i;
    int q = 0;
    i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return (i);
}