# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 23:32:55 by adbaich           #+#    #+#              #
#    Updated: 2022/02/09 23:46:56 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c \
	ft_bzero.c \

SRCC = client.c \
	ft_atoi.c \

NAME = server

NAMEC = client

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all : ${NAME} ${NAMEC}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

${NAMEC}:
	${CC} ${CFLAGS} ${SRCC} -o ${NAMEC}

clean:
	${RM} ${NAME} ${NAMEC}

fclean: clean

re: fclean all