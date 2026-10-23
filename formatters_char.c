/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:52:53 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 21:27:37 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list args)
{
	char	temp;

	temp = (char) va_arg(args, int);
	return (ft_putchar(temp));
}

int	format_s(va_list args)
{
	char	*temp;
	int		length;

	temp = (char *) va_arg(args, char *);
	if (!temp)
		temp = "(null)";
	length = ft_putstr(temp);
	if (length < 0)
		return (-1);
	return (length);
}
