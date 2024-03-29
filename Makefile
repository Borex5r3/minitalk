# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 23:32:55 by adbaich           #+#    #+#              #
#    Updated: 2022/08/02 12:44:15 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c \
	ft_bzero.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \

SRCC = client.c \
	ft_atoi.c \

OBJS := $(patsubst %.c,%.o, ${SRCS})
NAME = server
OBJC := $(patsubst %.c,%.o, ${SRCC})
NAMEC = client

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all : ${NAME} ${NAMEC}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

${NAMEC}: ${OBJC}
	${CC} ${CFLAGS} ${SRCC} -o ${NAMEC}

clean:
	${RM} ${OBJS} ${OBJC}

fclean: clean
	${RM} ${NAME} ${NAMEC}

re: fclean all