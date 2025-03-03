/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memputnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:18 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/26 14:56:24 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!ptr)
		return (write(fd, "(nil)", 5));
	count += write (fd, "0x", 2);
	ft_printmem((unsigned long)ptr, fd, &count);
	return (count);
}
