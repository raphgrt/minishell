##
## EPITECH PROJECT, 2023
## My str_dup.h
## File description:
## my_MakeFile
##

TARGET		=	libmystr.a
CC			=	gcc

SRCS	=	my_putstr.c 		my_strcapitalize.c 		my_strncat.c		\
			concat_params.c		my_revstr.c				my_strcat.c			\
			my_strncmp.c		my_char_isan.c			my_str_isalpha.c	\
			my_strcmp.c			my_strncpy.c			my_char_isnum.c		\
			my_str_islower.c	my_strcpy.c				my_strstr.c			\
								my_str_isnum.c			my_strdup.c			\
			my_strupcase.c		my_str_isprintable.c	my_is_prime.c		\
			my_swap.c			my_put_nbr.c			my_str_isupper.c	\
			my_strlen.c			my_str_to_word_array.c	my_putchar.c		\
			my_strlowcase.c		str_wordsize.c			my_char_issep.c		\
			str_count_words.c	is_in_string.c			free_word_array.c	\
			my_puterr.c			my_array_length.c		my_getnbr.c			\
			my_str_to_word_array_sep.c

OBJS = $(SRCS:.c=.o)

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} -c ${OBJS}
	ar rc ${TARGET} ${OBJS}

clean:
	rm -fr ${OBJS}

fclean: clean
	rm -fr ${TARGET}

re: fclean all
