/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:40:44 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/07 19:21:26 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char		*p1;
	const unsigned char	*p2;

	if (source == NULL && destination == NULL)
		return (NULL);
	p1 = (unsigned char *)destination;
	p2 = (const unsigned char *)source;
	while (num > 0)
	{
		*p1 = *p2;
		p1++;
		p2++;
		num--;
	}
	return (destination);
}
