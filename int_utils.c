/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:58:11 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 01:23:04 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_isdigit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }

// typedef struct s_flags
// {
// 	int	left_justify;	// - left justify (right is default)
// 	int	leading_zeroes; // 0 only int, ignored is left_justify present or for
// 						// ints if precision is specified
// 	int	plus; 			// + only signed int, ignored by others
// 	int	hashtag;		// # alternative conversion, only non-decimal integer
// }				t_flags;

// typedef struct	s_specs
// {
// 	// t_flags	flags;
// 	int		min_width; // int or '*' padded with space chars
// 	int		precision; // .(int or *) default is 0, negative is ignored
// 	int		length;    // size of the argument?
// 	char	specifier; // the format used, if invalid => undefined
// }				t_specs;

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == '#');
}

t_flags		parse_flags(const char **format)
{
	t_flags	flags = {
		.left_justify=0, 
		.leading_zeroes=0, 
		.plus=0, 
		.hashtag = 0
	};
	while (**format && is_flag(**format))
	{
		if (**format == '-')
			flags.left_justify = 1;
		else if (**format == '0')
			flags.leading_zeroes = 1;
		else if (**format == '+')
			flags.plus = 1;
		else if (**format == '#')
			flags.hashtag = 1;
		(*format)++;
	}
	return (flags);	
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%');
}

#include <stdio.h>

t_specs	parse_specs(const char **format)
{
	// t_specs	specs;
	int		width;
	t_flags	flags;

	flags = parse_flags(format);
	t_specs specs = {
		.flags=flags, 
		.min_width=0,
		.precision=0,
		.length=0,
		.specifier=0
	};

	// if (**format == '-')
	// {
	// 	specs.flags.left_justify = 1;
	// 	(*format)++;
	// }
	width = 0;
	while (**format && ft_isdigit(**format))
	{
		width = width * 10 + (**format - '0');
		(*format)++;
	}
	specs.min_width = width;
	// check others
	if (**format && ft_isspec(**format))
		specs.specifier = **format;
	return (specs);
}
