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

int	validate_matrix(t_matrix *m)
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
