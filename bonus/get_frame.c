/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:24 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/26 04:00:34 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	*get_coin_frame(t_img *frame)
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

t_img	*get_wall_frame(t_img *frame)
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
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1000;
	if (elapsed_time >= DELAY)
	{
		current_frame = current_frame->next;
		if (current_frame == NULL)
			current_frame = frame_head;
		last_time = current_time;
	}
	return (current_frame);
}

t_img	*get_toxic_frame(t_img *frame)
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

t_img	*get_enemy_r_frame(t_img *frame)
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

t_img	*get_enemy_l_frame(t_img *frame)
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
