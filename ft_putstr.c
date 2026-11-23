/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohoussa <mohoussa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:27:59 by mohoussa          #+#    #+#             */
/*   Updated: 2026/11/19 17:38:55 by mohoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		count;
	int		r;

	if (!s)
		return (write (1, "(null)", 6));
	count = 0;
	i = 0;
	while (s[i])
	{
		r = write(1, &s[i], 1);
		if (r < 0)
			return (-1);
		count += r;
		i++;
	}
	return (count);
}
