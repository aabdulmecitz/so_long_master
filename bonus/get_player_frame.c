/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:43:15 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 22:48:04 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	*get_player_front_frame(t_img *frame)
{
	static clock_t	last_time = 0;
	static t_img	*current_frame = NULL;
	static t_img	*frame_head = NULL;
	clock_t			current_time;
	double			elapsed_time;

	if (frame_head != frame)
	{
		frame_head = frame;
		current_frame = frame;
	}
	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 2000.0;
	if (elapsed_time >= DELAY)
	{
		current_frame = current_frame->next;
		if (current_frame == NULL)
			current_frame = frame_head;
		last_time = current_time;
	}
	return (current_frame);
}

t_img	*get_player_back_frame(t_img *frame)
{
	static clock_t	last_time = 0;
	static t_img	*current_frame = NULL;
	static t_img	*frame_head = NULL;
	clock_t			current_time;
	double			elapsed_time;

	if (frame_head != frame)
	{
		frame_head = frame;
		current_frame = frame;
	}
	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 2000.0;
	if (elapsed_time >= DELAY)
	{
		current_frame = current_frame->next;
		if (current_frame == NULL)
			current_frame = frame_head;
		last_time = current_time;
	}
	return (current_frame);
}

t_img	*get_player_right_frame(t_img *frame)
{
	static clock_t	last_time = 0;
	static t_img	*current_frame = NULL;
	static t_img	*frame_head = NULL;
	clock_t			current_time;
	double			elapsed_time;

	if (frame_head != frame)
	{
		frame_head = frame;
		current_frame = frame;
	}
	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 2000.0;
	if (elapsed_time >= DELAY)
	{
		current_frame = current_frame->next;
		if (current_frame == NULL)
			current_frame = frame_head;
		last_time = current_time;
	}
	return (current_frame);
}

t_img	*get_player_left_frame(t_img *frame)
{
	static clock_t	last_time = 0;
	static t_img	*current_frame = NULL;
	static t_img	*frame_head = NULL;
	clock_t			current_time;
	double			elapsed_time;

	if (frame_head != frame)
	{
		frame_head = frame;
		current_frame = frame;
	}
	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 2000.0;
	if (elapsed_time >= DELAY)
	{
		current_frame = current_frame->next;
		if (current_frame == NULL)
			current_frame = frame_head;
		last_time = current_time;
	}
	return (current_frame);
}

void	paint_player_with_animation(t_ctx *ctx, int x, int y)
{
	t_img	*current_player_frame;

	current_player_frame = NULL;
	if (ctx->player_dir == FRONT)
		current_player_frame = get_player_front_frame(ctx->player_front);
	else if (ctx->player_dir == BACK)
		current_player_frame = get_player_back_frame(ctx->player_back);
	else if (ctx->player_dir == LEFT)
		current_player_frame = get_player_left_frame(ctx->player_left);
	else if (ctx->player_dir == RIGHT)
		current_player_frame = get_player_right_frame(ctx->player_right);
	if (current_player_frame)
		mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr,
			current_player_frame->xpm_ptr, x * IMG_WIDTH, y * IMG_HEIGHT);
}
