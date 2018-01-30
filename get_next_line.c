/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:57:14 by yabdulha          #+#    #+#             */
/*   Updated: 2018/01/30 13:11:57 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
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
*/

/* Function to find fd in lst. */

struct s_list		*find_fd(int fd, t_list *lst)
{
	while(lst)
	{
		if (((t_fd*)lst->con)->fide == fd)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

/* Save fd (int) in content_size element in s_list struct libft.
** That way I can use the libft list functions.
** Each time gnl is called, scan the list to check if fd exists.
*/

int					get_next_line(const int fd, char **line)
{
	static t_list			*head;
	char					*position;
	int						ret;
	t_list					*current;
	t_fd					*fd_e;

	current = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (head && ((current = find_fd(fd, head))))
		{
			if (((t_fd*)current->con)->str)
			{
				ft_strcpy(*line, ((t_fd*)current->con)->str);
				if ((position = ft_strchr(*line, '\n')))
				{
					*position = '\0';
					ft_strcpy(((t_fd*)current->con)->str, position + 1);
					return (1);
				}
			}
		}
	else
	{
		fd_e = malloc(sizeof(t_fd));
		fd_e->fide = fd;
		fd_e->str = NULL;
		current = ft_lstnew((void*)fd_e, sizeof(fd_e));
	}
	if (!(head))
		head = current;
	else
		ft_lstadd(&head, current);
	if (head == NULL || current == NULL || current->con == NULL)
		return (-1);
	((t_fd*)current->con)->str = malloc(sizeof(char) * BUFF_SIZE);
	if ((ret = read(fd, ((t_fd*)current->con)->str, BUFF_SIZE)) <= 0)
	{
		free(((t_fd*)current->con)->str);
		return (ret);
	}
	while (!(position = ft_strchr(((t_fd*)current->con)->str, '\n')) && ret > 0)
	{
		*line = ft_strjoinfree(*line, ((t_fd*)current->con)->str);
		ret = read(fd, ((t_fd*)current->con)->str, BUFF_SIZE);
	}
	if (ret == 0)
		return (1);
	*position = '\0';
	*line = ft_strjoinfree(*line, ((t_fd*)current->con)->str);
	ft_strcpy(((t_fd*)current->con)->str, position + 1);
	return (1);
}
/*
int					main()
{
	char			*line;
	int				fd;
	int				fd2;

	fd = open("testfile", O_RDONLY);
	fd2 = open("testfile2", O_RDONLY);
	get_next_line(fd, &line);
	printf("Result: [%s]\n", line);
	get_next_line(fd2, &line);
	printf("Result: [%s]\n", line);
	get_next_line(fd, &line);
	printf("Result: [%s]\n", line);
	get_next_line(fd2, &line);
	printf("Result: [%s]\n", line);
	get_next_line(fd, &line);
	printf("Result: [%s]\n", line);
	return (0);
}
*/
