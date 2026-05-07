/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:33:15 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 04:01:24 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gc_node	t_gc_node;

struct	s_gc_node
{
	void		*ptr;
	t_gc_node	*next;
};

typedef struct s_garbage_collector
{
	t_gc_node	*head;
	int			count;
}	t_gc;

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

# define IMG_WIDTH 32
# define IMG_HEIGHT 32

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define WALL_XPM "assets/sprites/wall/wall.xpm"
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/coin/coin1.xpm"
# define PLAYER_XPM "assets/sprites/player/front/player17.xpm"
# define EXIT_XPM "assets/sprites/door/dungeon_door.xpm"
# define EXIT_OPEN_XPM "assets/sprites/door/opened_door/opened_door.xpm"

typedef struct s_location
{
	int	x;
	int	y;
}	t_location;

typedef struct s_map
{
	char		**map_matris;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_location	player;
}	t_map;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_ctx
{
	t_gc	gc;
	void	*mlx_ptr;
	void	*win_ptr;
	int		movements;
	int		map_alloc;
	t_map	map;
	t_img	*wall;
	t_img	*floor;
	t_img	*coins;
	t_img	*player;
	t_img	*exit;
	t_img	*exit_open;
}	t_ctx;

void	gc_init(t_gc *gc);
void	gc_add(t_gc *gc, void *ptr);
void	*gc_malloc(t_gc *gc, size_t size);
char	*gc_strdup(t_gc *gc, const char *str);
void	gc_add_string_array(t_gc *gc, char **array);
void	gc_remove(t_gc *gc, void *ptr);
void	gc_free_all(t_gc *gc);

void	check_cmd_args(int argc, char const *argv[], t_ctx *ctx);
void	map_initializer(t_ctx *ctx, char *argv);
void	map_checker(t_ctx *ctx);
void	general_checker(t_ctx *ctx);
void	so_long_init(t_ctx *ctx);
void	ft_init_mlx(t_ctx *ctx);
void	ft_init_sprites(t_ctx *ctx);
void	render_map(t_ctx *ctx);
int		key_hook(int keycode, t_ctx *ctx);
int		win_destroy(t_ctx *ctx);
void	success_exit(t_ctx *ctx);
void	free_double(void *p1, void *p2, void *p3, void *p4);
void	error(char *msg, t_ctx *ctx);
void	free_map_inside(t_map *map);

#endif
