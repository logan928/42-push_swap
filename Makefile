# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 12:15:59 by uwettasi          #+#    #+#              #
#    Updated: 2025/04/28 12:44:15 by uwettasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a

SRC = \
	algo_5.c	\
	cll_find_min_max.c	\
	cll_shrink.c	\
	populate_b.c	\
	rotate_counts.c	\
	algo_operations.c	\
	cll_grow.c	\
	ft_printf.c	\
	populate_b_updates.c	\
	secondalgo.c	\
	cll_comparisons.c	\
	cll_operations.c	\
	list_op_rotations.c	\
	push_swap.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "push_swap.a created!"

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $< -> $@"

clean:
	@rm -f $(OBJ)
	@echo "objects cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "library cleaned!"

re: fclean all

.PHONY: all clean fclean re



