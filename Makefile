##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## desc
##

cc	=	gcc

SRC	=	sources/main.c		\
		sources/help.c		\
		sources/strace.c

CFLAGS	=	-I./include/ -g -W -Wall

OBJ	=	$(SRC:.c=.o)

NAME	=	strace


all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME)	$(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

exe:
	gcc $(OBJ) -o $(NAME)

re:	fclean all
