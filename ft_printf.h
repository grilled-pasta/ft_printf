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

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
// str_utils
size_t	ft_strlen(const char *s);
int		ft_putnbr_hex(unsigned long n, int hex_case, int is_p);
int		ft_putnbr(int n, int length);
int		ft_putunbr(unsigned int n, int length);
// formatters_char 
int		format_c(va_list args);
int		format_s(va_list args);
// formatters_int
int		format_p(va_list args);
int		format_int(va_list args);
int		format_uint(va_list args);
int		format_uint_hex(va_list args, char format);

#endif
