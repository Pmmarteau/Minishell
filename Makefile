##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## ...
##

CC	=	gcc

SRC	=	src/main.c	\
		src/utils.c	\
		src/utils2.c	\
		src/my_shell.c	\
		src/check_command.c	\
		src/get_command.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	+=	-Wall -Wextra -g

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
