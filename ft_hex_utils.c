/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:48:54 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/08 13:47:13 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_puthex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else if (format == 'X')
	{
		ft_putchar(n - 10 + 'A');
	}
	else if (format == 'x')
	{
		ft_putchar (n - 10 + 'a');
	}
}

int	ft_printhex(unsigned int n, const char format)
{
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	ft_puthex(n, format);
	return (ft_hexlen(n));
}
