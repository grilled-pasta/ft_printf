/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:52:53 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 03:47:36 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	format_c(va_list args, t_specs specs)
{
	char	temp;
	char	str[2];
	int		length;

	temp = (unsigned char) va_arg(args, int);
	str[0] = temp;
	str[1] = '\0';
	length = format_specs(str, 1, specs);
	if (length < 0)
		return (length);
	return (length);
}

int	format_s(va_list args, t_specs specs)
{
	char	*temp;

	temp = (char *) va_arg(args, char *);
	if (!temp)
		temp = "(null)";
	return (format_specs(temp, ft_strlen(temp), specs));
}
