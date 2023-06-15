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

int	ft_int(int arg)
{
	char	*buffer;

	buffer = ft_itoa(arg);
	ft_putstr_fd(buffer, 1);
	free(buffer);
	return (chars(arg));
}

int	ft_str(char *arg)
{
	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		return (5);
	}
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg) - 1);
}
