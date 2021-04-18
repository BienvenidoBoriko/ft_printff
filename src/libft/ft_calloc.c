/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:13:40 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:03:56 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*array;
	size_t			cont;

	array = (unsigned char *)malloc(num * size);
	if (array == NULL)
		return (NULL);
	cont = 0;
	while (cont < (num * size))
	{
		((unsigned char *)array)[cont] = '\0';
		cont++;
	}
	return (array);
}
