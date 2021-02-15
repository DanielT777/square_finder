/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

typedef struct arrayposition
{
    int i;
    char **map;
    int **mapint;
    int j;
    int comparing;
    int maxlenvalue;
    int ipos;
    int jpos;
    int top;
    int left;
    int diagleft;
    int nb_cols;
    int nb_rows;
} arrayposition_t;

typedef struct error_s
{
    int error;
    int strlenint;
} error_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int fs_open_file (char const *filepath, error_t *err);
int fs_get_number_from_first_line(char const *filepath);
int findx(char const *array, int size, int line);
char readfile(char const *filepath, error_t *err);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int findbigsquare(char **mymap, int  **mapint, int nb_rows, int nb_cols);
int comparator (int top, int left, int diagleft);
void convertchartoint(char **mymap, int nb_rows, int nb_cols);
int fillfirst(char **mymap, int **mapint, int nb_rows, int nb_cols);
char **mem_alloc_2d_array(char *array, int nb_rows,
int nb_cols, int len_first_line);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
void dupmyarr(char **arr, int nb_rows, int nb_cols, char **map);
int my_strlen_bsq(char const *str);
int my_getnbr_bsq(char const *str, error_t *err);
void fillmymap(arrayposition_t *array, int i, int q);
int printmysq(int nb_rows, int nb_cols, arrayposition_t *array);
void init_struct(arrayposition_t *array, int **mapint, char **map);
void printmymap(arrayposition_t *array, int nb_cols);
int findbigsquare(char **mymap, int  **mapint, int nb_rows, int nb_cols);
void findcondibigsquare(arrayposition_t *array, char **map, int **mapint);
char **convertin2darray(char *array, int nb_rows, int nb_cols, int firstline);
int checksize(char *str, int line, int size, error_t *err);
void fillsecond(char **mymap, int **mapint, int nb_rows, int nb_cols);
void printmyoneline(char **mymap, int nb_rows, int nb_cols);
void fileempty(char *str, error_t *err);
int checkempty(char *str);
int checkmap(char *str, error_t *err, int line);
#endif /* !MY_H_ */
