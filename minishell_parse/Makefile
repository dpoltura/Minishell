# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 11:21:23 by dpoltura          #+#    #+#              #
#    Updated: 2024/04/09 12:06:43 by dpoltura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror -g -lreadline -Wno-unused-command-line-argument

SRCS =	minishell.c \
		ft_strjoin.c \
		split_line.c \
		utils.c \
		free.c \
		check_pipe.c \
		check_chev.c \
		init.c \
		echo.c \
		cd.c

OBJS = $(SRCS:%.c=%.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
