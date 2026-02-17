/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsack <vsack@student.42vienna.com>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-16 23:07:25 by vsack             #+#    #+#             */
/*   Updated: 2026-02-16 23:07:25 by vsack            ###   ########42vienna  */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	parse_pos_int_pre(const char *s, int len, int *out)
{
	long	n;
	int		i;

	if (len <= 0)
		return (0);
	n = 0;
	i = 0;
	while (i < len)
	{
		if (!is_digit(s[i]))
			return (0);
		n = n * 10 + (s[i] - '0');
		if (n > 2147483647)
			return (0);
		i++;
	}
	if (n <= 0)
		return (0);
	*out = (int)n;
	return (1);
}

static int	extractor(const char *hdr, int len, matrix *out)
{
	out->space = hdr[len - 3];
	out->obstacle = hdr[len - 2];
	out->fill = hdr[len - 1];
	if (!is_printable(out->space) || !is_printable(out->obstacle)
		|| !is_printable(out->fill))
		return (0);
	if (out->space == out->obstacle || out->space == out->fill
		|| out->obstacle == out->fill)
		return (0);
	return (1);
}

int	parse_header(const char *hdr, matrix *out)
{
	int	len;
	int	rows;

	if (!hdr || !out)
		return (0);
	len = ft_strlen(hdr);
	if (len < 4)
		return (0);
	if (!extractor(hdr, len, out))
		return (0);
	if (!parse_pos_int_pre(hdr, len - 3, &rows))
		return (0);
	out->rows = rows;
	out->col = 0;
	out->m = NULL;
	return (1);
}
