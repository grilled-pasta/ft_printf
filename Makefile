# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/16 21:18:17 by alkonsta          #+#    #+#              #
#    Updated: 2026/10/16 21:19:26 by alkonsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = *.c, */*.c

OBJDIR = ./libftprintf
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
