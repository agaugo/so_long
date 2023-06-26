/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:11:04 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/22 14:49:41 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_data *game, t_direction *direction)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + direction->dx;
	new_y = game->player.y + direction->dy;
	if (game->map.map[new_y][new_x] == 'E'
		&& game->map.validity.goblin_count == 0)
	{
        ft_printf("FINAL SCORE: %d\n", game->player.count);
        close_game(game);
	}
	if (game->map.map[new_y][new_x] == '0'
		|| game->map.map[new_y][new_x] == 'C')
	{
		if (game->map.map[new_y][new_x] == 'C')
			game->map.map[new_y][new_x] = '0';
		game->player.x = new_x;
		game->player.y = new_y;
		game->player.count += 1;
		render_map(game);
		ft_printf("Step Count: %d\n", game->player.count);
	}
}

void	handle_movement(t_data *game, int direction)
{
	t_direction	up;
	t_direction	left;
	t_direction	down;
	t_direction	right;

	up.dx = 0;
	up.dy = -1;
	left.dx = -1;
	left.dy = 0;
	down.dx = 0;
	down.dy = 1;
	right.dx = 1;
	right.dy = 0;
	if (direction == 1)
		move_player(game, &up);
	else if (direction == 2)
		move_player(game, &left);
	else if (direction == 3)
		move_player(game, &down);
	else if (direction == 4)
		move_player(game, &right);
}
