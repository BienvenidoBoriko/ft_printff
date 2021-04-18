/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:37:25 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:11:33 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static inline void	ignore_ret(int i)
{
	i = 0;
}

void	ft_putnbr_fd(int n, int fd)
{
	char			caracter;
	unsigned int	nbl;

	nbl = n;
	if (n < 0)
	{
		nbl = nbl * -1;
		ignore_ret(write(fd, "-", 1));
	}
	if (nbl > 9)
	{
		ft_putnbr_fd(nbl / 10, fd);
		ft_putnbr_fd(nbl % 10, fd);
	}
	if (nbl <= 9)
	{
		caracter = nbl + 48;
		ignore_ret(write(fd, &caracter, 1));
	}
}
