/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olnovyts <olnovyts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:00:05 by olnovyts          #+#    #+#             */
/*   Updated: 2026/02/17 21:00:08 by olnovyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct matrix_t
{
	char	**m;
	int		rows;
	int		col;
	char	obstacle;
	char	space;
	char	fill;
}			matrix;

typedef struct s_square
{
	int		size;
	int		y;
	int		x;
}			t_square;

// Core Logic
t_square	find_bsq(int **m, int rows, int cols);
matrix		*read_matrix(int fd);
int			**parse_matrix(matrix *m);
void		fill_matrix(matrix *m_def, t_square res);
void		print_matrix(matrix *m);

// Memory Management
void		free_matrix(matrix *out);
void		free_arr(int **arr, int rows);

// Helpers & Validation
char		*read_line(int fd);
int			ft_strlen(const char *s);
int			ft_atoi(char *str);
int			validate_matrix(matrix *m);
int			parse_header(const char *hdr, matrix *out);

#endif
