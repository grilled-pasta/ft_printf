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

int	ft_printf(const char *format, ...)
{
	va_list	val;
	
	va_start(val, format);

	int n = va_arg(val, int);

	write(1, format, ft_strlen(format));
	
	va_end(val);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("TEST");
}
