/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:48:54 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/07 16:11:59 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(int n)
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

void	ft_puthex(int n, const char format)
{
	while (n > 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	if (n < 10)
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

int	ft_printhex(int n, const char format)
{
	ft_puthex(n, format);
	return (ft_hexlen(n));
}
