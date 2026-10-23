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

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length])
		length++;
	return (length);
}

size_t	ft_putnbr_base(unsigned long n, char *base)
{
	size_t	length;
	size_t	base_length;

	length = 0;
	base_length = ft_strlen(base);
	if (n >= base_length)
		length = ft_putnbr_base(n / base_length, base);
	length += write(1, &base[n % base_length], 1);
	return (length);
}
