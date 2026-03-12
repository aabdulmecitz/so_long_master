/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:38 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/27 17:08:39 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_object(t_ctx *ctx, int x, int y);
void	ft_player_move(int keycode, t_ctx *ctx);
void	ft_move_dir(t_ctx *ctx, int dx, int dy);
int		key_hook(int keycode, t_ctx *ctx);

void	ft_player_move(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		ctx->player_dir = BACK;
		ft_move_dir(ctx, 0, -1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		ctx->player_dir = FRONT;
		ft_move_dir(ctx, 0, 1);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		ctx->player_dir = LEFT;
		ft_move_dir(ctx, -1, 0);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		ctx->player_dir = RIGHT;
		ft_move_dir(ctx, 1, 0);
	}
}

void	ft_move_dir(t_ctx *ctx, int dx, int dy)
{
	int	x;
	int	y;

	x = ctx->map.player.x;
	y = ctx->map.player.y;
	if (ctx->map.map_matris[y + dy][x + dx] != WALL
		&& (ctx->map.map_matris[y + dy][x + dx] != MAP_EXIT
		|| ctx->map.coins == 0))
	{
		ft_check_object(ctx, x + dx, y + dy);
		ctx->map.map_matris[y][x] = FLOOR;
		ctx->map.player.x += dx;
		ctx->map.player.y += dy;
		ctx->map.map_matris[y + dy][x + dx] = PLAYER;
		ctx->movements++;
		print_space_line(ctx);
		write_steps(ctx, 32, (ctx->map.rows + 1) * IMG_HEIGHT);
	}
}

void	ft_check_object(t_ctx *ctx, int x, int y)
{
	if (ctx->map.map_matris[y][x] == COINS)
		ctx->map.coins--;
	else if (ctx->map.map_matris[y][x] == MAP_EXIT && ctx->map.coins == 0)
	{
		congrats_msg();
		win_destroy(ctx);
	}
	else if (ctx->map.map_matris[y][x] == STAT_ENEMY
			|| ctx->map.map_matris[y][x] == WANDER_ENEMY)
	{
		failed_msg();
		win_destroy(ctx);
	}
}

int	key_hook(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		win_destroy(ctx);
	ft_player_move(keycode, ctx);
	return (0);
}

void	handler(t_ctx *ctx)
{
	mlx_hook(ctx->win_ptr, KeyPress, KeyPressMask, key_hook, ctx);
	mlx_hook(ctx->win_ptr, DestroyNotify, 0, win_destroy, ctx);
	mlx_hook(ctx->win_ptr, Expose, 0, render_a_frame, ctx);
}
