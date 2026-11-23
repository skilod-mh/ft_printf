/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohoussa <mohoussa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:28:16 by mohoussa          #+#    #+#             */
/*   Updated: 2026/11/19 19:51:13 by mohoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf(const char *f, ...);
int	ft_forunsigned(unsigned int n);
int	ft_printhexa(unsigned long n);
int	ft_putadr(void *p);
int	ft_hexup(unsigned int i);
#endif