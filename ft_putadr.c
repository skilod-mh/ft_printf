/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohoussa <mohoussa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:25:43 by mohoussa          #+#    #+#             */
/*   Updated: 2026/11/19 15:16:18 by mohoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr(void *p)
{
	unsigned long	i;
	int				count;
	int				r;

	i = (unsigned long)p;
	if (i == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	r = ft_printhexa(i);
	if (r < 0)
		return (-1);
	return (count + r);
}
