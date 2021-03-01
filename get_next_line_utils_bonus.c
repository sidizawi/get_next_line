/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:04:30 by szawi             #+#    #+#             */
/*   Updated: 2021/03/01 15:14:02 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	else if (!(str = malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(const char *all, const char *buff)
{
	size_t	len;
	char	*str;
	int		j;

	if (!buff)
		return (NULL);
	len = ft_strlen(all) + ft_strlen(buff) + 1;
	if (!(str = malloc(len)))
		return (NULL);
	len = 0;
	while (all && all[len])
	{
		str[len] = all[len];
		len++;
	}
	j = 0;
	while (buff[j])
		str[len++] = buff[j++];
	str[len] = '\0';
	return (str);
}

void	ft_add_to_line(char **all, char **line)
{
	char	*tmp;
	size_t	i;

	tmp = *all;
	if (!*all)
		*line = ft_strdup("", '\n');
	else
		*line = ft_strdup(*all, '\n');
	i = ft_strlen(*line) + 1;
	if (*line && i < ft_strlen(*all))
		*all = ft_strdup(&(*all)[i], '\0');
	else
		*all = NULL;
	if (tmp)
		free(tmp);
}

int		ft_check(int ret, char **all, char **line, char *buff)
{
	if (ret >= 0)
	{
		if (ft_strlen(buff))
			ft_add_to_all(all, buff);
		ft_add_to_line(all, line);
		free(buff);
		buff = NULL;
		if (*line && !*all && ret == 0)
			return (0);
		else if (*line)
			return (1);
	}
	else if (ret < 0 && *all)
		free(all);
	free(buff);
	buff = NULL;
	return (-1);
}
