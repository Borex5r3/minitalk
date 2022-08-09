# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 12:28:41 by adbaich           #+#    #+#              #
#    Updated: 2022/08/04 12:06:46 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server_bonus.c \
	ft_bzero.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \

SRCC = client_bonus.c \
	ft_atoi.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \

OBJS := $(patsubst %.c,%.o, ${SRCS})
NAME = server
OBJC := $(patsubst %.c,%.o, ${SRCC})
NAMEC = client

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

bonus : ${NAME} ${NAMEC}

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

re: fclean bonus