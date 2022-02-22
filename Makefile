##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile lib
##

CFLAGS	=  	-Wno-nullability-completeness

SRC 	=	$(shell find . -name '*.c')

OBJ 	=	$(SRC:.c=.o)

NAME	= 	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	find . -name "*.o" -delete
	find . -name "*~" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all
