#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
//# define BUFFER_SIZE 10

char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	newstat(char *stat);
char	*get_next_line(int fd);

#endif