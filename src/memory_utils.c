/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:10:50 by hflohil-          #+#    #+#             */
/*   Updated: 2023/08/23 13:12:24 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

char	**resize(char **ptr, int old_size, int new_size)
{
	char	**new_ptr;

	new_ptr = malloc(sizeof(char *) * new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, sizeof(char *) * old_size);
	free(ptr);
	return (new_ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_buffer;
	unsigned char	*src_buffer;

	dst_buffer = (unsigned char *)dst;
	src_buffer = (unsigned char *)src;
	if (dst_buffer != NULL || src_buffer != NULL)
	{
		while (n)
		{
			*(dst_buffer++) = *(src_buffer++);
			n--;
		}
	}
	return (dst);
}

int	close_game(t_data *game)
{
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	free_map(game->map.map);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**allocate_map_memory(t_data *game, char **map, int col_i, char *line)
{
	if (game->map.map_height <= col_i)
	{
		map = resize(map, game->map.map_height, game->map.map_height + 2);
		game->map.map_height++;
	}
	map[col_i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!map[col_i])
		return (NULL);
	map[game->map.map_height] = NULL;
	return (map);
}
