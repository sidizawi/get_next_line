/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:21:31 by szawi             #+#    #+#             */
/*   Updated: 2021/03/01 15:21:59 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_new_line(const char *s)
{
	int i;

	i = -1;
	while (s && s[++i])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

void			ft_add_to_all(char **all, char *buff)
{
	char *tmp;

	tmp = *all;
	*all = ft_strjoin(*all, buff);
	if (tmp)
		free(tmp);
}

static int		ft_finish_all(char **all, char **line, int cont)
{
	ft_add_to_line(all, line);
	if (cont && !*all && *line)
		return (0);
	else if (*line)
		return (1);
	if (*all)
		free(*all);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	static char	*all[OPEN_MAX];
	char		*buff;
	int			ret;

	buff = 0;
	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	else if (all[fd] && ft_new_line(all[fd]))
		return (ft_finish_all(&all[fd], line, 0));
	else if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	else if ((ret = read(fd, buff, BUFFER_SIZE)) == 0 && ft_strlen(all[fd]))
	{
		free(buff);
		return (ft_finish_all(&all[fd], line, 1));
	}
	if (ret >= 0)
		buff[ret] = 0;
	while (ret > 0 && !ft_new_line(buff))
	{
		ft_add_to_all(&all[fd], buff);
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
	}
	return (ft_check(ret, &all[fd], line, buff));
}
