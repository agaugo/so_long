/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:10:50 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/26 15:18:13 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	system("leaks so_long");
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
