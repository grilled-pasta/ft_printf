/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:20:52 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 00:54:47 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_10	"0123456789"
# define BASE_16_L	"0123456789abcdef"
# define BASE_16_U	"0123456789ABCDEF"

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
// str_utils
size_t	ft_strlen(const char *s);
size_t	ft_putchar(char c);
size_t	ft_putnbr_base(unsigned long n, char *base);
// formatters_char 
size_t	format_c(va_list args);
size_t	format_s(va_list args);
// formatters_int
size_t	format_p(va_list args);
size_t	format_int(va_list args);
size_t	format_u(va_list args);
size_t	format_x(va_list args, char format);

#endif
