/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipais-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:39:59 by ipais-mo          #+#    #+#             */
/*   Updated: 2024/07/17 19:24:18 by ipais-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//Auxiliar LIbrary
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_hexaputnbr_fd(int n, char specifier, int fd);

void	ft_putcharint_fd(char c, int fd, int *count);

#endif
