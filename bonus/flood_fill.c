/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:08:33 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/24 21:52:54 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_map	*ft_copy_map(const t_map *src_map)
{
	t_map	*dst_map;
	int		i;

	dst_map = (t_map *)malloc(sizeof(t_map));
	if (!dst_map)
		return (NULL);
	*dst_map = *src_map;
	dst_map->map_matris = (char **)malloc(sizeof(char *) * dst_map->rows);
	if (!dst_map->map_matris)
		return (free(dst_map), NULL);
	i = 0;
	while (i < dst_map->rows)
	{
		dst_map->map_matris[i] = ft_strdup(src_map->map_matris[i]);
		if (!dst_map->map_matris[i])
		{
			while (i--)
				free(dst_map->map_matris[i]);
			return (free(dst_map->map_matris), free(dst_map), NULL);
		}
		i++;
	}
	return (dst_map);
}

static void	flood_fill_c(t_map *map, int x, int y, int *collected)
{
	if (x < 0 || x >= map->columns || y < 0 || y >= map->rows
		|| map->map_matris[y][x] == WALL || map->map_matris[y][x] == STAT_ENEMY
		|| map->map_matris[y][x] == 'F'
		|| map->map_matris[y][x] == MAP_EXIT)
		return ;
	if (map->map_matris[y][x] == COINS)
		(*collected)++;
	map->map_matris[y][x] = 'F';
	flood_fill_c(map, x + 1, y, collected);
	flood_fill_c(map, x - 1, y, collected);
	flood_fill_c(map, x, y + 1, collected);
	flood_fill_c(map, x, y - 1, collected);
}

static void	flood_fill_e(t_map *map, int x, int y, int *collected)
{
	if (x < 0 || x >= map->columns || y < 0 || y >= map->rows
		|| map->map_matris[y][x] == WALL || map->map_matris[y][x] == STAT_ENEMY
		|| map->map_matris[y][x] == 'F')
		return ;
	if (map->map_matris[y][x] == MAP_EXIT)
		(*collected)++;
	map->map_matris[y][x] = 'F';
	flood_fill_e(map, x + 1, y, collected);
	flood_fill_e(map, x - 1, y, collected);
	flood_fill_e(map, x, y + 1, collected);
	flood_fill_e(map, x, y - 1, collected);
}

int	check_collectables(t_map *map_c, t_map *map_e, t_ctx *ctx)
{
	int	x;
	int	y;
	int	collected_c;
	int	collected_e;

	x = ctx->map.player.x;
	y = ctx->map.player.y;
	collected_c = 0;
	collected_e = 0;
	flood_fill_c(map_c, x, y, &collected_c);
	flood_fill_e(map_e, x, y, &collected_e);
	return (collected_c == map_c->coins && collected_e == map_e->exit);
}

void	general_checker(t_ctx *ctx)
{
	t_map	*clone_map_c;
	t_map	*clone_map_e;
	int		result;

	if (WIN_W >= (ctx->map.columns * IMG_WIDTH) && WIN_H
		>= (ctx->map.rows * IMG_HEIGHT))
	{
		ft_printf("rows %d, columns %d\n", ctx->map.rows, ctx->map.columns);
		ft_printf(GREEN"Map validation passed!\n"RESET);
	}
	else
		error("The map is too large for your display.", ctx);
	clone_map_c = ft_copy_map(&ctx->map);
	clone_map_e = ft_copy_map(&ctx->map);
	if (!clone_map_c)
		error("Map copy failed.", ctx);
	if (!clone_map_e)
		error("Map copy failed.", ctx);
	result = check_collectables(clone_map_c, clone_map_e, ctx);
	if (result)
		ft_printf(GREEN"Passed from flood fill\n"RESET);
	else
		error("All of coins or exit can't accessible.", ctx);
	free_map_inside(clone_map_c);
	free_map_inside(clone_map_e);
}
