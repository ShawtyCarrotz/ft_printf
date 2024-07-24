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

void	ft_printmem(unsigned long n, int fd, int *count)
{
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (n / 16 != 0)
		ft_printmem (n / 16, fd, count);
	c = base[n % 16];
	ft_putcharint_fd(c, fd, count);
}

int	ft_memputnbr_fd(void *ptr, int fd)
{
	int	count;

	count = 0;
	ft_printmem((unsigned long)ptr, fd, &count);
	return (count);
}
