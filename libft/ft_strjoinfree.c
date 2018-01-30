/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:32:17 by yabdulha          #+#    #+#             */
/*   Updated: 2018/01/28 19:46:41 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
