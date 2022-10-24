# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smontgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:49:18 by smontgen          #+#    #+#              #
#    Updated: 2022/10/24 17:49:19 by smontgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = libftprintf.a

MANDATORY = ft_printf.c\
			ft_printf_utils.c\
			print_hex.c\
			print_unsigned_int.c\
			print_ptr.c\

MANDATORY_SRCS	=	${MANDATORY}

MANDATORY_OBJS	= ${MANDATORY_SRCS:.c=.o}

CFLAGS	= -g -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${MANDATORY_OBJS}
			ar rc ${NAME} ${MANDATORY_OBJS}
			ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${MANDATORY_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
