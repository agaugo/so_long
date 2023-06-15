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

int	itoptr(uintptr_t convert)
{
	char		*string_hex;
	char		result[100];
	uintptr_t	remainder;
	uintptr_t	i;

	string_hex = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	if (!convert)
	{
		write(1, "0", 1);
		return (2);
	}
	while (convert != 0)
	{
		remainder = convert / 16;
		result[i++] = string_hex[convert - (remainder * 16)];
		convert = remainder;
	}
	result[i] = '\0';
	ft_putstr_fd(ft_strrev(result, i), 1);
	return (ft_strlen(result) + 1);
}
