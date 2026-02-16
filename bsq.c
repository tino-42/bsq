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

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	matrix	*m;

	i = 1;
	while (i < argc)
	{
		printf("---------- argc: %d ----------\n", i);
		fd = open(argv[i], O_RDONLY);
		m = read_matrix(fd);
		parse_matrix(m);
		i++;
	}
	return (0);
}
