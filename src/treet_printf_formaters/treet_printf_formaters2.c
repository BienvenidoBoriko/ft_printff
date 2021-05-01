/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treet_printf_formaters2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:04:51 by bboriko-          #+#    #+#             */
/*   Updated: 2021/05/01 19:44:15 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_printf.h"

int	aux_set_length(char *fmt, t_pf_formaters *pf_fters)
{
	int	legth_setet;

	legth_setet = 0;
	if (ft_strnstr(fmt, "ll", ft_strlen(fmt)))
	{
		free(pf_fters->length);
		pf_fters->length = ft_strdup("ll");
		legth_setet += 2;
	}
	if (ft_strnstr(fmt, "hh", ft_strlen(fmt)))
	{
		free(pf_fters->length);
		pf_fters->length = ft_strdup("hh");
		legth_setet += 2;
	}
	return (legth_setet);
}

int	set_length(char *fmt, t_pf_formaters *pf_fters)
{
	int	legth_setet;

	legth_setet = 0;
	if (ft_strrchr(fmt, 'l'))
	{
		free(pf_fters->length);
		pf_fters->length = ft_strdup("l");
		legth_setet++;
	}
	if (ft_strrchr(fmt, 'h'))
	{
		free(pf_fters->length);
		pf_fters->length = ft_strdup("h");
		legth_setet++;
	}
	legth_setet += aux_set_length(fmt, pf_fters);
	if (legth_setet > 1)
		return (-1);
	return (legth_setet);
}

int	set_specifier(char *formatter, t_pf_formaters *pf_fters)
{
	int	len;

	len = ft_strlen(formatter);
	if (*formatter == '\0')
		return (-1);
	pf_fters->specifier = formatter[len - 1];
	return (1);
}

t_pf_formaters	*init_t_pf_formaters(t_pf_formaters	*printf_formaters)
{
	printf_formaters->specifiers = ft_strdup("cspdiuxX%nfge");
	printf_formaters->lengths = ft_strdup("l ll h hh");
	printf_formaters->length = ft_strdup("");
	printf_formaters->left_justify = 0;
	printf_formaters->sign = 0;
	printf_formaters->width = ft_strdup("");
	printf_formaters->no_name = 0;
	printf_formaters->space = 0;
	printf_formaters->left_pads = 0;
	printf_formaters->precision = ft_strdup("");
	printf_formaters->specifier = '\0';
	return (printf_formaters);
}
