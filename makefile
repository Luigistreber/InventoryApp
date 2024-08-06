# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luigi_streber <luigi_streber@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 18:42:19 by luigi_streb       #+#    #+#              #
#    Updated: 2024/08/06 18:44:30 by luigi_streb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inventoryapp

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c inventoryutils.c
INCLUDE = inventory.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
