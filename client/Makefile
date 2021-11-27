# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 00:09:37 by rnishimo          #+#    #+#              #
#    Updated: 2021/11/27 05:30:59 by rnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SRCS = client.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
