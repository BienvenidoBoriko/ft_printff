/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:30:38 by bboriko-          #+#    #+#             */
/*   Updated: 2021/05/09 21:29:56 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	argc = 0;
	*argv = NULL;
	ft_printf("%+0u", 16);
	printf("%+0d", 16);
	//printf("hola %10c!!%p∫", "boss", 8);
	/**
	 * printf("%s", "hello word");
	 * printf("%d", ft_strlen("hola"));
	 */
	return (1);
}
