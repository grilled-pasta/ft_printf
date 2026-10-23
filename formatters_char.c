/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:52:53 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 00:53:16 by alkonsta         ###   ########.fr       */
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
	length = ft_strlen(temp);
	write(1, temp, length);
	return (length);
}
