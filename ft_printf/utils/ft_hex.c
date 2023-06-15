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

int	itohex(unsigned int convert, int uppercase)
{
	char			*string_hex;
	char			result[100];
	unsigned int	remainder;
	unsigned int	i;

	if (convert == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (uppercase)
		string_hex = "0123456789ABCDEF";
	else
		string_hex = "0123456789abcdef";
	i = 0;
	while (convert != 0)
	{
		remainder = convert / 16;
		result[i++] = string_hex[convert - (remainder * 16)];
		convert = remainder;
	}
	result[i] = '\0';
	ft_putstr_fd(ft_strrev(result, i), 1);
	return (i - 1);
}
