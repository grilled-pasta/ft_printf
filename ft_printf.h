/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:20:52 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 21:14:34 by alkonsta         ###   ########.fr       */
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
int		ft_putchar(char c);
int		ft_putstr(char	*s);
int		ft_putnbr_base(unsigned long n, char *base);
// formatters_char 
int		format_c(va_list args);
int		format_s(va_list args);
// formatters_int
int		format_p(va_list args);
int		format_int(va_list args);
int		format_u(va_list args);
int		format_x(va_list args, char format);

#endif
