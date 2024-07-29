/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:56:07 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/26 15:13:38 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printformat(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_putchar_fd(va_arg(args, int), 1);
	else if (specifier == 's')
		count = ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 'u')
		count = ft_putnbr_fd(va_arg(args, int), specifier, 1);
	else if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr_fd(va_arg(args, int), specifier, 1);
	else if (specifier == 'x' || specifier == 'X')
		count = ft_hexaputnbr_fd(va_arg(args, unsigned int), specifier, 1);
	else if (specifier == 'p')
		count = ft_memputnbr_fd(va_arg(args, void *), 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

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
			if (format[i] == '%')
				count += write(1, &format[i], 1);
			else
				count += printformat(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	count;
	char	*string = "tu es toto";
	count = ft_printf("Hello %s\n", "Ines");
	printf("%d\n", count);
	count = printf("Hello %s\n", "Ines");
	printf("%d\n", count);
	count = ft_printf("Hello %c\n", 'I');
	printf("%d\n", count);
	count = printf("Hello %c\n", 'I');
	printf("%d\n", count);
	count = ft_printf("Hello %u\n", 1);
	printf("%d\n", count);
	count = printf("Hello %u\n", 1);
	printf("%d\n", count);
	count = ft_printf("Hello %u\n", 12345678);
	printf("%d\n", count);
	count = printf("Hello %u\n", 12345678);
	printf("%d\n", count);
	count = ft_printf("Hello %d\n", -12345678);
	printf("%d\n", count);
	count = printf("Hello %d\n", -12345678);
	printf("%d\n", count);
	count = ft_printf("Hello %d\n", -2147483648);
	printf("%d\n", count);
	count = ft_printf("Hello %x\n", 140);
	printf("%d\n", count);
	count = printf("Hello %x\n", 140);
	printf("%d\n", count);
	count = ft_printf("Hello %X\n", 140);
	printf("%d\n", count);
	count = printf("Hello %X\n", 140);
	printf("%d\n", count);
	count = ft_printf("Hello %x\n", 1000);
	printf("%d\n", count);
	count = printf("Hello %x\n", 1000);
	printf("%d\n", count);
	count = ft_printf("Hello %X\n", 1000);
	printf("%d\n", count);
	count = printf("Hello %X\n", 1000);
	printf("%d\n", count);
	count = ft_printf("Hello %p\n", string);
	printf("%d\n", count);
	count = printf("Hello %p\n", string);
	printf("%d\n", count);
	return (0);
}*/
