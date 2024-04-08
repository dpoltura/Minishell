# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 09:53:05 by dpoltura          #+#    #+#              #
#    Updated: 2024/03/25 09:37:50 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Wall -Werror -g -Wno-unused-command-line-argument

SRCS = 	minishell.c \
		init.c \
		free.c \
		ft_split.c \
		input.c \
		utils.c \
		test.c \
		ft_getenv.c \
		ft_readline.c \
		exec.c \
		ft_strjoin.c \
		get_args.c
OBJS = $(SRCS:%.c=%.o)

NAME = minishell

INCLUDES = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
