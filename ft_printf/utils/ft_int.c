/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <hflohil-@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fill_string(unsigned int arg, char *buffer, int rev_index)
{
	int	i;

	i = rev_index - 1;
	if (arg == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}
	while (i >= 0)
	{
		buffer[i] = arg % 10 + '0';
		arg -= arg % 10;
		arg = arg / 10;
		i--;
	}
	buffer[rev_index] = '\0';
}

int	count_chars(unsigned int x)
{
	int	nb;

	nb = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = x / 10;
		nb++;
	}
	return (nb);
}

int	itou(unsigned int arg)
{
	char			*buffer;
	int				char_count;

	char_count = count_chars(arg);
	buffer = malloc(sizeof(char) * char_count + 1);
	if (!buffer)
		return (0);
	fill_string(arg, buffer, char_count);
	ft_putstr_fd(buffer, 1);
	free(buffer);
	return (char_count - 1);
}
