/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:18 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/17 19:34:45 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	count = ft_count(n);
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		count++;
	}
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		count++;
	}
	if (n / 10 != 0)
		ft_putnbr_fd (n / 10, fd);
	c = n % 10 + '0';
	ft_putchar_fd(c, fd);
	return (count);
}
