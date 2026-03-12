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
		game_init.c input.c render.c cleanup.c)

BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR),\
		so_long_bonus.c animation_creator.c button_acts.c check_cmd_args.c \
		check_map.c enemy_acts.c enemy_init.c flood_fill.c \
		frame_mount.c free.c free_all.c game_initializer.c \
		get_frame.c get_player_frame.c ig.c map_initializer.c \
		msg.c paint_frame.c write_steps.c)

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(LIBFT_A) $(LIBS) -o $@
	@echo "$(NAME) built."

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_SRCS) $(LIBFT_A) $(LIBS) -o $@
	@echo "$(NAME_BONUS) built."

$(LIBFT_A):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(MLX_A):
	@echo "Compiling mlx..."
	@make -C $(MLX_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "Cleaned libraries."

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "Removed binaries."

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

INVALID_MAPS_DIR = ./assets/maps/invalid/
INVALID_MAPS = $(wildcard $(INVALID_MAPS_DIR)*.ber)

test_invalid_maps: all bonus
	@echo "\033[1;34m=== Testing invalid maps with $(NAME) ===\033[0m"
	@for map in $(INVALID_MAPS); do \
		echo "\n$(NAME) $$map \nTesting $$map with $(NAME):"; \
		./$(NAME) $$map || echo "Error handled correctly for $$map"; \
	done
	@echo "\033[1;34m=== Testing invalid maps with $(NAME_BONUS) ===\033[0m"
	@for map in $(INVALID_MAPS); do \
		echo "\nTesting $$map with $(NAME_BONUS):"; \
		./$(NAME_BONUS) $$map || echo "Error handled correctly for $$map"; \
	done

test_valgrind: all bonus
	@echo "\033[1;34m=== Testing $(NAME) with Valgrind ===\033[0m"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) ./assets/maps/valid/platform1.ber
	@echo "\033[1;34m=== Testing $(NAME_BONUS) with Valgrind ===\033[0m"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_BONUS) ./assets/maps/valid/bonus/platform_bonus1.ber

.PHONY: all clean fclean re bonus get_libs compile_libs run run_bonus test_invalid_maps test_valgrind
