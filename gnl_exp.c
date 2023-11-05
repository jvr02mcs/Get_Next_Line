
/*
- Leer del archivo hasta encontrar un salto de linea o final del archivo (read -> 0)
- Todo lo guardamos en la estatica
-- Dividir la estatica ("Hola\nque tal\nestas"):
	· Linea que hemos leido hasta el \n ("Hola\n")
	· La estatica sin la linea ("que tal\nestas")
- Devolvemos la linea
*/

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	// Comprobar si hay linea en buffer
	if (existe_linea(buffer) == 1)
	{
		// Obtener la linea
		line = obtener_linea(buffer);

		// Eliminar la linea de buffer
		buffer = eliminar_linea(buffer);

		// Devolver linea
		return (line);
	}

	// Leemos el archivo hasta \n o read == 0
	buffer = leer_archivo(fd); // buffer = buffer + texto_leido
	if (!buffer)
		return NULL;
	// Obtener la linea
	line = obtener_linea(buffer);

	// Eliminar la linea de buffer
	buffer = eliminar_linea(buffer);

	// Devolvemos linea
	return (line);
}
/*
			write(fd, buffer, 42)
int bytes = read(fd, buffer, 42);*/
/* x = READ(...)
- x > 0: Leido y guardado x caracteres
- x = 0: no ha podido leer nada porque esta en el fina de fd
- x < 0: error (-1) 

buffer[1024]
IMPORTANTE: x = read(fd, buffer, 42);
			buffer[x] = '\0';
*/