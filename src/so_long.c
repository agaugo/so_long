/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:11:11 by hflohil-          #+#    #+#             */
/*   Updated: 2023/08/25 16:05:09 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"

int	read_error(int id)
{
	if (id == 1)
		ft_printf("Error: File not found or incorrect file extension.\n");
	else if (id == 2)
		ft_printf("Error: Empty File.\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	game;
	int		fd;
	int		len;
	int		x;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	len = (int)ft_strlen(argv[1]);
	if (fd == -1 || ft_strncmp(&argv[1][len - 4], ".ber", 4))
		return (read_error(1));
	game.mlx = mlx_init();
	game.win = NULL;
	load_imgs(&game);
	x = parse_map(fd, &game, 0);
	if (x == -1)
		return (read_error(2));
	game.win = mlx_new_window(game.mlx, (game.map.map_width * IMG_SIZE),
			(game.map.map_height * IMG_SIZE), "so_long");
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
