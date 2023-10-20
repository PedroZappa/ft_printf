# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 12:13:19 by zedr0             #+#    #+#              #
#    Updated: 2023/10/20 17:10:38 by zedr0            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

TESTS_PATH	= tests
TESTS		= $(TESTS_PATH)/ftprintf.znet

SRC			= ft_printf.c ft_parse.c ft_print_chars.c
OBJS		= $(SRC:.c=.o)
LIBFT_OBJS	= $(LIBFT_PATH):%.c=%.o)

MAKE		= make -C 
CFLAGS		= -Wall -Wextra -Werror
INC			= -I .
CC			= cc
RM			= rm -f
AR			= ar rcs


all: $(NAME)

.o:.c
	@echo "\nCompiling $<"
	$(CC) $(CFLAGS) $(INC) -c $<

$(NAME): $(OBJS)
	@echo "\nCompiling libft..."
	$(MAKE) $(LIBFT_PATH) extra
	cp $(LIBFT) $(NAME)
	@echo "\nBuilding archive..."
	$(AR) $(NAME) $(OBJS)
	@echo "\n\t\tSUCCESS!"

znet: $(NAME) 
	@echo "\nCompiling znet..."
	$(MAKE) $(TESTS_PATH) all
	cp $(TESTS) $(NAME) 
	@echo "\nBuilding archive..."
	$(AR) $(NAME) $(OBJS) 
	@echo "\n\t\tSUCCESS!"

clean:
	$(MAKE) $(LIBFT_PATH) clean
	$(MAKE) $(TESTS_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(MAKE) $(TESTS_PATH) fclean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
