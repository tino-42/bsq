
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

matrix  *read_matrix(int fd)
{
	char    *header;
	matrix  *st;
	int     i;

	header = read_line(fd);
	if (!header)
		return (NULL);

	st = malloc(sizeof(matrix));
	if (!st) {
		free(header);
		return (NULL);
	}
	parse_header(header, st);
	st->m = malloc(sizeof(char *) * (st->rows + 1));
	free(header);
	if (!st->m) {
		free(st);
		return (NULL);
	}

	i = 0;
	while (i < st->rows)
	{
		st->m[i] = read_line(fd);
		if (i == 0 && st->m[i])
			st->col = ft_strlen(st->m[i]);
		i++;
	}
	st->m[i] = NULL;
	return (st);
}
