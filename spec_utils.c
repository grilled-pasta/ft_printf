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

int	calc_str_len(char *s, int length, t_specs specs)
{
	int	result_length;
	int	sign;

	result_length = 0;
	sign = (*s == '-' || *s == '+' || *s == ' ');
	if (specs.precision > length - sign)
		result_length += specs.precision - length + sign;
	result_length += length;
	return (result_length);
}

int	print_width(int length, t_specs specs)
{
	int		width_length;
	char	width_c;

	width_length = 0;
	width_c = ' ';
	if (specs.precision > 0)
		specs.flags.leading_zeroes = 0;
	if (specs.flags.leading_zeroes && specs.precision == -1)
		width_c = '0';
	while (width_length < length)
	{
		if (ft_putchar(width_c) < 0)
			return (-1);
		width_length++;
	}
	return (width_length);
}

int	print_string(char *s, int string_length, t_specs specs)
{
	int	length;
	int	zeroes;
	int	sign;

	zeroes = 0;
	sign = (*s == '-' || *s == '+' || *s == ' ');
	if (sign && !(specs.flags.leading_zeroes && specs.precision == -1)
		&& !specs.flags.left_justify)
		if (ft_putchar(*s) < 0)
			return (-1);
	if (specs.precision > string_length - sign)
	{
		while (zeroes < specs.precision - string_length + sign)
		{
			if (ft_putchar('0') < 0)
				return (-1);
			zeroes++;
		}
	}
	length = ft_putnstr(s + sign, string_length - sign);
	if (length < 0)
		return (-1);
	return (length + zeroes + sign);
}
