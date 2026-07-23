#______________ FILES ______________#

FILES		=	src/main.c						\
				src/exit.c						\
				src/gc/ft_calloc_gc.c			\
				src/gc/ft_delone_gc.c			\
				src/gc/ft_error_gc.c			\
				src/gc/ft_free_all_gc.c			\
				src/gc/ft_free_tab_gc.c			\
				src/gc/ft_gnl_gc.c				\
				src/gc/ft_itoa_gc.c				\
				src/gc/ft_join_one_gc.c			\
				src/gc/ft_lstadd_gc.c			\
				src/gc/ft_malloc_gc.c			\
				src/gc/ft_renew_gc.c			\
				src/gc/ft_renew_one_gc.c		\
				src/gc/ft_scan_gc.c				\
				src/gc/ft_split_gc.c			\
				src/gc/ft_strdup_gc.c			\
				src/gc/ft_strjoin_gc.c			\
				src/gc/ft_substr_gc.c			\
				src/parsing/parse_first_lines.c	\
				src/parsing/parse_map.c			\
				src/parsing/parsing_utils.c		\
				src/parsing/parsing.c			\
				src/mlx/init_mlx.c				\
				src/calculs/raycasting.c

#______________ NAMES ______________#

NAME		=	cub3D

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -lm

OBJS        =   $(FILES:src/%.c=$(OBJ_DIR)%.o)
OBJ_DIR		=	objs/
SRC_DIR		=	src/

MLX_DIR		=	minilibx-linux
MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -lXext -lX11
MLX_URL		=	https://github.com/42Paris/minilibx-linux.git
INCLUDES	=	-I. -I$(MLX_DIR) -I$(LIB_DIR)

LIB_DIR		=	lib
LIBFT		=	$(LIB_DIR)/lib.a

YELLOW		=	\033[0;33m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

#______________ RULES ______________#

all			:	$(NAME)

mlx			:
	@git clone $(MLX_URL) $(MLX_DIR)

$(MLX_DIR)	:
	@git clone $(MLX_URL) $(MLX_DIR)

$(NAME)		:	$(MLX_DIR) $(OBJS)
	@make -C $(LIB_DIR)
	@printf "$(YELLOW)compiling Minilibx$(RESET)\n"
	@make -C $(MLX_DIR) --no-print-directory
	@printf "$(GREEN)Minilibx compiled\n$(YELLOW)compiling cub3D$(RESET)\n"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -no-pie -o $(NAME)
	@printf "$(GREEN)cub3D compiled$(RESET)\n"

$(OBJ_DIR)%.o	:	src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean		:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@printf "$(GREEN)objs cleaned$(RESET)\n"
	@make fclean -C $(LIB_DIR) --no-print-directory

fclean		:	clean
	@rm -rf $(MLX_DIR)
	@printf "$(RED)Minilibx erased$(RESET)\n"
	@rm -f $(NAME)
	@printf "$(RED)cub3D erased$(RESET)\n"

re			:	fclean all

.PHONY		:	all clean fclean re mlx