/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:07:12 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/08 12:56:17 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long str)
{
	int	len;

	len = 0;
	if (str == 0)
		return (-1);
	while (str != 0)
	{
		str /= 16;
		len++;
	}
	return (len);
}

void	ft_putptr(unsigned long long ptr)
{
	if (ptr > 15)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else if (ptr < 10)
		ft_putchar(ptr + '0');
	else
	{
		ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (len += ft_putstr("0x0"));
	len += ft_putstr("0x");
	ft_putptr(ptr);
	len += ft_ptrlen(ptr);
	return (len);
}
