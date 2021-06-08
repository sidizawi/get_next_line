/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:04:00 by szawi             #+#    #+#             */
/*   Updated: 2021/06/08 16:10:42 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_new_line(const char *s)
{
	int	i;

	i = -1;
	while (s && s[++i])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

void	ft_add_to_all(char **all, char *buff)
{
	char	*tmp;

	tmp = *all;
	*all = ft_strjoin(*all, buff);
	if (tmp)
		free(tmp);
}

static int	ft_finish_all(char **all, char **line, int cont)
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

static int	ft_free(char **temp)
{
	if (*temp)
	{
		free(*temp);
		*temp = NULL;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*all[OPEN_MAX];
	char		*buff;
	int			ret;

	buff = 0;
	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	else if (all[fd] && ft_new_line(all[fd]))
		return (ft_finish_all(&all[fd], line, 0));
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == 0 && ft_strlen(all[fd]) && ft_free(&buff))
		return (ft_finish_all(&all[fd], line, 1));
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
