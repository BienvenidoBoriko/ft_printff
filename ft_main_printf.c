/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:30:38 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/24 17:58:54 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	main(int argc, char **argv)
{
	argc = 0;
	*argv = NULL;
	ft_printf("hola %10.*srfrf numero %sasfdsfsdf", "boss", "diez");
	/**
	 * printf("%s", "hello word");
	 * printf("%d", ft_strlen("hola"));
	 */
	return (1);
}
