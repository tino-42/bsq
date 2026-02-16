#ifndef LIB_H
# define LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> // TODO: delete me
typedef struct matrix_t
{
	char	**m;
	int rows;
	char obstacle;
	char space;
	char fill;
} matrix;

int	ft_atoi(char *str);
char	*read_line(int fd);
matrix	*read_matrix(int fd);
int		**parse_matrix(matrix *m);   
#endif