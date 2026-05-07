/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:32:57 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 03:49:46 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char *argv[])
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
	{
		ft_printf(RED "Error\nMemory allocation failed for game\n" RESET);
		exit(1);
	}
	gc_init(&ctx->gc);
	ft_printf(CYAN "Initializing so_long...\n" RESET);
	so_long_init(ctx);
	check_cmd_args(argc, argv, ctx);
	ft_printf(YELLOW "Parsing map: %s\n" RESET, argv[1]);
	map_initializer(ctx, (char *)argv[1]);
	map_checker(ctx);
	ft_printf(GREEN "Map validation successful!\n" RESET);
	ft_init_mlx(ctx);
	ft_init_sprites(ctx);
	ft_printf(GREEN "Graphics initialized. Enjoy the game!\n" RESET);
	render_map(ctx);
	mlx_hook(ctx->win_ptr, 2, 1L << 0, key_hook, ctx);
	mlx_hook(ctx->win_ptr, 17, 0, win_destroy, ctx);
	mlx_loop(ctx->mlx_ptr);
	return (0);
}
