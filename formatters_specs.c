/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_specs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:57:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/29 00:12:43 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_string(char *s, int lenght, t_specs specs)
{
	int	width_length;
	int	string_length;

	width_length = 0;
	string_length = lenght;
	if (specs.precision == 0 && specs.specifier != 'c')
		string_length = 0;
	if (specs.precision > 0 && specs.precision < string_length
		&& specs.specifier != 'c')
		string_length = specs.precision;
	if (specs.flags.left_justify && (specs.precision != 0
			|| specs.specifier == 'c'))
		ft_putnstr(s, string_length);
	while (width_length < specs.min_width - string_length)
	{
		if (ft_putchar(' ') < 0)
			return (-1);
		width_length++;
	}
	if (!specs.flags.left_justify && (specs.precision != 0
			|| specs.specifier == 'c'))
		ft_putnstr(s, string_length);
	return (string_length + width_length);
}

int	format(char *s, int length, t_specs specs)
{
	int		width_length;
	int		result_length;
	int		sign;

	if (specs.precision == 0 && *s == '0')
		length = 0;
	sign = (*s == '-' || *s == '+' || *s == ' ');
	if (specs.flags.left_justify)
	{
		if (sign)
			if (ft_putchar(*s) < 0)
				return (-1);
		result_length = print_string(s, length, specs);
		width_length = print_width(specs.min_width - result_length, specs);
	}
	else
	{
		result_length = calc_str_len(s, length, specs);
		if (sign && specs.flags.leading_zeroes && specs.precision == -1)
			if (ft_putchar(*s) < 0)
				return (-1);
		width_length = print_width(specs.min_width - result_length, specs);
		result_length = print_string(s, length, specs);
	}
	return (width_length + result_length);
}

int	format_specs(char *s, int length, t_specs specs)
{
	if (specs.specifier == 's' || specs.specifier == 'c')
		return (format_string(s, length, specs));
	return (format(s, length, specs));
}
