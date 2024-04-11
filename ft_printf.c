/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:58:49 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/09 11:01:57 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		len += ft_printptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		len += ft_put_unsignednbr(va_arg(arg, int));
	else if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(arg, int), format);
	else if (format == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(format);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_check_format(args, *(str + 1));
			str++;
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
