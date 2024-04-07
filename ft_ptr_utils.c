/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:07:12 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/07 17:39:29 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(intptr_t str)
{
	int	len;

	len = 0;
	while (str != 0)
	{
		str /= 16;
		len++;
	}
	return (len);
}

void	ft_putptr(intptr_t ptr)
{
	while (ptr > 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	if (ptr < 10)
		ft_putchar(ptr + '0');
	else
	{
		ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_printptr(intptr_t ptr)
{
	
	ft_putptr(ptr);
	return (ft_ptrlen(ptr));
}
