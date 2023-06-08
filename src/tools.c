#include "../so_long.h"
#include <stdio.h>

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

int ft_strcmp(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') 
    {
        if (str1[i] != str2[i])
            return 0;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}