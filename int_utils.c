/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:58:11 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/23 22:13:21 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	ft_isdigit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }

typedef struct s_flags
{
	int	left_justify;	// - left justify (right is default)
	int	leading_zeroes; // 0 only int, ignored is left_justify present or for
						// ints if precision is specified
	int	plus; 			// + only signed int, ignored by others
	int	hashtag;		// # alternative conversion, only non-decimal integer
}				t_flags;

typedef struct	s_format
{
	t_flags	flags;
	int		min_width; // int or '*' padded with space chars
	int		precision; // .(int or *) default is 0, negative is ignored
	int		length;    // size of the argument?
	char	conversion_specifier; // the format used, if invalid => undefined
}				t_format;


