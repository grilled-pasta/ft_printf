/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_specs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:57:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 03:56:10 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	spec_isint(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int	format_min_width(char **s, int length, char pad_c, t_specs specs)
{
	int 	str_length;
	int		i;
	int		sign;

	str_length = length;
	i = 0;
	sign = 0;
	if (spec_isint(specs.specifier) && **s != '-' && (specs.flags.plus || specs.flags.space))
		sign = 1;
	while (specs.min_width - i - sign > str_length && !specs.flags.left_justify)
	{			
		if (spec_isint(specs.specifier) && specs.flags.leading_zeroes)
		{			
			// if (specs.flags.plus)
			// {
			// 	if (ft_putchar('+') < 0)
			// 		return (-1);
			// 	(*s)++;
			// } 
			// else if (specs.flags.space)
			// {
			// 	if (ft_putchar(' ') < 0)
			// 		return (-1);
			// 	(*s)++;
			// }
			if (**s == '-')
			{
				if (ft_putchar('-') < 0)
					return (-1);
				(*s)++;
			}
			if (ft_putchar(pad_c) < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(pad_c) < 0)
				return (-1);
		}
		i++;
	}	
	if (spec_isint(specs.specifier))
	{
		if (specs.flags.plus)
		{
			if (ft_putchar('+') < 0)
				return (-1);
		} 
		else if (specs.flags.space)
		{
			if (ft_putchar(' ') < 0)
				return (-1);
		}
	}
	return (i + sign);
}

int	format_min_width_left_justify(int length, t_specs specs)
{
	int 	str_length;
	int		i;

	str_length = length;
	i = 0;
	while (specs.min_width - i > str_length && specs.flags.left_justify)
	{
		if (ft_putchar(' ') < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	format_specs(char *s, int length, t_specs specs)
{
	int		w_length;
	int		s_length;

	w_length = 0;
	s_length = length;
	// printf("\n~~leading_zeroes: %d\n", specs.flags.leading_zeroes);
	// printf("~~spec_isint(%c) %d\n", specs.specifier, spec_isint(specs.specifier));
	// printf("~~specs.flags.left_justify: %d\n", specs.flags.left_justify);
	// printf("~~precision: %d\n", specs.precision);
	if (specs.precision >= 0)
		if (specs.precision < s_length && specs.specifier == 's')
			s_length = specs.precision;
	if (specs.min_width)
	{
		if (spec_isint(specs.specifier) && specs.flags.leading_zeroes
				&& !specs.flags.left_justify && specs.precision < 0) 
			w_length += format_min_width(&s, s_length, '0', specs);
		else
			w_length += format_min_width(&s, s_length, ' ', specs);
	}
	if (ft_putnstr(s, s_length + 1) < 0)
			return (-1);
	if (specs.flags.left_justify)
		w_length += format_min_width_left_justify(s_length, specs);
	return (w_length + s_length);
}
