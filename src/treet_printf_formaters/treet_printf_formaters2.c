/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treet_printf_formaters2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:04:51 by bboriko-          #+#    #+#             */
/*   Updated: 2021/05/09 20:12:09 by bboriko-         ###   ########.fr       */
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

int	set_length_aux(char *fmt, t_pf_formaters *pf_fters, char *str)
{
	if (pf_fters->length[0] != '\0')
		return (-1);
	free(pf_fters->length);
	pf_fters->length = ft_strdup(str);
	return (1);
}

int	set_length_aux2(char *fmt, t_pf_formaters *pf_fters, int cont)
{
	int	setted;

	setted = 0;
	if (fmt[cont] == 'l' && fmt[cont + 1] != 'l' && fmt[cont - 1] != 'l')
	{
		if (set_length_aux(fmt, pf_fters, "l") == -1)
			return (-1);
	}
	else if (fmt[cont] == 'h' && fmt[cont + 1] != 'h' && fmt[cont - 1] != 'h')
	{
		if (set_length_aux(fmt, pf_fters, "h") == -1)
			return (-1);
	}	
	else if (fmt[cont] == 'l' && fmt[cont + 1] == 'l')
	{
		if (set_length_aux(fmt, pf_fters, "ll") == -1)
			return (-1);
	}
	else if (fmt[cont] == 'h' && fmt[cont + 1] == 'h')
	{
		if (set_length_aux(fmt, pf_fters, "hh") == -1)
			return (-1);
	}
	return (1);
}

int	set_length(char *fmt, t_pf_formaters *pf_fters)
{
	int	cont;

	cont = pf_fters->c_chars;
	while (fmt[cont])
	{
		if (set_length_aux2(fmt, pf_fters, cont) == -1)
			return (-1);
		cont++;
	}
	return (ft_strlen(pf_fters->length));
}

int	set_specifier(char *formatter, t_pf_formaters *pf_fters)
{
	int	len;

	len = ft_strlen(formatter);
	if (len < 1)
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
	printf_formaters->c_chars = 0;
	return (printf_formaters);
}

int	set_precision_aux(char *fm, t_pf_formaters *pf_fters, int cont, int cont2)
{
	if (fm[cont] == '*')
	{
		pf_fters->precision = ft_strdup("*");
		pf_fters->c_chars += 2;
		return (2);
	}
	while ((fm[cont2] >= 48 && fm[cont2] <= 57) && fm[cont2] != '\0')
		cont2++;
	if (cont2 > cont)
	{
		pf_fters->precision = ft_substr(fm, cont, cont2 - cont);
		pf_fters->c_chars += (cont2 - cont + 1);
		return (cont2 - cont);
	}
	else
		return (0);
}

int	set_precision(char *fm, t_pf_formaters *pf_fters)
{
	int	cont;
	int	cont2;

	cont = 0;
	while (fm[cont] && fm[cont] != '.'
		&& (fm[cont + 1] != '*' || !ft_isdigit(fm[cont + 1])))
		cont++;
	if (cont < pf_fters->c_chars)
		return (-1);
	if (fm[cont + 1])
		cont++;
	else
		return (0);
	cont2 = cont;
	return (set_precision_aux(fm, pf_fters, cont, cont2));
}
