/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:19:41 by alkonsta          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/10/23 00:49:17 by alkonsta         ###   ########.fr       */
=======
/*   Updated: 2026/10/24 01:07:18 by alkonsta         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <limits.h>

int	handle_formatter(const char **format, va_list args)
{
	t_specs	specs;

	specs = parse_specs(format);
	if (specs.specifier == 'c')
		return (format_c(args, specs));
	else if (specs.specifier == 's')
		return (format_s(args, specs));
	else if (specs.specifier == 'p')
		return (format_p(args, specs));
	else if (specs.specifier == 'd' || specs.specifier == 'i')
		return (format_int(args, specs));
	else if (specs.specifier == 'u')
		return (format_u(args, specs));
	else if (specs.specifier == 'x' || specs.specifier == 'X')
		return (format_x(args, specs));
	else if (specs.specifier == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	handle_error(int error)
{
	errno = error;
	ft_putnstr("Error!\n", 7);
	return (error);
}

<<<<<<< HEAD
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
	return (0);
}

/* %[flags][width][.precision][length]specifier */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	length;
=======
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		temp;
>>>>>>> main

	length = 0;
	va_start(args, format);
	while (format && *format)
	{
<<<<<<< HEAD
		if (*format == '%')
		{
			format++;
			length += handle_formatter(*format, args);
		}
		else
			length += ft_putchar(*format);
=======
		if (*format == '%' && *(format + 1))
		{
			format++;
			temp = handle_formatter(&format, args);
		}
		else
			temp = ft_putchar(*format);
		if (temp < 0)
			return (va_end(args), handle_error(temp));
		if (INT_MAX - length < temp)
			return (va_end(args), handle_error(EOVERFLOW));
		length += temp;
>>>>>>> main
		format++;
	}
	va_end(args);
	return (length);
}
