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

#include "ft_printf.h"

int	ft_printf_two(char flag, va_list args)
{
	int	add_count;

	add_count = 0;
	if (flag == 'u')
		add_count += itou(va_arg(args, unsigned int));
	if (flag == 'X')
		add_count += itohex(va_arg(args, unsigned int), 1);
	if (flag == 'x')
		add_count += itohex(va_arg(args, unsigned int), 0);
	if (flag == 'p')
		add_count += itoptr(va_arg(args, uintptr_t));
	if (flag == 's')
		add_count += ft_str(va_arg(args, char *));
	if (flag == 'd' || flag == 'i')
		add_count += ft_int(va_arg(args, int));
	if (flag == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (flag == '%')
		ft_putchar_fd('%', 1);
	return (add_count);
}

int	ft_printf(const char *flag_string, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, flag_string);
	while (*flag_string)
	{
		if (*flag_string == '%')
		{
			flag_string++;
			count += ft_printf_two(*flag_string, args);
		}
		else if (*flag_string != '%')
			ft_putchar_fd(*flag_string, 1);
		count++;
		if (*flag_string)
			flag_string++;
	}
	va_end(args);
	return (count);
}
