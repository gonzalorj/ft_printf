/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:58:49 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/08 13:06:27 by gorodrig         ###   ########.fr       */
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

/*
int main()
{
	ft_printf("%s\n", "%c tests");
	ft_printf("%s\n\n", "---------------------------------");
	ft_printf("%c\n", 'a');
	ft_printf("%c\n", 'b');
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '1');
	ft_printf("%c\n", '0');
	ft_printf("%c\n", ' ');
	ft_printf("%c\n", '\0');
	ft_printf("%c\n", '\n');
	ft_printf("%c\n", '\t');
	ft_printf("%s\n", "%s tests");
	ft_printf("%s\n\n", "---------------------------------");
	ft_printf("%s\n", "-");
	ft_printf("%s\n", "Hello, World!");
	ft_printf("%s\n", "1312321");
	ft_printf("%s\n", "0");
	ft_printf("%s\n", "1");
	ft_printf("%s\n", "");
	ft_printf("%s\n", " ");
	ft_printf("%s %s\n", "a", "");
	ft_printf("%s %s\n", "", "a");
	ft_printf("%s %s\n", "a", "b");
	ft_printf("%s", "%p tests");
	ft_printf("%s\n", "---------------------------------");
	ft_printf("%p\n", 0);
	ft_printf("%p\n", 1);
	ft_printf("%p\n", 10);
	ft_printf("%p\n", 16);
	ft_printf("%p\n", 17);
	ft_printf("%p\n", 100);
	ft_printf("%p\n", 1000);
	ft_printf("%p\n", 10000);
	ft_printf("%p\n", -1);
	ft_printf("%p\n", -10);
	ft_printf("%p\n", -100);
	ft_printf("%p\n");
	ft_printf("%s", "%d tests");
	ft_printf("%s\n", "---------------------------------");
	ft_printf("%d\n", 0);
	ft_printf("%d\n", 1);
	ft_printf("%d\n", 10);
	ft_printf("%d\n", 16);
	ft_printf("%d\n", 17);
	ft_printf("%d\n", 100);
	ft_printf("%d\n", -1);
	ft_printf("%d\n", -10);
	ft_printf("%d\n", -100);
	ft_printf("%d\n", -2147483648);
	ft_printf("%s", "%i tests");
	ft_printf("%s\n", "---------------------------------");
	ft_printf("%i\n", 0);
	ft_printf("%i\n", 1);
	ft_printf("%i\n", 10);
	ft_printf("%i\n", 16);
	ft_printf("%i\n", 17);
	ft_printf("%i\n", 100);
	ft_printf("%i\n", -1);
	ft_printf("%i\n", -10);
	ft_printf("%i\n", -100);
	ft_printf("%i\n", -2147483648);
	ft_printf("%s", "%u tests");
	ft_printf("%s\n", "---------------------------------");
	ft_printf("%u\n", 0);
	ft_printf("%u\n", 1);
	ft_printf("%u\n", 10);
	ft_printf("%u\n", -1);
	ft_printf("%u\n", J3123);
	
		
	return (0);
}
*/
