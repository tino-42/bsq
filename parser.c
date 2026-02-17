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

static int	get_cell_value(char c, matrix *m)
{
	if (c == m->space)
		return (1);
	if (c == m->obstacle)
		return (0);
	return (-1);
}

int	**parse_matrix(matrix *m)
{
	int	**int_m;
	int	i;
	int	j;

	if (!m || !m->m || m->rows <= 0)
		return (NULL);
	int_m = malloc(sizeof(int *) * m->rows);
	if (!int_m)
		return (NULL);
	i = -1;
	while (++i < m->rows)
	{
		if (ft_strlen(m->m[i]) != m->col)
			return (NULL);
		int_m[i] = (int *)malloc(sizeof(int) * m->col);
		if (!int_m[i])
			return (NULL);
		j = -1;
		while (++j < m->col)
		{
			int_m[i][j] = get_cell_value(m->m[i][j], m);
			if (int_m[i][j] == -1)
				return (NULL);
		}
	}
	return (int_m);
}
