#include "lib.h"

char	*read_line(int fd)
{
	int		i;
	char	c;
	char	*buffer;

	buffer = malloc(1024);
	i = 0;
	if (!buffer)
		return (NULL);
	while (read(fd, &c, 1) > 0 && c != '\n')
		buffer[i++] = c;
	buffer[i] = '\0';
	return (buffer);
}

matrix	*read_matrix(int fd)
{
	char	*header;
	int		row_count;
	int		i;
	matrix	*st;

	header = read_line(fd);
	if (!header)
		return (NULL);
	row_count = ft_atoi(header);
	st = malloc(sizeof(matrix));
	st->m = malloc(sizeof(char *) * (row_count + 1));
    st->space = header[1];
    st->obstacle = header[2];
    st->fill = header[3]; // TODO: fix me pls, i dont work and will break with >1 digit row_count 
    free(header);
    if (!st->m)
		return (NULL);
	i = 0;
	while (i < row_count)
	{
		st->m[i] = read_line(fd);
		i++;
	}
	st->rows = row_count;
	st->m[i] = NULL;
	return (st);
}

int	**parse_matrix(matrix *m)
{
    int i;

    i = 0;
	printf("Rows: %d | Obstacle: %c | Fill with: %c\n", m->rows, m->obstacle, m->fill);
	for (int i = 0; i < m->rows; i++)
	{
		printf("%s\n", m->m[i]);
	}
	return (0);
}
