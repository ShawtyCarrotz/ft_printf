/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:56:07 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/06/25 16:44:28 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	printformat(char specifier, va_list args)
{
	unsigned int	count;

	count = 0;
	if (specifier == 'c')
	{
		ft_putchar_fd(va_args(args, int), 1);
		count = 1;
	}
	else if (specifier == 's')
	{
		ft_putstr_fd(va_args(args, char *), 1);
		count = ft_strlen();
	}
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr_fd(va_args(args, int), 1);
	else if (specifier == 'u')
		ft_putnbr_fd(va_args(args, unsigned int), 1);
	else if (specifier == 'x')
		va_args(args, int);
	else if (specifier == 'X')
		va_args(args, int);
	//if there's a char make it upper case*/
	else if (specifier == 'p')
		va_args(args, int);
		//ft_printsignedint();*/

	return (count);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += write(1, format[i], 1);
		else
		{
			i++;
			count += printformat(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
