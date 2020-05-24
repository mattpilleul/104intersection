##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =	src/display.c		\
		src/sphere.c		\
		src/cone.c		\
		src/cylinder.c		\
		lib/my/my_getnbr.c	\
		error/error.c		\
		main.c

OBJ = $(SRC:.c=.o)

NAME = 104intersection

LIBFLAG = gcc -o

CFLAG = -g3 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFLAG) $(NAME) $(OBJ) $(CFLAG) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
