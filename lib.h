#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <stdio.h> // TODO: delete me
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

char		*read_line(int fd);
matrix		*read_matrix(int fd);
int			**parse_matrix(matrix *m);
// helpers
int			ft_strlen(const char *s);
int			ft_atoi(char *str);
int			validate_matrix(matrix *m);
int	parse_header(const char *hdr, matrix *out);
#endif
