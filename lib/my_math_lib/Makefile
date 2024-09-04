##
## EPITECH PROJECT, 2023
## My str_dup.h
## File description:
## my_MakeFile
##


TARGET		=	libmymaths.a
CC			=	gcc
CXXFLAGS	=	-Wall -Wextra

SRCS	=		my_compute_square_root.c		my_isneg.c				\
				my_sort_int_array.c				my_compute_power_rec.c	\
				my_find_prime_sup.c

OBJS = $(SRCS:.c=.o)

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${CXXFLAGS} -c ${OBJS}
	ar rc ${TARGET} ${OBJS}

clean:
	rm -fr ${OBJS}

fclean: clean
	rm -fr ${TARGET}

re: fclean all
