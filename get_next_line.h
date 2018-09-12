/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:48:54 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/12 18:21:44 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 1000
# define MALLCHK(x) if (!x) return (-1);

typedef struct		s_lst
{
	char			*content;
	int				sep;
	int				fd;
	struct s_list	*next;
}					t_lst;

int		get_next_line(const int fd, char **line);
#endif
