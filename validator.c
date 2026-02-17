/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsack <vsack@student.42vienna.com>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-16 23:22:35 by vsack             #+#    #+#             */
/*   Updated: 2026-02-16 23:22:35 by vsack            ###   ########42vienna  */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	line_chars_valid(const char *str, char space, char obstacle)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != space && str[i] != obstacle)
			return (0);
		i++;
	}
	return (1);
}
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
int	parse_header(const char *hdr, matrix *out)
{
	int		len;
	int		rows;
	char	sp;
	char	ob;
	char	fi;

	if (!hdr || !out)
		return (0);
	len = ft_strlen(hdr);
	if (len < 4)
		return (0);
	sp = hdr[len - 3];
	ob = hdr[len - 2];
	fi = hdr[len - 1];
	if (!is_printable(sp) || !is_printable(fi) || !is_printable(ob))
		return (0);
	if ((sp == ob) || (sp == fi) || (ob == fi))
		return (0);
	if (!parse_pos_int_pre(hdr, len - 3, &rows))
		return (0);
	out->rows = rows;
	out->space = sp;
	out->obstacle = ob;
	out->fill = fi;
	out->col = 0;
	out->m = NULL;
	return (1);
}

int	validate_matrix(matrix *m)
{
	int	i;
	int	col;

	if (!m || !m->m || m->rows <= 0)
		return (0);
	if (!m->m[0])
		return (0);
	col = ft_strlen(m->m[0]);
	if (col <= 0)
		return (0);
	i = 0;
	while (i < m->rows)
	{
		if (!m->m[i])
			return (0);
		if (ft_strlen(m->m[i]) != col)
			return (0);
		if (!line_chars_valid(m->m[i], m->space, m->obstacle))
			return (0);
		i++;
	}
	if (m->m[m->rows] != NULL)
		return (0);
	m->col = col;
	return (1);
}
