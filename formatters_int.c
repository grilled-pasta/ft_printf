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

int	format_p(va_list args, t_specs specs)
{
	void	*temp;
	int		length;
	char	buffer[67];
	int		sign;

	temp = va_arg(args, void *);
	sign = 2;
	if (!temp)
		return (format_specs("(nil)", 5, specs));
	buffer[0] = '0';
	buffer[1] = 'x';
	length = ft_putnbr_base((unsigned long) temp, BASE_16_L, buffer + sign);
	buffer[length + sign] = '\0';
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
	char	buffer[12];

	temp = va_arg(args, int);
	n = temp;
	length = 0;
	sign = 0;
	if (n == 0 && specs.precision == 0)
		return (buffer[0] = '\0', format_specs(buffer, 0, specs));
	if (n < 0)
	{
		buffer[0] = '-';
		sign = 1;
		n = -n;
	}	
	else if (specs.flags.plus)
	{
		buffer[0] = '+';
		sign = 1;
	}
	else if (specs.flags.space)
	{
		buffer[0] = ' ';
		sign = 1;
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
	char			buffer[12];
	int				sign;

	temp = va_arg(args, unsigned int);
	length = 0;
	sign = 0;
	if (specs.flags.plus)
	{
		buffer[0] = '+';
		sign = 1;
	}
	else if (specs.flags.space)
	{
		buffer[0] = ' ';
		sign = 1;
	}
	length = ft_putnbr_base(temp, BASE_10, buffer + sign);
	if (length < 0)
		return (-1);
	buffer[length + sign] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}

int	format_x(va_list args, t_specs specs)
{
	long			temp;
	char			*base;
	int				length;
	char			buffer[14];
	int				sign;

	temp = (long) va_arg(args, unsigned int);
	length = 0;
	sign = 0;
	if (specs.specifier == 'X')
		base = BASE_16_U;
	else
		base = BASE_16_L;
	if (specs.flags.hashtag && temp)
	{
		buffer[0] = '0';
		buffer[1] = specs.specifier;
		sign += 2;
	}
	length = ft_putnbr_base(temp, base, buffer + sign);
	if (length < 0)
		return (-1);
	buffer[length + sign] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}
