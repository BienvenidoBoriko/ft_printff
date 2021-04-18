/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:36:27 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:12:56 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_c(char *s, char c)
{
	int	len;
	int	cont;

	len = 0;
	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] != c && (s[cont + 1] == c || s[cont + 1] == '\0'))
		{
			len++;
		}
		cont++;
	}
	return (len);
}

int	get_len_str(const char *s, int start, char c)
{
	int	len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

static void	aux_ft_split(char **str, char c, const char *s)
{
	int	cont3;
	int	cont2;

	cont3 = 0;
	cont2 = 0;
	while (s[cont3])
	{
		if (s[cont3] != c && (s[cont3 - 1] == c || s[cont3 - 1] == '\0'))
		{
			str[cont2] = ft_substr(s, cont3, get_len_str(s, cont3, c));
			cont2++;
		}
		cont3++;
	}
	str[cont2] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*ref;
	int		len;

	if (!s)
		return (NULL);
	ref = (char *)s;
	len = num_c(ref, c);
	str = (char **)malloc((len + 1) * sizeof(char **));
	if (str == NULL)
		return (NULL);
	aux_ft_split(str, c, ref);
	return (str);
}
