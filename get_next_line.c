#include "get_next_line.h"

static void	newstat(char *stat)
{
	while (stat[0] != '\0' && stat[0] != '\n')
		ft_strlcpy(stat, stat + 1, ft_strlen(stat));
	if (stat[0] == '\n')
		ft_strlcpy(stat, stat + 1, ft_strlen(stat));
}

static char	*linea_hasta_n(char *linea)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (linea[i] != '\n')
		i++;
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
	free (linea);
	return (str);
}

static int	hay_salto(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	leer(int fd, char *stat)
{
	char	aux[BUFFER_SIZE + 1];
	char	*aux2;
	int		i;

	i = read(fd, aux, BUFFER_SIZE);
	if (i < 0)
		return (-1);
	aux[i] = '\0';
	if (stat[0] == '\0')
		ft_strlcpy(stat, aux, ft_strlen(aux) + 1);
	else
	{
		aux2 = ft_strjoin(stat, aux);
		ft_strlcpy(stat, aux2, ft_strlen(aux2) + 1);
		free(aux2);
	}
	return (i);
}

char	*crear_linea(char *linea, char *stat)
{
	if (linea == NULL)
			linea = ft_strdup(stat);
	else
	{
		free(linea);
		linea = ft_strdup(stat);
	}
	return (linea);
}
char	*get_next_line(int fd)
{
	char		*linea;
	static char	stat[BUFFER_SIZE + 1];
	int			i;

//	system("leaks a.out");
	i = 1;
	linea = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (i != 0)
	{
		if (!hay_salto(stat))
			i = leer(fd, stat);
		if (i < 0 || stat[0] == '\0')
			return (NULL);
		linea = crear_linea(linea, stat);
		if (hay_salto(linea))
			break ;
	}
	if (hay_salto(linea))
		linea = linea_hasta_n(linea);
//	printf("--------------------------------------------------------------\n");
//	system("leaks a.out");
	newstat(stat);
	return (linea);
}

// int	main(void)
// {
// 	int	fd;
// 	int i = 3;

// 	fd = open("/Users/jrubio-m/Desktop/42proyects/42cursus/Get_Next_Line/hola.txt", O_RDONLY);
// 	// if (fd == -1)
// 	// 	printf("error");
// 	// else
// 	while (i != 0)
// 	{
// 		printf("final %i : %s\n", i, get_next_line(fd));
// 		i--;
// 	}
// 	return (0);
// }