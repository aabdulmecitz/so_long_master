/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:32:43 by aozkaya           #+#    #+#             */
/*   Updated: 2026/03/12 18:32:45 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_mlx(t_ctx *ctx)
{
	ctx->mlx_ptr = mlx_init();
	if (!ctx->mlx_ptr)
		error("Couldn't find mlx pointer.", ctx);
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr,
			ctx->map.columns * IMG_WIDTH,
			ctx->map.rows * IMG_HEIGHT, "so_long");
	if (!ctx->win_ptr)
		error("Couldn't create the Window.", ctx);
}

static void	load_sprite(t_img *sprite, void *mlx, char *path, t_ctx *ctx)
{
	sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->x, &sprite->y);
	if (!sprite->xpm_ptr)
		error("Couldn't lead a sprite. Check assets/sprites paths.", ctx);
}

void	ft_init_sprites(t_ctx *ctx)
{
	ctx->wall = malloc(sizeof(t_img));
	ctx->floor = malloc(sizeof(t_img));
	ctx->coins = malloc(sizeof(t_img));
	ctx->player = malloc(sizeof(t_img));
	ctx->exit = malloc(sizeof(t_img));
	ctx->exit_open = malloc(sizeof(t_img));
	if (!ctx->wall || !ctx->floor || !ctx->coins || !ctx->player || !ctx->exit || !ctx->exit_open)
		error("Sprite memory allocation failed.", ctx);
	load_sprite(ctx->wall, ctx->mlx_ptr, WALL_XPM, ctx);
	load_sprite(ctx->floor, ctx->mlx_ptr, FLOOR_XPM, ctx);
	load_sprite(ctx->coins, ctx->mlx_ptr, COINS_XPM, ctx);
	load_sprite(ctx->player, ctx->mlx_ptr, PLAYER_XPM, ctx);
	load_sprite(ctx->exit, ctx->mlx_ptr, EXIT_XPM, ctx);
	load_sprite(ctx->exit_open, ctx->mlx_ptr, EXIT_OPEN_XPM, ctx);
}

void	so_long_init(t_ctx *ctx)
{
	ctx->map.coins = 0;
	ctx->map.exit = 0;
	ctx->map.players = 0;
	ctx->movements = 0;
	ctx->map_alloc = 0;
	ctx->mlx_ptr = NULL;
	ctx->win_ptr = NULL;
	ctx->wall = NULL;
	ctx->floor = NULL;
	ctx->coins = NULL;
	ctx->player = NULL;
	ctx->exit = NULL;
	ctx->exit_open = NULL;
}
