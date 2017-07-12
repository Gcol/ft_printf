/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 06:03:03 by gcollett          #+#    #+#             */
/*   Updated: 2017/03/31 11:09:56 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_memory		*free_factory(t_memory *save)
{
	t_memory	*tmp;

	tmp = NULL;
	if (save->prev)
		(save->prev)->next = save->next;
	if (save->prev)
		tmp = (save->prev);
	else if (save->next)
		tmp = save->next;
	save->buf[0] = '\0';
	free(save->buf);
	free(save);
	return (tmp);
}

t_memory		*init_struct(t_memory *save, int fd)
{
	t_memory			*recup;

	recup = save;
	if (save)
	{
		while (save->prev && save->fd != fd)
			save = save->prev;
		while (save->next && save->fd != fd)
			save = save->next;
	}
	if (!save || save->fd != fd)
	{
		save = malloc(sizeof(t_memory));
		save->fd = (int)fd;
		save->prev = recup;
		if (recup)
			recup->next = save;
		save->next = NULL;
		save->pm = 1;
		save->buf = ft_memalloc(BUFF_SIZE + 1);
	}
	return (save);
}

static int		ft_attrib(char **line, t_memory *save, int cmp, int p)
{
	while (p != -1)
	{
		while (save->buf[p] != '\n' && save->buf[p])
			line[0][cmp++] = save->buf[p++];
		line[0][cmp] = (save->buf[p] == '\n') ? '\0' : line[0][cmp];
		if (save->buf[p] != '\n')
			*line = ft_realloc(*line, cmp + 1, BUFF_SIZE, 1);
		p = (save->buf[p] == '\n') ? -1 : 0;
		if (p == 0 && (save->pm = read(save->fd, save->buf, BUFF_SIZE)) == 0)
		{
			p = -1;
			if (!save->buf[0])
			{
				save = free_factory(save);
				return (0);
			}
		}
		save->buf[save->pm] = (p == 0) ? '\0' : save->buf[save->pm];
	}
	cmp = &(*ft_strchr(save->buf, '\n')) - &(*save->buf) + 1;
	while (cmp > 0 && p++ < save->pm - cmp)
		save->buf[p] = save->buf[cmp + p];
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static	t_memory	*save;

	if (fd < 0 || !BUFF_SIZE || BUFF_SIZE < 1 || !line)
		return (-1);
	save = init_struct(save, fd);
	if (save->pm < 1 && save->buf[0] == '\0')
	{
		return (save->pm);
	}
	if (save->pm < 1)
		return (save->pm);
	if (save->buf[0] == '\0')
		if ((save->pm = read(save->fd, save->buf, BUFF_SIZE)) < 1)
		{
			*line = NULL;
			save = free_factory(save);
			return (read(fd, "", BUFF_SIZE));
		}
	*line = ft_memalloc(BUFF_SIZE + 1);
	save->pm = (ft_strlen(save->buf) > 0) ? ft_strlen(save->buf) : 1;
	return (ft_attrib(line, save, 0, 0));
}
