/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:37:28 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 03:39:00 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

// int	ft_putnbr_base_x(unsigned long n, char *base, char *buffer)
// {
// 	int		length;
// 	size_t	base_length;
// 	int		temp;
//
// 	temp = 0;
// 	length = 0;
// 	base_length = ft_strlen(base);
// 	if (n >= base_length)
// 	{
// 		temp = ft_putnbr_base_x(n / base_length, base, buffer);
// 		if (temp < 0)
// 			return (temp);
// 		length = temp;
// 	}
// 	buffer[length] = base[n % base_length];
// 	return (length + 1);
// }

int	main(void)
{
	// int	res;
	// res = ft_printf("(nil)\n");
	// printf("res = %d", res);

	// void	*p;
	// char	buff[67];
	//
	// p = "TEST";
	// buff[0] = '0';
	// buff[1] = 'x';
	// int res = ft_putnbr_base_x((unsigned long) p, BASE_16_L, buff + 2);
	// buff[res + 2] = '\0';
	// printf("BUFFER: %s\tRES: %d\n", buff, res);
	// printf("%p", p);
	//

	// void	*p;
	//
	// p = "TEST";
	// printf("[%5d]\n", 42); // ___42
	// printf("[%2d]\n", 42); // 42
	// printf("[%8s]\n", "hi"); // ______hi
	// printf("[%5c]\n", 'A'); // ____A
	// printf("[%8x]\n", 42); // 2a
	// printf("[%3u]\n", 42); // _42
	// int res_og = printf("[%9p]\n", p);
	//
	// ft_printf("[%5d]\n", 42); // ___42
	// ft_printf("[%2d]\n", 42); // 42
	// ft_printf("[%8s]\n", "hi"); // ______hi
	// ft_printf("[%5c]\n", 'A'); // ____A
	// ft_printf("[%8x]\n", 42); // 2a____
	// ft_printf("[%3u]\n", 42); // _42
	// int res = ft_printf("[%9p]\n", p);
	//
	// printf("res_og = %d, res = %d\n", res_og, res);

	// printf("[%-5d]\n", 42); // 42___
	// printf("[%-8s]\n", "hi"); // hi______
	// printf("[%-5c]\n", 'A'); // A____
	// printf("[%-6x]\n\n", 42); // 2a____
	//
	// ft_printf("[%-5d]\n", 42); // 42___
	// ft_printf("[%-8s]\n", "hi"); // hi______
	// ft_printf("[%-5c]\n", 'A'); // A____
	// ft_printf("[%-6x]\n\n", 42); // 2a____

	// printf("%05d\n", 42); // 00042
	// printf("%08x\n", 42); // 0000002a
	// printf("%05d\n", -42); // -0042
	// printf("%03d\n\n", 1234); // 1234
	//
	// ft_printf("%05d\n", 42); // 00042
	// ft_printf("%08x\n", 42); // 0000002a
	// ft_printf("%05d\n", -42); // -0042
	// ft_printf("%03d\n\n", 1234); // 1234

	// printf("[%.3s]\n", "hello"); // hel
	// printf("[%.0s]\n", "hello"); // empty output
	// printf("[%8.3s]\n", "hello"); // _____hel
	// printf("[%-8.3s]\n\n", "hello"); // hel_____
	//
	// ft_printf("[%.3s]\n", "hello"); // hel
	// ft_printf("[%.0s]\n", "hello"); // empty output
	// ft_printf("[%8.3s]\n", "hello"); // _____hel
	// ft_printf("[%-8.3s]\n\n", "hello"); // hel_____

	// printf("%#x\n", 42); // 0x2a
	// printf("%#X\n", 42); // 0x2A
	// printf("%#x\n", 0); // 0
	// printf("%#o\n\n", 42); // 052

	// printf("%+d\n", 42); // +42
	// printf("%+d\n", -42); // -42
	// printf("%+d\n", 42); // 42
	// printf("% d\n", 42); // -42
	// printf("%+6d\n\n", 42); // ___+42
	// printf("%+d\n", 42); // +42
	// ft_printf("%+d\n", -42); // -42
	// ft_printf("%+d\n", 42); // 42
	// ft_printf("% d\n", 42); // -42
	// ft_printf("%+6d\n\n", 42); // ___+42
	//
	// {
	// 	int res1 = printf(" %09d %010d %011d %012d %013d %014d %015d\n\n", \
	// 			INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// 	int res2 = ft_printf(" %09d %010d %011d %012d %013d %014d %015d\n\n", \
	// 			INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//
	// 	printf("%d == %d\n", res1, res2);
	// }
	
	// int res1 = printf("42%+5d42\n", 0);
	// int res2 = ft_printf("42%+5d42\n", 0);
	// printf("%d = %d", res1, res2);
}
