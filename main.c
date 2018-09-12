/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 10:23:55 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/12 18:31:23 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int		main()
{
	int		fd;
	int		fd2;
	int 	i = 4;
	char	*line;

	line = malloc(sizeof(char*));
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text.1.txt", O_RDONLY);
	printf("%ld[%d][%d]\n", read(100, line, 0), fd, fd2);
	while (i--)
	{
		if (get_next_line(fd, &line))
			printf("[%s]\n", line);
		if (get_next_line(fd2, &line))
			printf(" || [%s]\n", line);
	}
	close(fd);
		
}