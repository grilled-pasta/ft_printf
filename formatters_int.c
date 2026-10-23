/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:11:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 21:26:07 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_p(va_list args)
{
	void	*temp;
	int		length;

	temp = va_arg(args, void *);
	if (!temp)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") < 0)
		return (-1);
	length = ft_putnbr_base((unsigned long) temp, BASE_16_L);
	if (length < 0)
		return (-1);
	return (length + 2);
}

int	format_int(va_list args)
{
	int		temp;
	long	n;
	int		length;
	int		res_length;

	temp = va_arg(args, int);
	n = temp;
	length = 0;
	if (n < 0)
	{
		length = ft_putchar('-');
		if (length < 0)
			return (-1);
		n = -n;
	}
	res_length = ft_putnbr_base(n, BASE_10);
	if (res_length < 0)
		return (-1);
	length += res_length;
	return (length);
}

int	format_u(va_list args)
{
	unsigned int	temp;
	int				length;

	temp = va_arg(args, unsigned int);
	length = ft_putnbr_base(temp, BASE_10);
	if (length < 0)
		return (-1);
	return (length);
}

int	format_x(va_list args, char format)
{
	unsigned int	temp;
	long			n;
	char			*base;
	int				length;

	temp = va_arg(args, unsigned int);
	n = temp;
	length = 0;
	if (format == 'X')
		base = BASE_16_U;
	else
		base = BASE_16_L;
	length = ft_putnbr_base(n, base);
	if (length < 0)
		return (-1);
	return (length);
}
