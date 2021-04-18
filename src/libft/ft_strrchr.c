/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:46:19 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:18:11 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	temp;
	char			*aux;
	int				si;

	si = 0;
	temp = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == temp)
		{
			aux = (char *)str;
			si = 1;
		}
		str++;
	}
	if (si == 1)
		return (aux);
	else if (*str == temp)
		return ((char *)str);
	else
		return (0);
}
