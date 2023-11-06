#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
#include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 10

char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
#endif