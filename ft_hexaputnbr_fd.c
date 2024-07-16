/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaputnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:18 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/16 16:24:04 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_hexaputnbr_fd(int n, char specifier, int fd)
{
	char	c;
	char	*base;
	int		count;

	count = 1;
	base = "0123456789abcdef";
	if (specifier == 'X')
		base = "0123456789ABCDEF";
	if (n / 16 != 0)
	{
		ft_hexaputnbr_fd (n / 16, specifier, fd);
		ft_hexaputnbr_fd (n % 16, specifier, fd);
		count++;
	}
	c = base[n % 16];
	ft_putchar_fd(c, fd);
	return (count);
}
