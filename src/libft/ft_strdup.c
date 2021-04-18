/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:14:09 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:13:36 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	char	*ref;

	ref = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ref);
}

char	*ft_strdup(const char *str1)
{
	char	*ref;

	ref = malloc(ft_strlen(str1) * sizeof(char) + 1);
	if (ref == NULL)
		return (NULL);
	else
		return (ft_strcpy(ref, str1));
}
