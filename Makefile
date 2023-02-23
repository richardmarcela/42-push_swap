# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcela <marcela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 16:00:34 by mrichard          #+#    #+#              #
#    Updated: 2023/02/23 17:10:00 by marcela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror -I include
RM = rm -rf
NAME = push_swap
LIBFT = ./libft/libft.a

SRCS = src/push_swap.c src/utils.c src/check_argv.c src/stacks.c src/starting.c\
		src/tiny_sort.c src/position.c src/sort.c src/cost.c src/moves.c\
		src/instructions_a.c src/instructions_b.c src/instructions_both.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		echo "Building..."
		$(MAKE) --no-print-directory -C ./libft
		$(CC) $(OBJS) $(LIBFT) -o push_swap

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: