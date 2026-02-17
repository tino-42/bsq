/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olnovyts <olnovyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:10:49 by olnovyts          #+#    #+#             */
/*   Updated: 2026/02/17 20:00:36 by olnovyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

int	get_min_neighbor(int **m, int i, int j)
{
	int	min;

	min = m[i - 1][j];
	if (m[i][j - 1] < min)
		min = m[i][j - 1];
	if (m[i - 1][j - 1] < min)
		min = m[i - 1][j - 1];
	return (min);
}

t_square	find_bsq(int **m, int rows, int cols)
{
	t_square	max;
	int			i;
	int			j;

	max = (t_square){0, 0, 0};
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (i > 0 && j > 0 && m[i][j] > 0)
				m[i][j] = get_min_neighbor(m, i, j) + 1;
			if (m[i][j] > max.size)
				max = (t_square){m[i][j], i, j};
		}
	}
	return (max);
}

// fill from the bottom right corner (backwards)
void	fill_matrix(t_matrix *m_def, t_square res)
{
	int	i;
	int	j;

	i = 0;
	while (i < res.size)
	{
		j = 0;
		while (j < res.size)
		{
			m_def->m[res.y - i][res.x - j] = m_def->fill;
			j++;
		}
		i++;
	}
}

void	print_matrix(t_matrix *m_def)
{
	int	i;

	i = 0;
	while (i < m_def->rows)
	{
		write(1, m_def->m[i], m_def->col);
		write(1, "\n", 1);
		i++;
	}
}

void	free_matrix(t_matrix *out)
{
	int	i;

	if (!out)
		return ;
	if (out->m)
	{
		i = 0;
		while (i < out->rows)
		{
			free(out->m[i]);
			i++;
		}
		free(out->m);
	}
	free(out);
}
