/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:37:28 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 22:14:54 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	// int	res;
	// res = ft_printf("(nil)\n");
	// printf("res = %d", res);
	printf("[%5d]\n", 42); // ___42
	printf("[%2d]\n", 42); // 42
	printf("[%8s]\n", "hi"); // ______hi
	printf("[%5c]\n", 'A'); // ____A
	printf("[%8x]\n\n", 42); // 2a
						 
	// printf("%-5d\n", 42); // 42___
	// printf("%-8s\n", "hi"); // hi______
	// printf("%-5c\n", 'A'); // A____
	// printf("%-6x\n\n", 42); // 2a____
	//
	// printf("%05d\n", 42); // 00042
	// printf("%08x\n", 42); // 0000002a
	// printf("%05d\n", -42); // -0042
	// printf("%03d\n\n", 1234); // 1234
	//
	// printf("%.3s\n", "hello"); // hel
	// printf("%.0s\n", "hello"); // empty output
	// printf("%8.3s\n", "hello"); // _____hel
	// printf("%-8.3s\n\n", "hello"); // hel_____
	//
	// printf("%#x\n", 42); // 0x2a
	// printf("%#X\n", 42); // 0x2A
	// printf("%#x\n", 0); // 0
	// printf("%#o\n\n", 42); // 052
	//
	// printf("%+d\n", 42); // +42
	// printf("%+d\n", -42); // -42
	// printf("%+d\n", 42); // 42
	// printf("% d\n", -42); // -42
	// printf("%+6d\n\n", 42); // ___+42
}
