/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:17:06 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 17:10:31 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include "./../src/libft/libft.h"
# include <stdarg.h>

typedef struct s_printf_formaters
{
	int		left_justify;
	int		sign;
	int		with;
	int		left_pads;
	int		precision;
	char	specifier;
	char	*length;
	char	*specifiers;
	char	*lengths;
	int		count_chars;
}t_pf_formaters;
int	ft_printf(const	char *format, ...);

#endif