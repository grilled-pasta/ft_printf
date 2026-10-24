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

int	format_min_width(char **s, int length, t_specs specs)
{
	int 	str_length;
	int		i;

	str_length = length;
	i = 0;
	while (specs.min_width - i > str_length && !specs.flags.left_justify)
	{
		if (spec_isint(specs.specifier) && specs.flags.leading_zeroes)
		{	
			if (**s == '-')
			{
				if (ft_putchar('-') < 0)
					return (-1);
				(*s)++;
			}
			if (ft_putchar('0') < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(' ') < 0)
				return (-1);
		}
		i++;
	}
	return (i);
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
	if (specs.min_width)
		w_length += format_min_width(&s, length, specs);
	if (length == 1)
	{
		if (ft_putchar(*s) < 0)
			return (-1);
	}
	else 
		if (ft_putstr(s) < 0)
			return (-1);
	if (specs.flags.left_justify)
		w_length += format_min_width_left_justify(length, specs);
	return (w_length + s_length);
}
