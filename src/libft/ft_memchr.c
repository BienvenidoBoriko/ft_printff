/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:56:14 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:09:11 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	p2;

	p1 = (unsigned char *)str;
	p2 = (unsigned char)c;
	while (n > 0)
	{
		if (*p1 == p2)
			return (p1);
		p1++;
		n--;
	}
	return (0);
}
