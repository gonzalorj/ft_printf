/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:58:49 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/03 15:43:44 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int rt;

	rt = 0;
	while (*str)
		if (str == '%')
		{
			str++;
			ft_check_type(str, arg)
		}

}

static int ft_check_type(char *str, void *arg)
{
	int rt;

	rt = 0;
	if (*str == 'c')
		rt = ft_putchar_fd();
	else if (*str == 's')
		rt = ft_putstr_fd();
	else if (*str == 'p')
		rt = ft_puthexvoid;
	else if (*str == 'd')
		rt = ft_putnbr_fd;
	else if (*str == 'i')
		rt = ft_putnbr_fd;
	else if (*str == 'u')
		rt = ft_putnbrunsigned;
	else if (*str == 'x')
		rt = ft_hexmin;
	else if (*str == 'X')
		rt = ft_hexmay;
	else if (*str == '%')
		rt = ft_putchar_fd;
	return (rt);
}