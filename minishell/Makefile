# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 17:09:10 by dpoltura          #+#    #+#              #
#    Updated: 2024/06/25 12:49:16 by aduriez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror -g -lreadline -Wno-unused-command-line-argument

SRCS =	minishell_parse.c \
		init_data.c \
		free.c \
		split_input.c \
		utils.c \
		token.c \
		arg_to_cmd.c \
		get_path.c \
		ft_split.c \
		ft_strjoin.c \
		ft_substr.c \
		check_input.c\
		ft_readline.c \
		init_env.c \
		ft_execve.c \
		echo.c \
		quotes.c \
		ft_here_doc.c

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
