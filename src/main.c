/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsack <vsack@student.42vienna.com>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-17 17:53:12 by vsack             #+#    #+#             */
/*   Updated: 2026-02-17 17:53:12 by vsack            ###   ########42vienna  */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

static void	print_map_error(void)
{
	write(1, "map error\n", 10);
}

static void	process_fd(int fd)
{
	t_matrix	*m_def;
	int			**int_m;
	t_square	res;

	m_def = read_matrix(fd);
	if (!m_def || !validate_matrix(m_def))
	{
		free_matrix(m_def);
		print_map_error();
		return ;
	}
	int_m = parse_matrix(m_def);
	if (!int_m)
	{
		free_matrix(m_def);
		print_map_error();
		return ;
	}
	res = find_bsq(int_m, m_def->rows, m_def->col);
	if (res.size > 0)
		fill_matrix(m_def, res);
	print_matrix(m_def);
	free_arr(int_m, m_def->rows);
	free_matrix(m_def);
}

// TODO: some BSQ test may fail.
int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 1)
	{
		process_fd(0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			print_map_error();
		else
		{
			process_fd(fd);
			close(fd);
		}
		if (i + 1 < argc)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
