/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:39:33 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:13:21 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	temp;

	temp = (char)c;
	while (*str != temp)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
