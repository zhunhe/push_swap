# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:09:06 by juhur             #+#    #+#              #
#    Updated: 2022/03/06 22:12:04 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./include
HEADER = $(INC_DIR)/push_swap.h

SRC_DIR = ./src
SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
	push_swap.c \
	utils.c \
	to_integer.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	init.c \
	lis.c \
	quit.c \
	split.c \
	a_to_b.c \
	b_to_a.c \
	utils2.c \
)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I./$(INC_DIR) -c $< -o $@

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -I./$(INC_DIR) -o $@

.PHONY : all, clean, fclean, re