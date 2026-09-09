# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araissa- <araissa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/20 16:56:38 by araissa-          #+#    #+#              #
#    Updated: 2026/07/20 16:56:38 by araissa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -Iincludes -Ilibft
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC = srcs/main.c \
	srcs/parsing.c \
	srcs/stack_utils.c \
	srcs/utils.c \
	srcs/analysis.c \
	srcs/bench_utils.c \
	srcs/bench_print.c \
	srcs/bench_strategy.c \
	srcs/main_utils.c \
	operations/ft_rerotate.c\
	operations/ft_rotate.c\
	operations/ft_swap.c\
	operations/ft_push.c\
	sort/chunk_sort.c\
	sort/chunk_utils.c\
	sort/selection_sort.c\
	sort/sort_dispatch.c\
	sort/sort_base.c\
	sort/radix_sort.c\
	sort/adaptive_sort.c

OBJ = $(SRC:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME):  $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
		rm -f $(OBJ)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
