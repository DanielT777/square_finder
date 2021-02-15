/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** fill an array
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

void dupmyarr(char **arr, int nb_rows, int nb_cols, char **map)
{
    int i = 0;
    int q = 0;

    while (i < nb_rows) {
        while (q < nb_cols) {
            map[i][q] = arr[i][q];
            q++;
            map[i][q] = '\n';
        }
        q = 0;
        i++;
    }
}