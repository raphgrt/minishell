##
## EPITECH PROJECT, 2023
## B-PSU-100-LYN-1-1-my_navy
## File description:
## Makefile
##

TARGET		=	mysh
CC			=	gcc
CFLAGS		=
LDFLAGS		=	-Llib/my_string_lib/ -lmystr
BUILTINS	=	src/builtin

SRCS	=	src/main.c						src/minishell.c				\
			src/child.c						src/get_env.c				\
			${BUILTINS}/my_setenv.c										\
			${BUILTINS}/builtins.c			${BUILTINS}/my_cd.c			\
			${BUILTINS}/my_exit.c			${BUILTINS}/my_env.c		\
			${BUILTINS}/my_unsetenv.c

OBJS	=	$(SRCS:.c=.o)

all: ${TARGET}

${TARGET}: ${OBJS}
	@make -C lib/my_string_lib
	${CC} -o ${TARGET} ${OBJS} ${LDFLAGS}

clean:
	rm -fr ${OBJS}
	make clean -C lib/my_string_lib

fclean: clean
	rm -fr ${TARGET}
	make fclean -C lib/my_string_lib

re:	fclean all

.PHONY: clean fclean re
