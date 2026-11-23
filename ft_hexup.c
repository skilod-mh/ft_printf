/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohoussa <mohoussa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:35:52 by mohoussa          #+#    #+#             */
/*   Updated: 2026/11/19 15:17:42 by mohoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexup(unsigned int i)
{
	char	*hex;
	char	buff [8];
	int		n;

	hex = "0123456789ABCDEF";
	n = 8;
	if (i == 0)
		return (write(1, "0", 1));
	while (i > 0)
	{
		buff[--n] = hex[i % 16];
		i = i / 16;
	}
	return (write(1, &buff[n], 8 - n));
}
