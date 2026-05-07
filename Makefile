NAME            = so_long
NAME_BONUS      = so_long_bonus

SRCS_DIR        = ./src/
BONUS_SRCS_DIR  = ./bonus/
LIBFT_DIR       = ./lib/libft
MLX_DIR         = ./lib/minilibx-linux

LIBFT_A         = $(LIBFT_DIR)/libft.a
MLX_A           = $(MLX_DIR)/libmlx.a

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
INCLUDES        = -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS            = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd

SRCS = $(addprefix $(SRCS_DIR),\
		main.c parse.c validate.c flood_fill.c \
		game_init.c input.c render.c cleanup.c gc.c gc_utils.c)

BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR),\
		so_long_bonus.c animation_creator.c button_acts.c check_cmd_args.c \
		check_map.c enemy_acts.c enemy_init.c flood_fill.c \
		frame_mount.c free.c free_all.c game_initializer.c \
		get_frame.c get_player_frame.c ig.c map_initializer.c \
		msg.c paint_frame.c write_steps.c)

# include shared GC implementation from src for bonus build
BONUS_SRCS += ./src/gc.c ./src/gc_utils.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_A) $(LIBS) -o $@
	@echo "$(GREEN)$(NAME) successfully compiled!$(DEF_COLOR)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(LIBFT_A) $(LIBS) -o $@
	@echo "$(MAGENTA)$(NAME_BONUS) successfully compiled!$(DEF_COLOR)"

%.o: %.c
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	@echo "$(BLUE)Compiling libft...$(DEF_COLOR)"
	@make -C $(LIBFT_DIR) > /dev/null

$(MLX_A):
	@echo "$(BLUE)Compiling minilibx...$(DEF_COLOR)"
	@make -C $(MLX_DIR) > /dev/null 2>&1

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null
	@make -C $(MLX_DIR) clean > /dev/null
	@echo "$(RED)Object files and libraries cleaned.$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo "$(RED)Binaries removed.$(DEF_COLOR)"

re: fclean all

get_libs:
	@rm -rf $(LIBFT_DIR) $(MLX_DIR)
	@mkdir -p lib
	git clone https://github.com/aabdulmecitz/42-Libft.git $(LIBFT_DIR)
	cd $(LIBFT_DIR) && git checkout lft4solong
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

compile_libs: get_libs
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

run: all
	./$(NAME) ./assets/maps/valid/map1.ber

run_bonus: bonus
	./$(NAME_BONUS) ./assets/maps/valid/bonus/map5.ber

.PHONY: all clean fclean re bonus get_libs compile_libs run run_bonus test_invalid_maps test_valgrind
