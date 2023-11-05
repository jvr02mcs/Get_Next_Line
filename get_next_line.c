#include "get_next_line.h"


int newstat(char *stat, char *linea)
{
	char *str;
	int	i;
	int j;

	i = 0;
	j = 0;
	while (stat[i] == linea[i] || stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		i++;
	if (stat[i] == '\0')
		str = ft_strdup(stat);
	else if (stat[0] == '\n')
		str = malloc(sizeof(char) * (ft_strlen(stat)));
	else
		str = malloc(sizeof(char) * (ft_strlen(stat) - i) + 1);
	while (stat[i + j] != '\0')
	{
		str[j] = stat[i + j];
		j++;
	}
	str[j] = '\0';
	j = ft_strlcpy(stat, str, j + 1);
	return (j);
}

char	*linea_hasta_n(char *linea)
{
	int	i;
	int	j;
	char *str;

	j = 0;
	i = 0;
	while(linea[i] != '\n')
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

int	leer(int fd, char *buf)
{
	int	i;

	i = read(fd, buf, BUFFER_SIZE + 1);
	buf[i] = '\0';
	return (i);
}

char *gnl(int fd)
{
	char *linea;
	static char stat[BUFFER_SIZE + 1];
	int i;

	printf("stat 1 : %s\n", stat);
	if (stat[0] != '\0')
	{
		linea = ft_strdup(stat);
		if (hay_salto(stat))
		{
			linea = linea_hasta_n(stat);
			i = newstat(stat, linea);
			return (linea);
		}
	}
		i = leer(fd, stat);
		if (linea == NULL)
			linea = ft_strdup(stat);
		else
			linea = ft_strjoin(linea, stat);
		if (hay_salto(linea))
		{
			linea = linea_hasta_n(linea);
			i = newstat(stat, linea);
			return (linea);
		}
	return (linea);
}

int	main(void)
{
	int	fd;
	int i = 3;

	fd = open("/Users/jrubio-m/Desktop/42proyects/Get_Next_Line/hola.txt", O_RDONLY);
	if (fd == -1)
		printf("error");
	else
		while (i != 0)
		{
			printf("final %i : %s\n", i, gnl(fd));
			i--;
		}
	return (0);
}