# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrichard <mrichard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 16:00:34 by mrichard          #+#    #+#              #
#    Updated: 2023/02/20 19:21:00 by mrichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror -I./includes
RM = rm -rf
NAME = push_swap
LIBFT = ./libft/libft.a

SRCS = src/push_swap.c src/utils.c src/check_argv.c src/instructions_a.c src/instructions_b.c\
		src/tiny_sort.c src/starting.c src/stacks.c

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