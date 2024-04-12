# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 13:10:15 by gorodrig          #+#    #+#              #
#    Updated: 2024/04/07 16:24:24 by gorodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

SOURCES = ft_hex_utils.c \
						ft_printf.c \
						ft_ptr_utils.c \
						ft_putchar.c \
						ft_putnbr_utils.c \
						ft_putstr.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)	
	@$(AR) $(NAME) $(OBJECTS)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@$(RM) $(OBJECTS)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
