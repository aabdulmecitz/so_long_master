/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:50:01 by aozkaya           #+#    #+#             */
/*   Updated: 2025/05/25 22:50:03 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_empty_lines(char *map, t_ctx *ctx);

void	map_initializer(t_ctx *ctx, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	char	*tmp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error("The Map couldn't be opened. Does the Map exist?", ctx);
	map_temp = ft_strdup("");
	ctx->map.rows = 0;
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		tmp = ft_strjoin(map_temp, line_temp);
		free_double(map_temp, line_temp, NULL, NULL);
		map_temp = tmp;
		ctx->map.rows++;
	}
	close(map_fd);
	check_empty_lines(map_temp, ctx);
	ctx->map.map_matris = ft_split(map_temp, '\n');
	ctx->map_alloc = 1;
	free(map_temp);
}

void	check_empty_lines(char *map, t_ctx *ctx)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error("Invalid map.\
The map have an empty line right at the beginning.", ctx);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		error("Invalid map. \
The map have an empty line at the end.", ctx);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error("Invalid map. \
The map have an empty line at the middle.", ctx);
		}
		i++;
	}
}
