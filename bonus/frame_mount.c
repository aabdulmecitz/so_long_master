/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_a_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:59 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:09:00 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player(t_ctx *ctx, int x, int y);

int	render_a_frame(t_ctx *ctx)
{
	int	x;
	int	y;

	handle_enemies(ctx);
	y = 0;
	while (y < ctx->map.rows + 2)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			if (y < ctx->map.rows)
				put_texture(ctx, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	print_space_line(t_ctx *ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->map.rows + 2)
	{
		x = 0;
		while (x < ctx->map.columns)
		{
			if (!(y < ctx->map.rows))
			{
				mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
ctx->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	put_texture(t_ctx *ctx, int x, int y)
{
	if (ctx->map.map_matris[y][x] == WALL)
		paint_wall_with_animation(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == FLOOR)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->floor->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (ctx->map.map_matris[y][x] == COINS)
		paint_coin_with_animation(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == WANDER_ENEMY)
		paint_enemy_x_with_animation(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == STAT_ENEMY)
		paint_toxic_with_animation(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == PLAYER)
		paint_player_with_animation(ctx, x, y);
	else if (ctx->map.map_matris[y][x] == MAP_EXIT)
		paint_door(ctx, x, y);
}
