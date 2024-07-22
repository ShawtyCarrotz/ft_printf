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

void	ft_printnbr(int n, int fd, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		n = 147483648;
		ft_putcharint_fd('-', fd, count);
		ft_putcharint_fd('2', fd, count);
	}
	else if (n < 0)
	{
		n = -n;
		ft_putcharint_fd('-', fd, count);
	}
	if (n / 10 != 0)
		ft_printnbr(n / 10, fd, count);
	c = n % 10 + '0';
	ft_putcharint_fd(c, fd, count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	ft_printnbr(n, fd, &count);
	return (count);
}
