#______________ FILES ______________#

FILES	=	main.c

#______________ NAMES ______________#

NAME		=	cub3D

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -lm

OBJS		=	$(FILES:.c=.o)

MLX_DIR		= minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11
MLX_URL	=	https://github.com/42Paris/minilibx-linux.git
INCLUDES	= -I. -I$(MLX_DIR) -I$(LIB_DIR)

LIB_DIR	= 	lib
LIBFT		= $(LIB_DIR)/lib.a

YELLOW		=	\033[0;33m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

#______________ RULES ______________#

all			:	$(MLX_DIR) $(NAME)

$(MLX_DIR)	:
	@git clone $(MLX_URL) $(MLX_DIR)

$(NAME)		:	$(OBJS)
	@make -C $(LIB_DIR)
	@printf "$(YELLOW)compiling Minilibx$(RESET)\n"
	@make -C $(MLX_DIR) --no-print-directory
	@printf "$(GREEN)Minilibx compiled\n$(YELLOW)compiling cub3D$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -no-pie -o $(NAME)
	@printf "$(GREEN)cub3D compiled$(RESET)\n"

%.o		: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean	: clean
	@rm -f $(OBJS)
	@printf "$(GREEN)objs cleaned$(RESET)\n"
	@make fclean -C $(LIB_DIR) --no-print-directory

fclean	: clean
	@rm -rf $(MLX_DIR)
	@printf "$(RED)Minilibx erased$(RESET)\n"
	@rm -f $(NAME)
	@printf "$(RED)cub3D erased$(RESET)\n"

re		: fclean all