/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:36:00 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/15 15:52:41 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include "libft.h"

int		main(int ac, char **av)
{
	FILE	*file = NULL;
	int		i = -1;
	int		j = -1;
	int		r;

	srand(time(NULL));
	if (ac != 2 && !av[1])
		return (0);
	file = fopen(av[1], "w");
	while (i++ < 250)
	{
		j = -1;
		while (j++ < 250)
		{
			r = rand() % 100;
			fputs(ft_itoa(r), file);
			fputs(" ", file);
		}
		fputs("\n", file);
	}
	fclose(file);
	return (0);
}
