/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:58:11 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/29 00:10:40 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(char *s, t_specs specs)
{
	int	sign;

	sign = 0;
	if (*s == '-')
	{
		if (ft_putchar(*s) < 0)
			return (-1);
		sign = 1;
	}
	else if (specs.flags.plus)
	{
		if (ft_putchar('+') < 0)
			return (-1);
		sign = 1;
	}
	else if (specs.flags.space)
	{
		if (ft_putchar(' ') < 0)
			return (-1);
		sign = 1;
	}
	return (sign);
}

int	print_hex_prefix(char *s, t_specs specs)
{
	if (*s != '0' && specs.flags.hashtag)
	{
		if (specs.specifier == 'x')
		{
			if (ft_putnstr("0x", 2) < 0)
				return (-1);
		}
		else if (specs.specifier == 'X')
			if (ft_putnstr("0X", 2) < 0)
				return (-1);
	}
	return (0);
}

int	print_width(int length, t_specs specs)
{
	int	width_length;

	width_length = 0;
	while (width_length < length)
	{
		if (specs.flags.leading_zeroes && specs.precision < 0)
		{
			if (ft_putchar('0') < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(' ') < 0)
				return (-1);
		}
		width_length++;
	}
	return (width_length);
}

int	calc_extra_length(char *s, t_specs specs)
{
	if (*s != '0' && (specs.specifier == 'x' || specs.specifier == 'X' )
		&& specs.flags.hashtag)
		return (2);
	return (0);
}

int	print_string(char *s, int string_length, t_specs specs)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	if (print_hex_prefix(s, specs) < 0)
		return (-1);
	if (specs.precision > string_length)
	{
		while (i < specs.precision - string_length)
		{
			if (ft_putchar('0') < 0)
				return (0);
			i++;
		}
	}
	length = ft_putnstr(s, string_length);
	if (length < 0)
		return (-1);
	return (length + i);
}
