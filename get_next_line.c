/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungurea <sungurea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:51:00 by sungurea          #+#    #+#             */
/*   Updated: 2018/09/12 18:36:03 by sungurea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*file_handle(t_list **fl, unsigned int fd)
{
	t_list		*cfl;

	cfl = *fl;
	while (cfl)
	{
		if (cfl->content_size == fd)
			return (cfl);
		cfl = cfl->next;
	}
	cfl = ft_lstnew("\0", fd);
	cfl->next = *fl;
	*fl = cfl;
	return (cfl);
}

int		content_handle(t_list *cfl, char *buf, int fd)
{
	int		rl;
	char	*tmp;

	while (!(ft_strchr(cfl->content, '\n')) && (rl = read(fd, buf, BUFF_SIZE)))
	{
		tmp = cfl->content;
		if (rl < BUFF_SIZE && (buf[rl] = '\n'))
			buf[rl + 1] = 0;
		cfl->content = ft_strjoin(tmp, buf);
	}
	if (rl <= 0)
		return (rl);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*fl;
	t_list			*cfl;
	char			*cnt;
	char			*split;

	if ((read(fd, buf, 0) < 0 && !line))
		return (-1);
	cfl = file_handle(&fl, fd);
	cnt = cfl->content;
	if (*cnt && (split = ft_strchr(cfl->content, '\n')))
	{
		*line = ft_strsub(cfl->content, 0, split - cnt);
		cfl->content = split + 1;
		return (1);
	}
	else if (content_handle(cfl, buf, fd))
		get_next_line(fd, line);
	else
		return (0);
	return (1);
}
