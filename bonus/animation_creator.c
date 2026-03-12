/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:30 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 22:49:34 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_creator(t_ctx *ctx, t_img *new_img,
			const char *current_path);

void	init_animation(t_ctx *ctx, t_img *img, ...)
{
	va_list		args;
	t_img		*new_img;
	const char	*current_path;
	t_img		*temp;

	va_start(args, img);
	current_path = va_arg(args, const char *);
	temp = img;
	while (current_path != NULL)
	{
		new_img = malloc(sizeof(t_img));
		img_creator(ctx, new_img, current_path);
		temp->next = new_img;
		temp = temp->next;
		current_path = va_arg(args, const char *);
	}
	va_end(args);
}

static void	init_player_animation(t_ctx *ctx)
{
	init_animation(ctx, ctx->player_front,
		PLAYER_FRONT_XPM1, PLAYER_FRONT_XPM2,
		PLAYER_FRONT_XPM3, PLAYER_FRONT_XPM4,
		PLAYER_FRONT_XPM5, PLAYER_FRONT_XPM6,
		PLAYER_FRONT_XPM7, PLAYER_FRONT_XPM8, NULL);
	init_animation(ctx, ctx->player_left,
		PLAYER_LEFT_XPM1, PLAYER_LEFT_XPM2,
		PLAYER_LEFT_XPM3, PLAYER_LEFT_XPM4,
		PLAYER_LEFT_XPM5, PLAYER_LEFT_XPM6,
		PLAYER_LEFT_XPM7, PLAYER_LEFT_XPM8, NULL);
	init_animation(ctx, ctx->player_right,
		PLAYER_RIGHT_XPM1, PLAYER_RIGHT_XPM2,
		PLAYER_RIGHT_XPM3, PLAYER_RIGHT_XPM4,
		PLAYER_RIGHT_XPM5, PLAYER_RIGHT_XPM6,
		PLAYER_RIGHT_XPM7, PLAYER_RIGHT_XPM8, NULL);
	init_animation(ctx, ctx->player_back,
		PLAYER_BACK_XPM1, PLAYER_BACK_XPM2,
		PLAYER_BACK_XPM3, PLAYER_BACK_XPM4,
		PLAYER_BACK_XPM5, PLAYER_BACK_XPM6,
		PLAYER_BACK_XPM7, PLAYER_BACK_XPM8, NULL);
}

void	init_all_of_animations(t_ctx *ctx)
{
	init_animation(ctx, ctx->coins,
		COINS_XPM1, COINS_XPM2,
		COINS_XPM3, COINS_XPM4, NULL);
	init_animation(ctx, ctx->wall,
		WALL_XPM1, WALL_XPM2, WALL_XPM3,
		WALL_XPM4, WALL_XPM5, NULL);
	init_animation(ctx, ctx->enemy_k,
		TOXIC_XPM1, TOXIC_XPM2,
		TOXIC_XPM3, TOXIC_XPM4, NULL);
	init_animation(ctx, ctx->enemy_x_l,
		WANDER_ENEMY_L_XPM1, WANDER_ENEMY_L_XPM2,
		WANDER_ENEMY_L_XPM3, WANDER_ENEMY_L_XPM4, NULL);
	init_animation(ctx, ctx->enemy_x_r,
		WANDER_ENEMY_R_XPM1, WANDER_ENEMY_R_XPM2,
		WANDER_ENEMY_R_XPM3, WANDER_ENEMY_R_XPM4, NULL);
	init_player_animation(ctx);
}

void	img_creator(t_ctx *ctx, t_img *new_img,
		const char *current_path)
{
	if (!new_img)
		error("Memory allocation failed for img node.", ctx);
	load_sprite(new_img, ctx->mlx_ptr, (char *)current_path, ctx);
	new_img->next = NULL;
}
