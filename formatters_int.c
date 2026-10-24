/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:11:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 03:40:28 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	format_p(va_list args, t_specs specs)
{
	void	*temp;
	int		length;
	char	buffer[67]; // "0x" + unsigned long bytes (64) + null-term

	temp = va_arg(args, void *);
	if (!temp)
		return (format_specs("(nil)", 5, specs));
	buffer[0] = '0';
	buffer[1] = 'x';
	length = ft_putnbr_base((unsigned long) temp, BASE_16_L, buffer + 2);
	buffer[length + 2] = '\0';
	if (length < 0)
		return (-1);
	return (format_specs(buffer, ft_strlen(buffer), specs));
}

int	format_int(va_list args, t_specs specs)
{
	int		temp;
	long	n;
	int		length;
	int		sign;
	char	buffer[12]; // int + minus + null-term

	temp = va_arg(args, int);
	n = temp;
	length = 0;
	sign = 0;
	if (n < 0)
	{
		buffer[0] = '-';
		sign = 1;
		n = -n;
	}
	length = ft_putnbr_base(n, BASE_10, buffer + sign);
	buffer[length + sign] = '\0';
	if (length < 0)
		return (-1);
	return (format_specs(buffer, ft_strlen(buffer), specs));
}

int	format_u(va_list args, t_specs specs)
{
	unsigned int	temp;
	int				length;
	char			buffer[12]; // int + minus + null-term

	temp = va_arg(args, unsigned int);
	length = ft_putnbr_base(temp, BASE_10, buffer);
	if (length < 0)
		return (-1);
	buffer[length] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}

int	format_x(va_list args, char format, t_specs specs)
{
	unsigned int	temp;
	long			n;
	char			*base;
	int				length;
	char			buffer[12]; // int + minus + null-term

	temp = va_arg(args, unsigned int);
	n = temp;
	length = 0;
	if (format == 'X')
		base = BASE_16_U;
	else
		base = BASE_16_L;
	length = ft_putnbr_base(n, base, buffer);
	if (length < 0)
		return (-1);
	buffer[length] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}
