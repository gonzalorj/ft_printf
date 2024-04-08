/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:00:38 by gorodrig          #+#    #+#             */
/*   Updated: 2024/04/08 13:05:33 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void				ft_putptr(unsigned long long ptr);
int					ft_printf(const char *format, ...);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putnbr(int n);
unsigned int		ft_put_unsignednbr(unsigned int n);
int					ft_printhex(int n, char format);
int					ft_printptr(unsigned long long ptr);

#endif