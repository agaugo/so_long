/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:03:04 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/23 16:03:47 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	i = 0;
	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while (s1_cast[i] != '\0' && i < n)
	{
		if (s1_cast[i] > s2_cast[i])
			return (1);
		else if (s1_cast[i] < s2_cast[i])
			return (-1);
		else
			i++;
	}
	if (i != n && s2[i] != '\0')
		return (-1);
	else
		return (0);
}

void	invalid_map(t_data *game)
{
	ft_printf("Error: Invalid Map.\n");
	close_game(game);
}
