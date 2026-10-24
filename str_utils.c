/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:29:31 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 01:08:09 by alkonsta         ###   ########.fr       */
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

int	ft_putnstr(char	*s, int length)
{
	// char	temp;
	//
	// temp = '\0';
	// write(1, s, length);
	// write(1, &temp, 1);
	return (write(1, s, length));
}

int	ft_putnbr_base(unsigned long n, char *base, char *buffer)
{
	int		length;
	size_t	base_length;
	int		temp;

	length = 0;
	temp = 0;
	if (!base || ft_strlen(base) < 2 || !buffer)
		return (-1);
	base_length = ft_strlen(base);
	if (n >= base_length)
	{
		temp = ft_putnbr_base(n / base_length, base, buffer);
		if (temp < 0)
			return (temp);
		length = temp;
	}
	buffer[length] = base[n % base_length];
	return (length + 1);
}
