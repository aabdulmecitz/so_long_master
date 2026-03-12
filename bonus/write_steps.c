/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:15 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:52:54 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_steps(t_ctx *ctx, int x, int y)
{
	char	*movement;

	movement = ft_itoa(ctx->movements);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, x + 64, y, 0xFFFFFF, movement);
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, x, y, 0xFFFFFF, "Movements: ");
	free(movement);
}
