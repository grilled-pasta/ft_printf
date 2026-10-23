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

size_t	format_p(va_list args)
{
	void	*temp;
	size_t	length;

	temp = va_arg(args, void *);
	length = 0;
	if (!temp)
		return (write(1, "(nil)", 5));
	length += ft_putchar('0');
	length += ft_putchar('x');
	return (ft_putnbr_base((unsigned long) temp, BASE_16_L) + length);
}

size_t	format_int(va_list args)
{
	int		temp;
	long	n;

	temp = va_arg(args, int);
	n = temp;
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr_base(-n, BASE_10));
	return (ft_putnbr_base(n, BASE_10));
}

size_t	format_u(va_list args)
{
	unsigned int	temp;

	temp = va_arg(args, unsigned int);
	return (ft_putnbr_base(temp, BASE_10));
}

size_t	format_x(va_list args, char format)
{
	unsigned int	temp;
	long			n;

	temp = va_arg(args, unsigned int);
	n = temp;
	if (format == 'X')
		return (ft_putnbr_base(n, BASE_16_U));
	return (ft_putnbr_base(n, BASE_16_L));
}
