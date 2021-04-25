/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:17:06 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/25 12:09:57 by bboriko-         ###   ########.fr       */
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
	char	*width;
	int		left_pads;
	char	*precision;
	int		no_name;
	int		space;
	char	specifier;
	char	*length;
	char	*specifiers;
	char	*lengths;
	int		count_chars;
}t_pf_formaters;
int				ft_printf(const	char *format, ...);
int				set_t_pf_formaters(t_pf_formaters	*pf_formaters, char *fmt);
char			*get_formats(char *fm, t_pf_formaters *pf_fters, int count);
int				aux_set_flags(char *formatter, t_pf_formaters *pf_fters);
int				set_flags(char *formatter, t_pf_formaters *pf_fters);
int				set_precision_flag(char *fm, t_pf_formaters *pf_fters);
int				set_width_flag(char *format, t_pf_formaters *pf_fters);
int				ft_format(char *fm, t_pf_formaters *pf_fters, int count);
t_pf_formaters	*init_t_pf_formaters(t_pf_formaters	*printf_formaters);

#endif