/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:19:41 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/16 22:34:33 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>

// %[flags][width][.precision][length]specifier
int	ft_printf(const char *format, ...)
{
	va_list			args;
	void			*temp;
	char			temp_c;
	int				temp_i;
	unsigned int	temp_ui;
	size_t			res;

	temp = NULL;
	res = 0;
	temp_c = 0;
	temp_i = 0;
	temp_ui = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
			res++;
			continue ;
		}
		if (!*(format + 1))
			break ;
		format++;
		if (*format == 'c')
		{
			temp_c = (char) va_arg(args, int);
			write(1, &temp_c, sizeof(char));
			res++;
		}
		else if (*format == 's')
		{
			temp = (char *) va_arg(args, char *);
			if (!temp)
				temp = "(null)";
			write(1, temp, ft_strlen(temp));
			res += ft_strlen(temp);
		} 
		else if (*format == 'p')
		{
			temp = va_arg(args, void *);
			if (!temp)
			{
				temp = "(nil)";
				write(1, temp, ft_strlen(temp));
				res += ft_strlen(temp);
			}
			else
				res += ft_putnbr_hex((unsigned long) temp, 0, 1);
		}
		else if (*format == 'd' || *format == 'i')
		{
			temp_i = va_arg(args, int);
			res += ft_putnbr(temp_i, 0);
		}
		else if (*format == 'u')
		{
			temp_ui = va_arg(args, unsigned int);
			res += ft_putunbr(temp_ui, 0);
		}
		else if (*format == 'x' || *format == 'X')
		{
			temp_ui = va_arg(args, unsigned int);
			res += ft_putnbr_hex(temp_ui, *format == 'X', 0);
		} else if (*format == '%')
		{
			write(1, format, 1);
			res++;
		}
		format++;
	}
	va_end(args);
	return (res);
}
