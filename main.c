#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int i = 3;

	fd = open("introducir_archivo", O_RDONLY);
	// if (fd == -1)
	// 	printf("error");
	// else
	while (i != 0)
	{
		printf("final %i : %s\n", i, get_next_line(fd));
		i--;
	}
	return (0);
}