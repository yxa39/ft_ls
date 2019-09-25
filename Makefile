# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yxie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/25 09:44:45 by yxie              #+#    #+#              #
#    Updated: 2019/09/25 10:23:06 by yxie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
LFT_FLAGS = -L $(LFT_PATH) -lftprintf

LFT_PATH = libft

SRCS = srcs/*.c

all: $(NAME)

$(NAME):
	@make re -C $(LFT_PATH)
	$(CC) $(CC_FLAGS) $(SRCS)  -o $(NAME) $(LFT_FLAGS)

fclean:
	@rm -f $(NAME)

re: fclean all
