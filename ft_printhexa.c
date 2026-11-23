/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohoussa <mohoussa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:04:33 by mohoussa          #+#    #+#             */
/*   Updated: 2026/11/19 15:15:58 by mohoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long n)
{
	int		i;
	char	*hex;
	char	buf[16];

	hex = "0123456789abcdef";
	i = 16;
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	while (n > 0)
	{
		buf[--i] = hex[n % 16];
		n /= 16;
	}
	return (write (1, &buf[i], 16 - i));
}
