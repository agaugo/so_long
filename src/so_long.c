/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:11:11 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/16 12:13:24 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	game;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
    game.mlx = mlx_init();
    game.win = NULL;
    load_imgs(&game);
    parse_map(fd, &game);
    game.win = mlx_new_window(game.mlx, (game.map.map_width * IMG_SIZE), (game.map.map_height * IMG_SIZE),"so_long");
    render_map(&game);
    mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
