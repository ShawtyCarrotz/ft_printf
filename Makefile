# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 13:55:07 by ipais-mo          #+#    #+#              #
#    Updated: 2024/06/22 16:52:06 by ipais-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
FLAGS= -Wall -Wextra -Werror
CC= cc
OBJ= $(SRC:.c=.o)
SRC= ft_printf.c

RM= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
