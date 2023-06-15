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

char	*ft_strrev(char *buffer, int size)
{
	int		index;
	int		r_index;
	char	temp;

	index = 0;
	r_index = size - 1;
	while (index <= r_index)
	{
		temp = buffer[index];
		buffer[index] = buffer[r_index];
		buffer[r_index] = temp;
		index++;
		r_index--;
	}
	buffer[size] = '\0';
	return (buffer);
}

int	chars(int n)
{
	int	nb;

	nb = 0;
	if (n == 0)
		return (0);
	if (n < 0)
	{
		nb++;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb - 1);
}
