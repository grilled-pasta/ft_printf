/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:29:31 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 21:14:18 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length])
		length++;
	return (length);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char	*s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int		length;
	size_t	base_length;
	int		temp;

	length = 0;
	temp = 0;
	if (!base || !*base || ft_strlen(base) < 2)
		return (-1);
	base_length = ft_strlen(base);
	if (n >= base_length)
	{
		temp = ft_putnbr_base(n / base_length, base);
		if (temp < 0)
			return (temp);
		length = temp;
	}
	temp = write(1, &base[n % base_length], 1);
	if (temp < 0)
		return (temp);
	length += temp;
	return (length);
}
