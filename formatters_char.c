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
	write(1, &temp, sizeof(char));
	return (1);
}

int	format_s(va_list args)
{
	char	*temp;

	temp = (char *) va_arg(args, char *);
	if (!temp)
		temp = "(null)";
	write(1, temp, ft_strlen(temp));
	return (ft_strlen(temp));
}
