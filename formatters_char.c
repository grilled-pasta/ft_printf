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

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	format_c(va_list args)
{
	char	temp;

	temp = (char) va_arg(args, int);
	return (put_char(temp));
}

int	format_s(va_list args)
{
	char	*temp;
	size_t	len;

	temp = (char *) va_arg(args, char *);
	if (!temp)
		temp = "(null)";
	len = ft_strlen(temp);
	write(1, temp, len);
	return (len);
}
