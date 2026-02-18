/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsack <vsack@student.42vienna.com>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-17 18:03:25 by vsack             #+#    #+#             */
/*   Updated: 2026/02/18 12:54:01 by olnovyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

char	*read_line(int fd)
{
	char	*buf;
	char	c;
	int		i;
	int		res;

	buf = malloc(sizeof(char) * 16384);
	if (!buf)
		return (NULL);
	i = 0;
	c = 0;
	res = read(fd, &c, 1);
	while (res > 0 && c != '\n' && i < 16383)
	{
		buf[i++] = c;
		res = read(fd, &c, 1);
	}
	buf[i] = '\0';
	if (res < 0 || (res == 0 && i == 0) || (res == 0 && c != '\n'))
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

t_matrix	*read_matrix(int fd)
{
	t_matrix	*st;
	char		*header;
	int			i;

	header = read_line(fd);
	if (!header)
		return (NULL);
	st = malloc(sizeof(t_matrix));
	if (!st || !parse_header(header, st))
	{
		free(header);
		free(st);
		return (NULL);
	}
	free(header);
	st->m = malloc(sizeof(char *) * (st->rows + 1));
	if (!st->m)
		return (NULL);
	i = -1;
	while (++i < st->rows)
		st->m[i] = read_line(fd);
	st->m[i] = NULL;
	return (st);
}

int	**parse_matrix(t_matrix *m)
{
	int	**res;
	int	i;
	int	j;

	res = malloc(sizeof(int *) * m->rows);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < m->rows)
	{
		res[i] = malloc(sizeof(int) * m->col);
		if (!res[i])
			return (free_arr(res, i), NULL);
		j = -1;
		while (++j < m->col)
		{
			if (m->m[i][j] == m->obstacle)
				res[i][j] = 0;
			else
				res[i][j] = 1;
		}
	}
	return (res);
}
