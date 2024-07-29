/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:39:59 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/26 15:09:01 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Auxiliar LIbrary
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, char specifier, int fd);
int		ft_hexaputnbr_fd(unsigned int n, char specifier, int fd);
int		ft_memputnbr_fd(void *ptr, int fd);
int		ft_printf(const char *format, ...);

void	ft_putcharint_fd(char c, int fd, int *count);

#endif
