# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 14:48:16 by neda-sil          #+#    #+#              #
#    Updated: 2026/07/10 12:10:16 by malaimo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#______________ FILES ______________#

FILES	=	libft/ft_atoi					\
			libft/ft_bzero					\
			libft/ft_calloc					\
			libft/ft_itoa					\
			libft/ft_split					\
			libft/ft_isalnum				\
			libft/ft_isalpha				\
			libft/ft_isascii				\
			libft/ft_isdigit				\
			libft/ft_isprint				\
			libft/ft_isspace				\
			libft/ft_memchr					\
			libft/ft_memcmp					\
			libft/ft_memcpy					\
			libft/ft_memmove				\
			libft/ft_memset					\
			libft/ft_putchar_fd				\
			libft/ft_putendl_fd				\
			libft/ft_putnbr_fd				\
			libft/ft_putstr_fd				\
			libft/ft_strchr					\
			libft/ft_strdup					\
			libft/ft_striteri				\
			libft/ft_strjoin				\
			libft/ft_strlcat				\
			libft/ft_strlcpy				\
			libft/ft_strlen					\
			libft/ft_strmapi				\
			libft/ft_strncmp				\
			libft/ft_strnstr				\
			libft/ft_strrchr				\
			libft/ft_strtrim				\
			libft/ft_substr					\
			libft/ft_tolower				\
			libft/ft_toupper				\
			ftprintf/util/find_type			\
			ftprintf/util/ft_put			\
			ftprintf/src/ft_printf			\
			ftprintf/util/ft_unsigned_itoa	\
	  		ftprintf/util/hexa				\
	  		ftprintf/util/print_adress		\
			gnl/get_next_line				\
			gnl/get_next_line_utils			\
			libft/is_there					\
			libft/ft_splitlen

#______________ NAMES ______________#

NAME	=	lib.a
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra
CF		=	$(addsuffix .c, $(FILES))
OF		=	$(addsuffix .o, $(FILES))
YELLOW	=	\033[0;33m
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BROWN	=	\033[38;5;130m
RESET	=	\033[0m

#______________ RULES ______________#

all			:	compiletxt $(NAME)	
	@printf "$(GREEN)LIB COMPILED$(RESET)\n"

compiletxt	:
	@printf "$(YELLOW)compiling libft$(RESET)\n"

$(NAME)		:	$(OF)
	@ar -rcs $@ $?

%.o			:	%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean		:
	@rm -f $(OF)
	@printf "$(GREEN)lib cleaned$(RESET)\n"

fclean		:	clean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) erased$(RESET)\n"

burger		:
	@printf "$(YELLOW)--BREAD--\n"
	@printf "$(RED)--TOMATO-\n"
	@printf "$(GREEN)--SALAD--\n"
	@printf "$(BROWN)--STEAK--\n"
	@printf "$(YELLOW)--BREAD--$(RESET)\n"

re			:	fclean all

.PHONY		:	all clean fclean re