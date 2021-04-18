/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:20:29 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:13:49 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strcat(char *dest, const char *src)
{
	char	*c_s1;

	c_s1 = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c_s1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		t_len;
	int		s_len;

	if (s1 != NULL && s2 != NULL)
	{
		t_len = ft_strlen(s1);
		s_len = ft_strlen(s2);
		join = (char *)malloc(((t_len + s_len) * sizeof(char)) + 1);
		if (join == NULL)
			return (NULL);
		join[0] = '\0';
		ft_strcat(join, s1);
		ft_strcat(join, s2);
		return (join);
	}
	else if (s1 == NULL)
		return ((char *)s2);
	else
		return ((char *)s1);
}
