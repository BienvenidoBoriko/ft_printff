/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treet_printf_formaters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:02:14 by bboriko-          #+#    #+#             */
/*   Updated: 2021/05/01 21:46:26 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_printf.h"
/*int	set_specifier(char *fm, t_pf_formaters *pf_fters, int count)
{
	int	r_count;

	r_count = count;
	while (!ft_strrchr(pf_fters->specifiers, fm[count]) && fm[count] != ' ')
		count++;
	if (r_count == count)
		return (-1);
	pf_fters->specifier = fm[count]; 
	return (count);
}*/

/*int	set_t_pf_formaters(t_pf_formaters	*pf_formaters, char *fmt)
{
	int	len;

	len = ft_strlen(fmt);
	pf_formaters->specifier = fmt[len - 1];
	set_flags(fmt, pf_formaters);
	return (1);
}*/

int	get_aux_set_flags_len(t_pf_formaters *pf_fters)
{
	int	len;

	len = 0;
	if (pf_fters->left_justify == 1)
		len++;
	if (pf_fters->sign == 1)
		len++;
	if (pf_fters->no_name == 1)
		len++;
	if (pf_fters->space == 1)
		len++;
	if (pf_fters->left_pads == 1)
		len++;
	return (len);
}

int	aux_set_flags(char *formatter, t_pf_formaters *pf_fters)
{
	int	cont;
	int	len;

	cont = 0;
	len = 0;
	while (formatter[cont])
	{
		if (formatter[cont] == '-')
			pf_fters->left_justify = 1;
		else if (formatter[cont] == '+')
			pf_fters->sign = 1;
		else if (formatter[cont] == '#')
			pf_fters->no_name = 1;
		else if (formatter[cont] == ' ')
			pf_fters->space = 1;
		else if (formatter[cont] == '0' && !ft_isdigit(formatter[cont - 1]))
			pf_fters->left_pads = 1;
		cont++;
	}
	len = get_aux_set_flags_len(pf_fters);
	return (len);
}

int	set_flags(char *formatter, t_pf_formaters *pf_fters)
{
	int	cont;

	cont = aux_set_flags(formatter, pf_fters);
	cont += set_width_flag(formatter, pf_fters);
	ft_putstr_fd("\n", 1);
	//ft_putstr_fd(formatter, 1);
	ft_putnbr_fd(cont, 1);
	ft_putstr_fd("\n", 1);
	if (ft_strrchr(formatter, '.'))
	{
		free(pf_fters->precision);
		cont += set_precision_flag(formatter, pf_fters);
	}
	return (cont);
}

int	set_precision_flag(char *fm, t_pf_formaters *pf_fters)
{
	int	cont;
	int	cont2;

	cont = 0;
	while (fm[cont] != '.' && fm[cont])
		cont++;
	if (fm[cont + 1])
		cont++;
	else
		return (-1);
	cont2 = cont;
	if (fm[cont] == '*')
	{
		pf_fters->precision = ft_substr(fm, cont, 1);
		return (2);
	}
	while ((fm[cont2] >= 48 && fm[cont2] <= 57) && fm[cont2])
		cont2++;
	if (cont2 > 0)
	{
		pf_fters->precision = ft_substr(fm, cont, cont2 - cont + 1);
		return (cont2 - cont + 1);
	}
	else
		return (0);
}

int	set_width_flag_aux(char *format, t_pf_formaters *pf_fters)
{
	char	*result;

	result = ft_strrchr(format, "*");
	if (!result || *(result--) == '.')
		return (-1);
	free(pf_fters->width);
	pf_fters->width = ft_strdup("*");
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("si", 1);
	//ft_putnbr_fd(setet, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}

int	set_width_flag(char *fm, t_pf_formaters *pf_fters)
{
	int	cont;
	int	cont2;
	int	parar;

	cont = 0;
	parar = 0;
	if ((set_width_flag_aux(fm, pf_fters)) == -1)
	{
		while (fm[cont] && !ft_isdigit(fm[cont]) && fm[cont - 1] != '.'
			&& !ft_isdigit(fm[cont - 1]))
			cont++;
		cont2 = cont;
		while ((fm[cont2] >= 48 && fm[cont2] <= 57) && fm[cont2])
			cont2++;
	}
	else
	{
		ft_putstr_fd("\n", 1);
	ft_putstr_fd("si2", 1);
	//ft_putnbr_fd(setet, 1);
	ft_putstr_fd("\n", 1);
	return (1);
	}
	if (cont2 > 0)
	{
		free(pf_fters->width);
		pf_fters->width = ft_substr(fm, cont, cont2 - cont + 1);
		return (cont2 - cont);
	}
	else
		return (0);
}
