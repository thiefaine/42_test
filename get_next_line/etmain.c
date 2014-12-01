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

int		main(void)
{
	int		ret;
	char	*line;

	printf("\n\n\033[35m---------------Tests d'erreur---------------\033[0m\n");
	printf("\n-----Passage de fd arbitraire-----\n");
	ret = get_next_line(512, &line);
	printf("ret : %d\n", ret);
	return (0);

}
