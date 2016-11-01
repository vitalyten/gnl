/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:26:49 by vtenigin          #+#    #+#             */
/*   Updated: 2016/10/29 22:59:56 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check(char **line, t_file *file)
{
	char	*end;
	char	*tmp;

	end = ft_strchr(file->str, '\n');
	if (end)
	{
		*end = '\0';
		end++;
		*line = ft_strdup(file->str);
		tmp = ft_strdup(end);
		ft_strdel(&(file->str));
		file->str = tmp;
        ft_strdel(&tmp);
		return (1);
	}
	if (ft_strlen(file->str) > 0)
	{
		*line = ft_strdup(file->str);
		*(file->str) = '\0';
		return (1);
	}
	return (0);
}

t_file	*ft_newfile(int fd)
{
    t_file	*list;

    if (!(list = (t_file *)ft_memalloc(sizeof(t_file))))
        return (NULL);
    list->fd = fd;
    list->str = ft_strnew(0);
    list->next = NULL;
    return (list);
}

int			 get_next_line(const int fd, char **line)
{
	static t_file	*list = NULL;
	t_file			*start;
	t_file			*tlist;
	long long		len;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
    if (!list)
	    list = ft_newfile(fd);
    start = list;
	while (list->next && list->fd != fd)
		list = list->next;
	if (list->fd != fd)
    {
        list->next = ft_newfile(fd);
        list = list->next;
    }

	while(!ft_strchr(list->str, '\n'))
	{
		len = read(fd, buf, BUFF_SIZE);
		if (len == -1)
			return (-1);
		if (len == 0)
            break ;
		buf[len] = '\0';
		tmp = ft_strjoin(list->str, buf);
		ft_strdel(&(list->str));
		list->str = tmp;
        ft_strdel(&(tmp));
	}
    tlist = list;
    list = start;
	return (check(line, tlist));
}
