/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:32:57 by aozkaya           #+#    #+#             */
/*   Updated: 2026/03/12 18:33:00 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char *argv[])
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
	{
		ft_printf("Error\nMemory allocation failed for game\n");
		exit(1);
	}
	so_long_init(ctx);
	check_cmd_args(argc, argv, ctx);
	map_initializer(ctx, (char *)argv[1]);
	map_checker(ctx);
	ft_init_mlx(ctx);
	ft_init_sprites(ctx);
	render_map(ctx);
	mlx_hook(ctx->win_ptr, 2, 1L << 0, key_hook, ctx);
	mlx_hook(ctx->win_ptr, 17, 0, win_destroy, ctx);
	mlx_loop(ctx->mlx_ptr);
	return (0);
}
