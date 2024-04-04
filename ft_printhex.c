/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:12:43 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/04 15:52:42 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_printhex(int nb)
{
	char hex[10];
	int rest;
	int i;

	i = 0;
	while (nb != 0)
	{
		rest = nb % 16;
		if (rest < 10)
			hex[i] = rest + 48;
		else 
			hex[i] = rest + 65;
		nb /= 16;
		i++;
	}
	return (hex);
}

#include <stdio.h>
int main ()
{
	int nb = 123;

	char *result = ft_printhex(nb);

	printf("%s", result);
	return 0;
}
