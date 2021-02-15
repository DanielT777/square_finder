/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** open a file in read-only mode
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int fs_open_file(char const *filepath, error_t *err)
{
    int fd = open(filepath, O_RDONLY);
    return (fd);
}