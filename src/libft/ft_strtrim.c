/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:49:35 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:17:58 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comprobar(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
		{
			return (-1);
		}
		set++;
	}
	return (1);
}

static int	get_ini(char const *s1, char const *set)
{
	int	i;
	int	ini;

	i = 0;
	ini = 0;
	while (s1[i] != '\0')
	{
		if (comprobar(s1[i], set) == 1)
		{
			ini = i;
			return (ini);
		}
		i++;
	}
	return (ini);
}

static int	get_fin(char const *s1, char const *set)
{
	int	fin;
	int	len;

	len = ft_strlen(s1) - 1;
	fin = 0;
	while (s1[len] != '\0')
	{
		if (comprobar(s1[len], set) == 1)
		{
			fin = len;
			return (++fin);
		}
		len--;
	}
	return (fin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	char	*ref;
	int		ini;
	int		fin;

	ini = 0;
	fin = 0;
	if (s1 != NULL)
	{
		ini = get_ini(s1, set);
		fin = get_fin(s1, set);
		trimed = (char *)malloc((fin - ini) * sizeof(char) + 1);
		ref = trimed;
		if (trimed == NULL)
			return (NULL);
		while (ini < fin)
		{
			*trimed = s1[ini];
			trimed++;
			ini++;
		}
		*trimed = '\0';
		return (ref);
	}
	return (NULL);
}
