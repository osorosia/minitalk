# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 01:31:51 by rnishimo          #+#    #+#              #
#    Updated: 2022/02/05 01:43:20 by rnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
CLIENT = client
SERVER = server
LIBFT = ./libft/libft.a
# CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror -g

SRCS_CLIENT = \
./mandatory/client.c \
./mandatory/utils.c

SRCS_SERVER = \
./mandatory/server.c \
./mandatory/utils.c

SRCS_B_CLIENT = \
./bonus/client_bonus.c \
./bonus/utils_bonus.c
SRCS_B_SERVER = \
./bonus/server_bonus.c \
./bonus/utils_bonus.c

ifeq ($(findstring bonus,$(MAKECMDGOALS)), bonus)
SRCS_C = $(SRCS_B_CLIENT)
SRCS_S = $(SRCS_B_SERVER)
HEADER = ./bonus/minitalk_bonus.h
else
SRCS_C = $(SRCS_CLIENT)
SRCS_S = $(SRCS_SERVER)
HEADER = ./mandatory/minitalk.h
endif
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

ifeq ($(findstring debug, $(MAKECMDGOALS)), debug)
DEBUG = -D DEBUG=1
endif

.PHONY: all
all: $(CLIENT) $(SERVER)

$(NAME): all

$(CLIENT): $(OBJS_C) $(HEADER) $(LIBFT)
	gcc $(CFLAGS) $(DEBUG) -o $@ $(OBJS_C) $(LIBFT)

$(SERVER): $(OBJS_S) $(HEADER) $(LIBFT)
	gcc $(CFLAGS) $(DEBUG) -o $@ $(OBJS_S) $(LIBFT)

%.o: %.c
	gcc $(CFLAGS) $(DEBUG) -c -o $@ $<

$(LIBFT):
	make -C ./libft

.PHONY: bonus
\bonus: all

.PHONY: clean
clean:
	rm -f $(SRCS_CLIENT:.c=.o)
	rm -f $(SRCS_SERVER:.c=.o)
	rm -f $(SRCS_B_CLIENT:.c=.o)
	rm -f $(SRCS_B_SERVER:.c=.o)
	
.PHONY: fclean
fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)

.PHONY: re
re: fclean all

# -------------------------------------------------------------

.PHONY: norm
norm:
	norminette | grep Error | cat

.PHONY: debug
debug: re

.PHONY: submit
submit:
	rm -f ./libft/get_next_line.c
	cat ./libft/Makefile | grep -v get_next_line > ./libft/tmp
	cat ./libft/tmp > ./libft/Makefile
