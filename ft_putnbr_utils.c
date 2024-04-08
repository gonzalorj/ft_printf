/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:48:56 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/08 13:05:01 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return (len += 11);
		}
		ft_putchar('-');
		n *= -1;
		len++;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		len++;
	}
	return (len);
}

unsigned int	ft_put_unsignednbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_put_unsignednbr(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		len++;
	}
	return (len);
}
