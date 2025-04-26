# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibarbouc <ibarbouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 22:47:21 by ibarbouc          #+#    #+#              #
#    Updated: 2024/12/18 21:08:14 by ibarbouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wextra -Wall -Werror 

SOURCES = ft_printf.c\
		ft_put.c\
		ft_put2.c\
		

OBJ = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re