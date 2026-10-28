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
	if (specs.precision >= 0 && specs.precision < string_length)
		string_length = specs.precision;
	if (specs.flags.left_justify)
		ft_putnstr(s, string_length);
	while (width_length < specs.min_width - string_length)
	{
		if (ft_putchar(' ') < 0)
			return (-1);
		width_length++;
	}
	if (!specs.flags.left_justify)
		ft_putnstr(s, string_length);
	return (string_length + width_length);
}

int	format(char *s, int length, t_specs specs)
{
	int		width_length;
	int		string_length;
	int		extra_length;
	int		sign;

	width_length = 0;
	sign = print_sign(s, specs); // TODO: print sign wit the string not here 
	string_length = length;
	extra_length = calc_extra_length(s, specs);
	if (*s == '-')
	{
		s++;
		string_length--;
	}
	if (specs.flags.left_justify)
		if ((string_length = print_string(s, string_length, specs)) < 0)
			return (0);
	width_length = print_width(specs.min_width - string_length - sign
			- extra_length, specs);
	if (width_length < 0)
		return (-1);
	if (!specs.flags.left_justify)
		if ((string_length = print_string(s, string_length, specs)) < 0)
			return (0);
	return (width_length + string_length + sign + extra_length);
}

int	format_specs(char *s, int length, t_specs specs)
{
	if (specs.specifier == 's' || specs.specifier == 'c')
		return (format_string(s, length, specs));
	return (format(s, length, specs));
}
