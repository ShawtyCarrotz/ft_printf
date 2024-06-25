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

#include <libft.h>
#include <stdarg.h>

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
			write(1, format[i], 1);
		else
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				ft_putnbr_fd(va_args(args, int), 1);
			else if (format[i + 1] == 'u')
				ft_putnbr_fd(va_args(args, unsigned int), 1);
			else if (format[i + 1] == 'x')
				va_args(args, int);
			else if (format[i + 1] == 'X')
				va_args(args, int);
			//if there's a char make it upper case
			else if (format[i + 1] == 's')
				ft_putstr_fd(va_args(args, char *));
			else if (format[i + 1] == 'c')
				ft_putchar_fd(va_args(args, char), 1);
			else if (format[i + 1] == 'p')
				va_args(args, int);
				//ft_printsignedint();
		}
		count++;
		i++;
	}
	va_end(args);
	return (count);
}
