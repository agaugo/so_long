/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:10:50 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/16 12:10:52 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(0);
}

void	free_game(t_data *game)
{
	int	col_i;

	col_i = 0;
	while (col_i < game->map.map_height)
	{
		free(game->map.map[col_i]);
		col_i++;
	}
	free(game->map.map);
}
