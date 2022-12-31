# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:09:06 by juhur             #+#    #+#              #
#    Updated: 2022/12/31 15:52:21 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./include
M_HEADER = $(INC_DIR)/push_swap.h
B_HEADER = $(INC_DIR)/push_swap_bonus.h

SRC_DIR = ./src

M_SRC_DIR = $(SRC_DIR)/mandatory
M_SRCS = $(addprefix $(M_SRC_DIR)/, \
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

B_SRC_DIR = $(SRC_DIR)/bonus
B_SRCS = $(addprefix $(B_SRC_DIR)/, \
	main_bonus.c \
)

M_OBJS = $(M_SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	@rm -f $(M_OBJS) $(B_OBJS)

.PHONY : fclean
fclean : clean
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@rm -f bonus

.PHONY : re
re : fclean all

%.o : %.c
	@$(CC) $(CFLAGS) -I./$(INC_DIR) -c $< -o $@

$(NAME) : $(M_OBJS) $(M_HEADER)
	@$(CC) $(CFLAGS) $(M_OBJS) -I./$(INC_DIR) -o $@

bonus : $(B_OBJS) $(B_HEADER)
	@$(CC) $(CFLAGS) $(B_OBJS) -I.$(INC_DIR) -o $(CHECKER)
	@touch bonus
