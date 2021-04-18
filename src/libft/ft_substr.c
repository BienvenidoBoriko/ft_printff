/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:14:34 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:17:05 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ref;
	size_t	cont;

	if (s == NULL)
		return (NULL);
	cont = 0;
	if (((int)start) > ft_strlen(s))
	{
		ref = ft_substr("\0", 0, 1);
		return (ref);
	}
	ref = malloc(len * sizeof(char) + 1);
	if (!(ref))
		return (NULL);
	while (cont < len)
	{
		ref[cont] = s[start + cont];
		cont++;
	}
	ref[cont] = '\0';
	return (ref);
}
