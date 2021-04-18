/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:36:59 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/13 20:20:31 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + ft_strlen(src));
	else
		return (len_dst + ft_strlen(src));
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len;

	len = get_len(dst, src, dstsize);
	if (dstsize > 0)
	{
		while (*dst != '\0' && dstsize > 0)
		{
			dst++;
			dstsize--;
		}
		if (dstsize > 1)
		{
			while (*src != '\0' && dstsize > 1)
			{
				*dst = *src;
				dst++;
				src++;
				dstsize--;
			}
			*dst = '\0';
		}
	}
	return (len);
}
