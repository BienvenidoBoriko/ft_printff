/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:55:59 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:09:00 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *orig, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	cc;

	cc = (unsigned char)c;
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)orig;
	while (n > 0)
	{
		*p1 = *p2;
		if (*p2 == cc)
			return (++p1);
		p1++;
		p2++;
		n--;
	}
	return (NULL);
}
