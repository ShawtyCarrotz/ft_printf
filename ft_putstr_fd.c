/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:55:27 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/26 14:58:50 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (s[i])
		count += write(fd, &s[i++], 1);
	return (count);
}
