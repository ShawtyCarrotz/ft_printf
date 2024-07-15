# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 13:55:07 by ipais-mo          #+#    #+#              #
#    Updated: 2024/07/02 16:50:29 by ipais-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
FLAGS= -Wall -Wextra -Werror
CC= cc
OBJ= $(SRC:.c=.o)
SRC= ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_signedputnbr_fd.c

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

exec:
	$(CC) $(FLAGS) -g $(SRC) -lbsd
