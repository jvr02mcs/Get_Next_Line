#include "get_next_line.h"

static char	*linea_hasta_n(char *linea)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	while (linea[i] != '\n' && linea[i])
		i++;
	if (linea[i] == 0)
		return (linea);
	i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	while (i > 0)
	{
		str[j] = linea[j];
		j++;
		i--;
	}
	str[j] = '\0';
	return (free (linea), str);
}

static int	hay_salto(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	leer(int fd, char *stat)
{
	int		i;

	i = read(fd, stat, BUFFER_SIZE);
	if (i < 0)
		return (-1);
	stat[i] = '\0';
	return (i);
}

char	*crear_linea(char *linea, char *stat, int i)
{
	char	*aux;

	if (!linea)
	{
		if (i <= 0)
		{
			stat[0] = '\0';
			return (NULL);
		}
		aux = ft_strdup(stat);
	}
	else
	{
		if (i < 0)
		{
			stat[0] = '\0';
			return (free(linea), NULL);
		}
		aux = ft_strjoin(linea, stat);
		free(linea);
	}
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*linea;
	static char	stat[BUFFER_SIZE + 1];
	int			i;

	i = 1;
	linea = NULL;
	if (fd < 0)
		return (NULL);
	if (stat[0])
		linea = crear_linea(linea, stat, 1);
	while (i != 0)
	{
		if (!hay_salto(stat))
			i = leer(fd, stat);
		linea = crear_linea(linea, stat, i);
		if (!linea)
			return (NULL);
		if (hay_salto(linea))
			break ;
	}
	linea = linea_hasta_n(linea);
	newstat(stat);
	return (linea);
}

// int	main(void)
// {
// 	int	fd;
// 	int i = 3;

// 	fd = open("/Users/jrubio-m/Desktop/42proyects/42cursus/GNL/hola.txt", O_RDONLY);
// 	// if (fd == -1)
// 	// 	printf("error");
// 	// else
// 	char *line;
// 	while (i != 0)
// 	{
// 		line = get_next_line(fd);
// 		printf("final %i : %s\n", i, line);
// 		free(line);
// 		i--;
// 	}
// 	return (0);
// }