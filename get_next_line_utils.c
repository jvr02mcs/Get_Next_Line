#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c])
		c++;
	return (c);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	c = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		str[i + c] = s2[c];
		c++;
	}
	str[i + c] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[c] != '\0' && c < n - 1)
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (ft_strlen(src));
}

void	newstat(char *stat)
{
	while (stat[0] != '\0' && stat[0] != '\n')
		ft_strlcpy(stat, stat + 1, ft_strlen(stat));
	if (stat[0] == '\n')
		ft_strlcpy(stat, stat + 1, ft_strlen(stat));
}
