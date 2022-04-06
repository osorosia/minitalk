# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishimo <rnishimo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 01:31:51 by rnishimo          #+#    #+#              #
#    Updated: 2022/02/05 09:29:43 by rnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g

SRCS_CLIENT = ./client.c
SRCS_SERVER = ./server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

$(NAME): all

$(CLIENT): $(OBJS_CLIENT) $(HEADER) $(LIBFT)
	cc $(CFLAGS) -o $@ $(OBJS_CLIENT) $(LIBFT)

$(SERVER): $(OBJS_SERVER) $(HEADER) $(LIBFT)
	cc $(CFLAGS) -o $@ $(OBJS_SERVER) $(LIBFT)

$(LIBFT):
	make -C ./libft

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

.PHONY: all
all: $(CLIENT) $(SERVER)

.PHONY: bonus
bonus: all

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

.PHONY: submit
submit:
	rm -f ./libft/get_next_line.c
	cat ./libft/Makefile | grep -v get_next_line > ./libft/tmp
	cat ./libft/tmp > ./libft/Makefile
