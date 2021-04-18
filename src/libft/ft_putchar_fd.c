/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:15:39 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:11:17 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static inline void	ignore_ret(int i)
{
	i = 0;
}

void	ft_putchar_fd(char c, int fd)
{
	ignore_ret(write(fd, &c, 1));
}
