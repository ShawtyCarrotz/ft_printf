/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addressputnbr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:32:18 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/16 16:47:05 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_addressputnbr_fd(int n, int fd)
{
	char	c;
	char	*base;
	int		count;

	count = 3;
	base = "0123456789abcdef";
	if (n / 16 != 0)
	{
		ft_addressputnbr_fd (n / 16, fd);
		ft_addressputnbr_fd (n % 16, fd);
		count++;
	}
	c = base[n % 16];
	ft_putchar_fd(c, fd);
	return (count);
}
