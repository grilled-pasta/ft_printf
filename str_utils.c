/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:29:31 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/16 22:29:55 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

static int	ft_putnbr_hex_x(unsigned long n, char *hex, int length)
{
	unsigned long	nb;
	char			temp;

	nb = n;
	if (nb >= 16)
		length = ft_putnbr_hex_x(nb / 16, hex, length);
	temp = hex[nb % 16];
	write(1, &temp, 1);
	return (length + 1);
}

int	ft_putnbr_hex(unsigned long n, int hex_case, int is_p)
{
	static char	*hex[] = {"0123456789abcdef", "0123456789ABCDEF"};
	char		temp;
	int			res;

	res = 0;
	if (hex_case < 0 || hex_case > 1)
		hex_case = 0;
	if (is_p)
	{
		temp = '0';
		write(1, &temp, 1);
		temp = 'x';
		write(1, &temp, 1);
		res += 2;
	}
	res += ft_putnbr_hex_x(n, hex[hex_case], 0);
	return (res);
}

int	ft_putnbr(int n, int length)
{
	long	nb;
	char	temp;

	nb = n;
	if (n < 0)
	{
		temp = '-';
		write(1, &temp, 1);
		nb = -nb;
		length = length + 1;
	}
	if (nb > 9)
		length = ft_putnbr(nb / 10, length);
	temp = '0' + (nb % 10);
	write(1, &temp, 1);
	return (length + 1);
}

int	ft_putunbr(unsigned int n, int length)
{
	long	nb;
	char	temp;

	nb = n;
	if (n < 0)
	{
		temp = '-';
		write(1, &temp, 1);
		nb = -nb;
		length = length + 1;
	}
	if (nb > 9)
		length = ft_putnbr(nb / 10, length);
	temp = '0' + (nb % 10);
	write(1, &temp, 1);
	return (length + 1);
}
