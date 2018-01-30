/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:56:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/01/30 13:06:41 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 3
# define con content
# define cs content_size
# include <unistd.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_fd
{
	int		fide;
	char	*str;
}				t_fd;

int				get_next_line(const int fd, char **line);
char			*ft_strjoinfree(char *s1, const char *s2);

#endif
