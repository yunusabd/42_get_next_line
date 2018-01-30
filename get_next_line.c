/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:57:14 by yabdulha          #+#    #+#             */
/*   Updated: 2018/01/30 09:54:52 by yabdulha         ###   ########.fr       */
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
	if (lst == NULL)
		return (NULL);
	while(lst->next)
	{
		printf("List item -> str: %s:\n", ((t_fd*)lst->con)->str);
		if (((t_fd*)lst->con)->fide == fd)
		{
			printf("found fd\n");
			return (lst);
		}
		lst = lst->next;
	}
	printf("find_fd returns NULL\n");
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
	t_fd					fd_e;


	printf("gnl fd: %d:\n", fd);
	current = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE + 1);
	// try finding fd in list.
	if (head && ((current = find_fd(fd, head))))
		{
			printf("found fd\n");
			if (current->content)
				{
					printf("Rest in aktuellem fd vorhaden\n");
					ft_strcpy(*line, (char*)current->content);
					if ((position = ft_strchr(*line, '\n')))
					{
						*position = '\0';
						return (1);
					}
				}
		}
	else
	{
		fd_e.fide = fd;

		current = ft_lstnew(&fd_e, sizeof(fd_e));
		current->content = (void*)&fd_e;
		current->content_size = sizeof(fd_e);
	}
	if (!(head))
		head = current;
	else
		ft_lstadd(&head, current);
	if (head == NULL || current == NULL || current->con == NULL)
		return (-1);
	if ((ret = read(current->con->fide, current->con->str, BUFF_SIZE) <= 0))
		return (ret);
	read(current->con->fide, current->con->str, BUFF_SIZE);
	while (!(position = ft_strchr(current->con->str, '\n')) && ret >= 0)
	{
		*line = ft_strjoinfree(*line, current->con->str);
		ret = read(current->con->fide, (char*)current->content, BUFF_SIZE);
		if (ret == 0)
			return (1);
	}
	*position = '\0';
	*line = ft_strjoinfree(*line, current->con->str);
	ft_strcpy(current->con->str, position + 1);
	return (1);
}

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
	return (0);
}
