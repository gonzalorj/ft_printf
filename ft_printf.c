/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:58:49 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/07 16:11:58 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_check_format(*format + 1, args);
			format++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

static int	ft_check_format(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(arg, char));
	else if (format == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(arg, intptr_t));
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
