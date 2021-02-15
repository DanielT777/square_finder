/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** main bsq
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

int main(int argc, char **argv)
{
    error_t err;
    if (argc != 2)
        return (84);
    if (readfile(argv[1], &err) == 84)
        return (84);
    return (0);
}

char readfile(char const *filepath, error_t *err)
{
    int i = 0;
    int line = 0;
    int x = 0;
    int fd = fs_open_file(filepath, err);

    if (fd < 0)
        return (84);
    struct stat sb;
    stat(filepath, &sb);
    char *array = malloc(sizeof(char) * (sb.st_size + 2));
    read(fd, array, sb.st_size);
    if (checkempty(array) == 84)
        return (84);
    array[sb.st_size + 1] = '\0';
    line = my_getnbr_bsq(array, err);
    if (checkmap(array, err, line) == 84 ||
    checksize(array, line, sb.st_size, err) == 84)
        return (84);
    x = findx(array, line, sb.st_size);
    mem_alloc_2d_array (array, line, x, my_strlen_bsq(array));
}

int checksize(char *str, int line, int size, error_t *err)
{
    int i = err->strlenint+1;
    int comparex = findx(str, line, size);
    int z = 0;
    int max = 0;
    int j = 0;
    for (; str[i] != '\0'; i++) {
        for (;str[i] != '\n'; i++) {
            z++;
        }
        if (z != comparex)
            return (84);
        else
            z = 0;
    }
}

int checkempty(char *str)
{
    if (str[0] == '\0') {
        return (84);
    }
}

int checkmap(char *str, error_t *err, int line)
{
    int i = err->strlenint;
    int j = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != 'o' && str[i] != '\n'
        && str[i] != '\0') {
            return (84);
        }
        if (str[i] == '\n')
            j++;
    }
    if (j != my_getnbr_bsq(str, err)+1)
        return (84);
}