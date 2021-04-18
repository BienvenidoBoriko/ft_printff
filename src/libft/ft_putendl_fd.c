/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:33:47 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:11:26 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static inline void	ignore_ret(int i)
{
	i = 0;
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			ignore_ret(write(fd, &(*s), 1));
			s++;
		}
		ignore_ret(write(fd, "\n", 1));
	}
}
