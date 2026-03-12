/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:31:21 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/26 04:49:38 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	paint_coin_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_coin_frame;

	current_coin_frame = NULL;
	current_coin_frame = get_coin_frame(ctx->coins);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
		current_coin_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	paint_wall_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_wall_frame;

	current_wall_frame = NULL;
	current_wall_frame = get_wall_frame(ctx->wall);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
		current_wall_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	paint_toxic_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_toxic_frame;

	current_toxic_frame = NULL;
	current_toxic_frame = get_toxic_frame(ctx->enemy_k);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
		current_toxic_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	paint_enemy_x_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_enemy_x_frame;

	current_enemy_x_frame = NULL;
	if (ctx->enemy->dir == LEFT || ctx->enemy->dir == BACK)
		current_enemy_x_frame = get_enemy_l_frame(ctx->enemy_x_l);
	else if (ctx->enemy->dir == RIGHT || ctx->enemy->dir == FRONT)
		current_enemy_x_frame = get_enemy_r_frame(ctx->enemy_x_r);
	if (current_enemy_x_frame)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
			current_enemy_x_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	paint_door(t_ctx *ctx, int x, int y)
{
	if (ctx->map.coins == 0)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->open_exit->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
	else
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, \
				ctx->exit_closed->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}
