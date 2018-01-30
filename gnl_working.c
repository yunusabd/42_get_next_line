/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:57:14 by yabdulha          #+#    #+#             */
/*   Updated: 2018/01/28 23:38:10 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*new;
	int		i;
	int		len1;
	int		len;
	char	*tmp;

	if (!(s1 && s2))
		return (NULL);
	tmp = s1;
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	i = 0;
	if (!(new = (char*)malloc(sizeof(*new) * len + 1)))
		return (NULL);
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (len1 <= len)
	{
		new[len1] = s2[i];
		i++;
		len1++;
	}
	free(tmp);
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rest;
	char		*position;
	int			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE + 1);
	if (rest)
	{
		ft_strcpy(*line, rest);
		if (ft_strchr(*line, '\n'))
		{
			position = ft_strchr(*line, '\n');
			*position = '\0';
			return (1);
		}
	}
	else if (!(rest = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((ret = read(fd, rest, BUFF_SIZE)) <= 0)
		return (ret);
	while (!(position = ft_strchr(rest, '\n')) && ret >= 0)
	{
		*line = ft_strjoinfree(*line, rest);
		ret = read(fd, rest, BUFF_SIZE);
		if (ret == 0)
			return (1);
	}
	*position = '\0';
	*line = ft_strjoinfree(*line, rest);
	ft_strcpy(rest, position + 1);
	return (1);
}
