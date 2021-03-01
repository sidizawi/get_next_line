/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:21:36 by szawi             #+#    #+#             */
/*   Updated: 2021/02/19 18:30:07 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(const char *all, const char *buff);
char	*ft_strdup(const char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_add_to_line(char **all, char **line);
void	ft_add_to_all(char **all, char *buff);
int		ft_check(int ret, char **all, char **line, char *buff);

#endif
