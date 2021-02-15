/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Copy an array in another array and malloc it
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"

char **convertin2darray(char *array, int nb_rows, int nb_cols, int firstline)
{
    int i = 0;
    int j = 0;
    int a = firstline + 1;
    char **map = malloc(sizeof(char *) * (nb_rows + 3));
    while (i < nb_rows) {
        map[i] = malloc(sizeof(char) * (nb_cols + 3));
        j = 0;
            while (array[a] != '\n') {
                map[i][j] = array[a];
                a++;
                j++;
        }
        map[i][j] = '\n';
        j++;
        map[i][j] = '\0';
        a++;
        i++;
    }
    map[i] = NULL;
    return (map);
}

void init_struct(arrayposition_t *array, int **mapint, char **map)
{
    array->i = 1;
    array->j = 1;
    array->comparing = 0;
    array->maxlenvalue = 0;
    array->ipos = 0;
    array->jpos = 0;
    array->top = mapint[array->i-1][array->j];
    array->left = mapint[array->i][array->j-1];
    array->diagleft = mapint[array->i-1][array->j-1];
    array->map = map;
    array->mapint = mapint;
}

int printmysq(int nb_rows, int nb_cols, arrayposition_t *array)
{

    int i = 0;
    int q = 0;

    while (i < nb_rows) {
        while (q < nb_cols) {
            fillmymap(array, i, q);
            q++;
        }
        q = 0;
        i++;
    }
    printmymap(array, nb_cols);
}

void findwhereputx(arrayposition_t *array)
{
    if (array->maxlenvalue < array->comparing) {
        array->maxlenvalue = array->comparing;
        array->ipos = array->i+1;
        array->jpos = array->j+1;
    }
}

void findcondibigsquare(arrayposition_t *array, char **map, int **mapint)
{
            if (map[array->i][array->j] != 'o'
            && mapint[array->i][array->j] > 1) {
                array->top = mapint[array->i-1][array->j];
                array->left = mapint[array->i][array->j-1];
                array->diagleft = mapint[array->i-1][array->j-1];
            if (array->top > 1 && array->left > 1 && array->diagleft > 1) {
                array->comparing =
                comparator(array->top, array->left, array->diagleft);
                findwhereputx(array);
                array->mapint[array->i][array->j] = array->comparing;
        }
    }
}