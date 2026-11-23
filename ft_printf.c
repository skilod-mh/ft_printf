/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohoussa <mohoussa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:47:02 by mohoussa          #+#    #+#             */
/*   Updated: 2026/11/19 17:39:40 by mohoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prf(const char *f, va_list ar)
{
	int	i;

	i = 0;
	if (f[i] == '%' && f[i + 1] == 'c')
		return (ft_putchar((va_arg(ar, int))));
	if (f[i] == '%' && f[i + 1] == 's')
		return (ft_putstr(va_arg(ar, char *)));
	if (f[i] == '%' && (f[i + 1] == 'd' || f[i + 1] == 'i'))
		return (ft_putnbr((va_arg(ar, int))));
	if (f[i] == '%' && f[i + 1] == 'p')
		return (ft_putadr(va_arg(ar, void *)));
	if (f[i] == '%' && f[i + 1] == 'u')
		return (ft_forunsigned((va_arg(ar, unsigned int))));
	if (f[i] == '%' && f[i + 1] == 'x')
		return (ft_printhexa((va_arg(ar, unsigned int))));
	if (f[i] == '%' && f[i + 1] == 'X')
		return (ft_hexup((va_arg(ar, unsigned int))));
	if (f[i] == '%' && f[i + 1] == '%')
		return (write(1, &f[i], 1));
	return (0);
}

static int	ft_convert(const char *format, va_list ar)
{
	int		i;
	int		count;
	int		r;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			r = (ft_prf(&format[i], ar));
			i++;
		}
		else
			r = write(1, &format[i], 1);
		if (r < 0)
			return (-1);
		count += r;
		i++;
	}
	return (count);
}

int	ft_printf(const char *f, ...)
{
	va_list		arg;
	int			i;

	if (!f)
		return (-1);
	va_start (arg, f);
	i = ft_convert(f, arg);
	va_end(arg);
	return (i);
}
