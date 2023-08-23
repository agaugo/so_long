/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:21:07 by hflohil-          #+#    #+#             */
/*   Updated: 2023/08/23 12:31:17 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// **** STRUCTS **** //

# define IMG_SIZE 32

typedef struct s_validity
{
	int			player_count;
	int			exit_count;
	int			goblin_count;
	int			alien_chars;
}				t_validity;

typedef struct s_direction
{
	int			dx;
	int			dy;
}				t_direction;

typedef struct s_player
{
	int			x;
	int			y;
	int			count;
}				t_player;

typedef struct s_map
{
	int			map_height;
	int			map_width;
	char		**map;
	t_validity	validity;

}				t_map;

typedef struct s_imgs
{
	void		*img_tile;
	void		*img_wall;
	void		*img_hero;
	void		*img_goblin;
	void		*img_exit;
}				t_imgs;

typedef struct s_dimensions
{
	int			height;
	int			width;

}				t_dimensions;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	t_imgs		imgs;
	t_map		map;
	t_player	player;
	int			error;
}				t_data;

//  **** CORE **** //
int		main(int argc, char *argv[]);
int		parse_map(int fd, t_data *game, int col_i);
int		key_hook(int keycode, t_data *game);
void	free_game(t_data *game);
void	handle_movement(t_data *game, int direction);
void	render_map(t_data *game);
int		ft_printf(const char *flag_string, ...);
int		close_game(t_data *game);
int		read_map(t_data *game);
int		check_map(t_data *game);
void	flood_fill(t_data *game, char **map, int x, int y);
int		check_path(t_data *game, char **map);
void	load_imgs(t_data *game);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**resize(char **ptr, int old_size, int new_size);
void	invalid_map(t_data *game);
void	save_lines(t_data *game);
void	save_lines_two(t_data *game, char **map);
void	assign_image(t_data *game, int row_i, int col_i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**allocate_map_memory(t_data *game, char **map, int col_i,
			char *line);
void	free_map(char **map);
char	**copy_map(t_data *game);

#endif