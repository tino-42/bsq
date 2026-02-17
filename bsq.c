/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olnovyts <olnovyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:10:49 by olnovyts          #+#    #+#             */
/*   Updated: 2026/02/16 15:03:23 by olnovyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

t_square	find_bsq(int **m, int rows, int cols)
{
	t_square	max;
	int			i;
	int			j;
	int			min;

	max = (t_square){0, 0, 0};
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (i > 0 && j > 0 && m[i][j] > 0)
			{
				min = m[i - 1][j];
				if (m[i][j - 1] < min)
					min = m[i][j - 1];
				if (m[i - 1][j - 1] < min)
					min = m[i - 1][j - 1];
				m[i][j] = min + 1;
			}
			if (m[i][j] > max.size)
			{
				max.size = m[i][j];
				max.y = i;
				max.x = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

void	fill_matrix(matrix *m_def, t_square res)
{
	int	i;
	int	j;

	i = res.y;
	while (i > res.y - res.size)
	{
		j = res.x;
		while (j > res.x - res.size)
		{
			m_def->m[i][j] = m_def->fill;
			j--;
		}
		i--;
	}
}

void	print_matrix(matrix *m_def)
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

void	free_matrix(matrix *out)
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

void	free_arr(int **arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
/*main in different file
int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	matrix		*m_def;
	int			**int_m;
	t_square	res;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			write(2, "map error\n", 10);
			i++;
			continue ;
		}
		m_def = read_matrix(fd);
		if (m_def && validate_matrix(m_def))
		{
			int_m = parse_matrix(m_def);
			if (int_m)
			{
				res = find_bsq(int_m, m_def->rows, m_def->col);
				if (res.size > 0)
					fill_matrix(m_def, res);
				print_matrix(m_def);
				free_arr(int_m, m_def->rows);
				free_matrix(m_def);
			}
			else
				write(2, "map error\n", 10);
		}
		else
			write(2, "map error\n", 10);
		close(fd);
		i++;
	}
	return (0);
}*/
