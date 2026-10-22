/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:11:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 00:55:03 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_p(va_list args)
{
	void	*temp;

	temp = va_arg(args, void *);
	if (!temp)
	{
		temp = "(nil)";
		write(1, temp, ft_strlen(temp));
		return (ft_strlen(temp));
	}
	return (ft_putnbr_hex((unsigned long) temp, 0, 1));
}

int	format_int(va_list args)
{
	int	temp;

	temp = va_arg(args, int);
	return (ft_putnbr(temp, 0));
}

int	format_u(va_list args)
{
	unsigned int	temp;

	temp = va_arg(args, unsigned int);
	return (ft_putunbr(temp, 0));
}

int	format_x(va_list args, char format)
{
	unsigned int	temp;

	temp = va_arg(args, unsigned int);
	return (ft_putnbr_hex(temp, format == 'X', 0));
}
