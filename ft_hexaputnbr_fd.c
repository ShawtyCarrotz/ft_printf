/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaputnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:18 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/26 14:56:10 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(unsigned int n, char specifier, int fd, int *count)
{
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (specifier == 'X')
		base = "0123456789ABCDEF";
	if (n / 16 != 0)
		ft_printhexa (n / 16, specifier, fd, count);
	c = base[n % 16];
	ft_putcharint_fd(c, fd, count);
}

int	ft_hexaputnbr_fd(unsigned int n, char specifier, int fd)
{
	int	count;

	count = 0;
	ft_printhexa(n, specifier, fd, &count);
	return (count);
}
