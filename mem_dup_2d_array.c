/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** malloc an 2d array
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    int i = 0;
    char **map = malloc(sizeof(char *) * (nb_rows + 2));

    map[nb_rows] = NULL;

    while (i < nb_rows)
    {
        map[i] = malloc(sizeof(char) * (nb_cols + 2));
        map[i][nb_cols] = '\0';
        i++;
    }
    dupmyarr(arr, nb_rows, nb_cols, map);
    return (map);
}

int findbigsquare(char **mymap, int  **mapint, int nb_rows, int nb_cols)
{
    arrayposition_t array;
    init_struct(&array, mapint, mymap);
    for (array.i; array.i < nb_rows; array.i++) {
        for (array.j = 1; array.j < nb_cols; array.j++) {
            findcondibigsquare(&array, mymap, mapint);
        }
    }
    printmysq(nb_rows, nb_cols, &array);
}

int comparator(int top, int left, int diagleft)
{
        int result = 0;
        if (top <= left && top <= diagleft) {
            result = top;
            return (result + 1);
        } else if (left <= top && left <=  diagleft) {
            result = left;
            return (result + 1);
        } else {
            result = diagleft;
            return (result + 1);
        }
}

void printmymap(arrayposition_t *array, int nb_cols)
{
    for (int z = 0; array->map[z] != NULL; z++)
        write(1, array->map[z], nb_cols + 1);
}

void fillmymap(arrayposition_t *array, int i, int q)
{
    if (i >= array->ipos - (array->maxlenvalue - 48) && i < array->ipos
        && q > array->jpos - (array->maxlenvalue - 48) - 1
        && q < array->jpos)
            array->map[i][q] = 'x';
}