/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohoussa <mohoussa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:29:34 by mohoussa          #+#    #+#             */
/*   Updated: 2026/11/19 16:08:13 by mohoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_forunsigned(unsigned int n)
{
	char	c;
	int		count;
	int		r;

	count = 0;
	if (n >= 10)
	{
		r = ft_forunsigned (n / 10);
		if (r < 0)
			return (-1);
		count += r;
	}
	c = (n % 10) + '0';
	r = write (1, &c, 1);
	if (r < 0)
		return (-1);
	return (count + r);
}
