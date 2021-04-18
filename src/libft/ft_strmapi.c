/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:53:40 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:23:43 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*copi;
	int		cont;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	copi = (char *)malloc(len * sizeof(char) + 1);
	if (copi == NULL)
		return (NULL);
	cont = 0;
	while (s[cont] != '\0')
	{
		copi[cont] = f(cont, s[cont]);
		cont++;
	}
	copi[cont] = '\0';
	return (copi);
}
