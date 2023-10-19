# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 12:13:19 by zedr0             #+#    #+#              #
#    Updated: 2023/10/19 12:48:46 by zedr0            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC		= ft_printf.c
OBJS	= $(SRC:.c=.o)

MAKE	= make -C 
CFLAGS	= -Wall -Wextra -Werror
INC		= -I .
CC		= cc
RM		= rm -f
AR		= ar rcs

all: $(NAME)

.o:.c:
	$(CC) $(CFLAGS) $(INC) -c $<

$(NAME): $(OBJS)
	$(MAKE) $(LIBFT_PATH) all
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re