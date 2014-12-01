#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "get_next_line.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;
	char	buf[33];
	int		nb_read;

	if (ac > 1)
	{
		printf("\n\n\033[31m---------------Tests avances---------------\033[0m\n");
		printf("\n-----Affichage d'une ligne de 4 caracteres depuis un fichier-----\n");
		fd = open(av[1], O_RDONLY);
		i = 0;
		while (get_next_line(fd, &line))
			printf("line %d : %s\n", ++i, line);
		close(fd);
		printf("\n-----Fichier de depart-----\n");
		fd = open(av[1], O_RDONLY);
		while ((nb_read = read(fd, buf, 32)))
		{
			buf[nb_read] = '\0';
			printf("%s", buf);
		}
		close(fd);

		printf("\n-----Affichage de deux lignes de 4 caracteres depuis un fichier-----\n");
		fd = open(av[2], O_RDONLY);
		i = 0;
		while (get_next_line(fd, &line))
			printf("line %d : %s\n", ++i, line);
		close(fd);
		printf("\n-----Fichier de depart-----\n");
		fd = open(av[2], O_RDONLY);
		while ((nb_read = read(fd, buf, 32)))
		{
			buf[nb_read] = '\0';
			printf("%s", buf);
		}
		close(fd);

		printf("\n-----Affichage de plusieurs lignes de 4 caracteres depuis un fichier-----\n");
		fd = open(av[3], O_RDONLY);
		i = 0;
		while (get_next_line(fd, &line))
			printf("line %d : %s\n", ++i, line);
		close(fd);
		printf("\n-----Fichier de depart-----\n");
		fd = open(av[3], O_RDONLY);
		while ((nb_read = read(fd, buf, 32)))
		{
			buf[nb_read] = '\0';
			printf("%s", buf);
		}
		close(fd);
	//	sleep(5);

		printf("\n-----Affichage d'une ligne de 4 caracteres sans \\n depuis un fichier-----\n");
		fd = open(av[4], O_RDONLY);
		i = 0;
		while (get_next_line(fd, &line))
			printf("line %d : %s\n", ++i, line);
		close(fd);
		printf("\n-----Fichier de depart-----\n");
		fd = open(av[4], O_RDONLY);
		while ((nb_read = read(fd, buf, 32)))
		{
			buf[nb_read] = '\0';
			printf("%s\n", buf);
		}
		close(fd);

		printf("\n-----Affichage d'une ligne de 8 caracteres sans \\n depuis un fichier-----\n");
		fd = open(av[5], O_RDONLY);
		i = 0;
		while (get_next_line(fd, &line))
			printf("line %d : %s\n", ++i, line);
		close(fd);
		printf("\n-----Fichier de depart-----\n");
		fd = open(av[5], O_RDONLY);
		while ((nb_read = read(fd, buf, 32)))
		{
			buf[nb_read] = '\0';
			printf("%s\n", buf);
		}
		close(fd);

		printf("\n-----Affichage d'une ligne de 16 caracteres sans \\n depuis un fichier-----\n");
		fd = open(av[6], O_RDONLY);
		i = 0;
		while (get_next_line(fd, &line))
			printf("line %d : %s\n", ++i, line);
		close(fd);
		printf("\n-----Fichier de depart-----\n");
		fd = open(av[6], O_RDONLY);
		while ((nb_read = read(fd, buf, 32)))
		{
			buf[nb_read] = '\0';
			printf("%s\n", buf);
		}
		close(fd);
	}
	else
	{
		fd = 0;
		i = 0;
		while (get_next_line(fd, &line))
			printf("line %d : %s\n", ++i, line);
		printf("\n-----Fichier de depart-----\n");
	}
	return (0);
}
