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
#include "my.h"

void convertchartoint(char **mymap, int nb_rows, int nb_cols)
{

    int k = 0;
    int i = 0;
    int j = 0;
    int isthere = 0;
    int **mapint = malloc(sizeof(int *) * (nb_rows + 2));

    for (;mymap[i] != NULL; i++) {
        mapint[i] = malloc(sizeof(int) * (nb_cols + 2));
        for (j = 0; mymap[i][j] != '\n';j++)
            mapint[i][j] = '0';
        j++;
        mapint[i][j] = '\0';
    }
    mapint[i] = NULL;
    fillfirst (mymap, mapint, nb_rows, nb_cols);
}

int fillfirst(char **mymap, int **mapint, int nb_rows, int nb_cols)
{

    int i = 0;
    int j = 0;
        while (i < nb_rows) {
            if (nb_cols == 1 && mymap[i][j] == '.') {
                mymap[i][j] = 'x';
                fillsecond(mymap, mapint, nb_rows, nb_cols);
                return (0);
            }
            if (mymap[i][j] == 'o')
                mapint[i][j] = '0';
            if (mymap[i][j] == '.' )
                mapint[i][j] = '1';
            i++;
        }
    fillsecond(mymap, mapint, nb_rows, nb_cols);
}

void fillsecond(char **mymap, int **mapint, int nb_rows, int nb_cols)
{
    int i = 0;
    int j = 0;

    while (j < nb_cols) {
        if (nb_rows == 1) {
            printmyoneline(mymap, nb_rows, nb_cols);
            return (0);
        }
        if (mymap[i][j] == 'o')
            mapint[i][j] = '0';
        if (mymap[i][j] == '.' )
            mapint[i][j] = '1';
            j++;
        }
    findbigsquare(mymap, mapint, nb_rows, nb_cols);
}

void printmyoneline(char **mymap, int nb_rows, int nb_cols)
{
    int i = 0;
    int j = 0;
    for (; j < nb_cols; j++) {
        if (mymap[0][j] == '.' && i == 0) {
            mymap[0][j] = 'x';
            i++;
        }
    }
    for (int z = 0; mymap[z] != NULL; z++)
        write(1, mymap[z], nb_cols - 1);
}

char **mem_alloc_2d_array(char *array, int nb_rows, int nb_cols, int first_line)
{
    char **mymap = convertin2darray(array, nb_rows, nb_cols, first_line);
    convertchartoint (mymap, nb_rows, nb_cols);
    return (mymap);
}