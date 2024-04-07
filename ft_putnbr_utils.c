/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:48:56 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/07 14:04:14 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		len = ft_putnbr(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		len ++;
	}
	return (len);
}

int ft_put_unsignednbr(int n)
{
	int len;

	len = 0;
	if (n >= 10)
	{
		len = ft_put_unsignednbr(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		len ++;
	}
	return (len);
}