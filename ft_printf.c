/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:19:41 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 00:49:17 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>

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
		return (format_uint(args));
	else if (format == 'x' || format == 'X')
		return (format_uint_hex(args, format));
	else if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

/* %[flags][width][.precision][length]specifier */
int	ft_printf(const char *format, ...)
{
	va_list			args;
	size_t			res;

	res = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			res += handle_formatter(*format, args);
		}
		else
		{
			write(1, format, 1);
			res++;
		}
		format++;
	}
	va_end(args);
	return (res);
}
