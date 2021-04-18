/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:04:31 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:09:27 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	char		*lasts;
	char		*lastd;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = src;
	d = dest;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		lasts = (char *)(s + (len - 1));
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
