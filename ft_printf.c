/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:56:07 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/02 16:48:31 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	printformat(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_putchar_fd(va_arg(args, int), 1);
	else if (specifier == 's')
		count = ft_putstr_fd(va_arg(args, char *), 1);
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
	int	i;
	int	count;
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

	count = ft_printf("Hello %s\n", "Ines");
	//count = ft_printf("Hello %s\n", "Ines");
	printf("%d\n", count);
	ft_printf("Hello %c", 'I');
	return (0);
}
