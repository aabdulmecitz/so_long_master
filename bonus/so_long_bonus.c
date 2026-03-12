/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:09:07 by aozkaya           #+#    #+#             */
/*   Updated: 2025/06/10 18:45:36 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_ctx(t_ctx *ctx)
{
	free_all_mem(ctx);
	ft_printf(GREEN "ctx closed successmap_matrisy.\n" RESET);
	exit(0);
	return (0);
}

int	main(int argc, const char *argv[])
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		error("Memory allocation failed for game", ctx);
	check_cmd_args(argc, argv, ctx);
	map_initializer(ctx, (char *)argv[1]);
	so_long_init(ctx);
	map_checker(ctx);
	init_enemies(ctx);
	init_all_of_animations(ctx);
	handle_enemies(ctx);
	mlx_loop_hook(ctx->mlx_ptr, render_a_frame, ctx);
	handler(ctx);
	mlx_loop(ctx->mlx_ptr);
	return (0);
}
