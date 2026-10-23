/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:19:41 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 22:15:25 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>

int	handle_formatter(char format, va_list args)
{
	if (format == 'c')
		return (format_c(args));
	else if (format == 's')
		return (format_s(args));
	else if (format == 'p')
		return (format_p(args));
	else if (format == 'd' || format == 'i')
		return (format_int(args));
	else if (format == 'u')
		return (format_u(args));
	else if (format == 'x' || format == 'X')
		return (format_x(args, format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	handle_error(int error)
{
	errno = error;
	return (error);
}

/* %[flags][width][.precision][length]specifier */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		temp;

	length = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			temp = handle_formatter(*format, args);
		}
		else
			temp = ft_putchar(*format);
		if (temp < 0)
			return (va_end(args), handle_error(temp));
		if (INT_MAX - length < temp)
			return (va_end(args), handle_error(EOVERFLOW));
		length += temp;
		format++;
	}
	va_end(args);
	return (length);
}
