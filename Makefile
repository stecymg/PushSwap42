# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smontgen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:00:05 by smontgen          #+#    #+#              #
#    Updated: 2022/10/21 15:00:10 by smontgen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -rf

NAME = push_swap

MANDATORY = parsing.c \
			main.c \
			operation.c \
			utils.c \
			init_list.c \
			utils2.c \
			sort_three.c \
			init_list2.c \
			sort_all.c \
			sort_all_utils.c \
			sort_all_utils2.c \
			ft_split.c \
			ft_strjoin.c \
			sort_five.c \

MANDATORY_SRCS	=	${MANDATORY}

MANDATORY_OBJS	= ${MANDATORY_SRCS:.c=.o}

CFLAGS	= -g -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${MANDATORY_OBJS}
		make -C printf
		${CC} ${CFLAGS} ${MANDATORY_SRCS} printf/libftprintf.a -o ${NAME}

all: ${NAME}

clean:
	${RM} ${MANDATORY_OBJS}

fclean: clean
	make fclean -C printf
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
