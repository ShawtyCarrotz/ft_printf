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

#include "../Libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	printformat(char specifier, va_list args)
{
	unsigned int	count;
	char	*s;

	count = 0;
	if (specifier == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count = 1;
	}
	else if (specifier == 's')
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
		count = ft_strlen(s);
	}
	/*else if (specifier == 'd' || specifier == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 'u')
		ft_putnbr_fd(va_args(args, unsigned int), 1);
	else if (specifier == 'x')
		va_args(args, int);
	else if (specifier == 'X')
		va_args(args, int);
	//if there's a char make it upper case
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
			count += write(1, &format[i], 1);
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

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s", "Ines");
	printf("%d", count);
	return (0);
}
