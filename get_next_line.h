/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:56:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/02/04 16:10:04 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 7
# define FD_ELEM ((t_fd*)current->content)
# include <unistd.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_fd
{
	int		fide;
	char	*rest;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
