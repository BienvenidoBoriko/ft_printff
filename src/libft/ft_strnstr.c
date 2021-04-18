/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:55:21 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:23:14 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, int len1)
{
	int		cont2;
	int		cont;
	int		len;
	int		cont3;

	cont = 0;
	cont3 = 0;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (haystack[cont] != '\0' && cont3 < len1)
	{
		cont2 = 0;
		while ((cont + cont2) < len1 && needle[cont2] != '\0'
			&& (haystack[cont + cont2] == needle[cont2]))
		{
			if (len == ++cont2)
				return ((char *)&haystack[cont]);
		}
		cont++;
		cont3++;
	}
	return (NULL);
}
