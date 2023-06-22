/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:11:00 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/22 14:44:07 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 53)
		close_game(game);
	if (keycode == 13)
		handle_movement(game, 1);
	if (keycode == 0)
		handle_movement(game, 2);
	if (keycode == 1)
		handle_movement(game, 3);
	if (keycode == 2)
		handle_movement(game, 4);
	return (0);
}
