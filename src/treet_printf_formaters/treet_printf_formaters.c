/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treet_printf_formaters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:02:14 by bboriko-          #+#    #+#             */
/*   Updated: 2021/05/02 18:43:29 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/ft_printf.h"

int	check_flags(char *fm, int c)
{
	int	r_cont;

	r_cont = c;
	while (fm[c])
	{
		if (fm[c] == '-' || fm[c] == '+' || fm[c] == '#' || fm[c] == ' '
			|| (fm[c] == '0' && !ft_isdigit(fm[c - 1])))
			return (-1);
		c++;
	}
	return (r_cont);
}

int	set_flags(char *fm, t_pf_formaters *pf_fters)
{
	int	cont;

	cont = 0;
	while (fm[cont])
	{
		if (fm[cont] == '-')
			pf_fters->left_justify = 1;
		else if (fm[cont] == '+')
			pf_fters->sign = 1;
		else if (fm[cont] == '#')
			pf_fters->no_name = 1;
		else if (fm[cont] == ' ')
			pf_fters->space = 1;
		else if (fm[cont] == '0' && !ft_isdigit(fm[cont - 1]))
			pf_fters->left_pads = 1;
		else
		{
			cont++;
			break ;
		}
		cont++;
	}
	return (check_flags(fm, cont));
}

int	set_width_aux(char *fm, t_pf_formaters *pf_fters)
{
	char	*result;
	int		cont;

	cont = 0;
	while (fm[cont] && fm[cont] != '*')
		cont++;
	if (fm[cont] == '*' && fm[cont - 1] != '.' && cont > pf_fters->c_chars)
	{
		free(pf_fters->width);
		pf_fters->width = ft_strdup("*");
		return (1);
	}
	else if (pf_fters->c_chars > cont && fm[cont] == '*' && fm[cont - 1] != '.')
		return (-1);
	else
		return (0);
	//ft_putstr_fd("\n", 1);
	//ft_putstr_fd("si", 1);
	//ft_putnbr_fd(setet, 1);
	//ft_putstr_fd("\n", 1);
	//return (1);
}

int	set_width_aux2(char *fm, t_pf_formaters *pf_fters, int cont, int cont2)
{
	if (cont < pf_fters->c_chars)
		return (-1);
	if (cont2 > 0)
	{
		free(pf_fters->width);
		pf_fters->width = ft_substr(fm, cont, cont2 - cont);
		pf_fters->c_chars += (cont2 - cont);
		return (cont2 - cont);
	}
	else
		return (0);
}

int	set_width(char *fm, t_pf_formaters *pf_fters)
{
	int	cont;
	int	cont2;
	int	punto;

	cont = 0;
	punto = 0;
	if ((set_width_aux(fm, pf_fters)) == 1)
		return (1);
	if ((set_width_aux(fm, pf_fters)) == -1)
		return (-1);
	while (fm[cont])
	{
		if (ft_isdigit(fm[cont]) && fm[cont - 1] == '.')
			punto = 1;
		else if (ft_isdigit(fm[cont]) && fm[cont - 1] != '.' && punto == 0)
			break ;
		else if (!ft_isdigit(fm[cont]))
			punto = 0;
		cont++;
	}
	cont2 = cont;
	while ((fm[cont2] >= 48 && fm[cont2] <= 57) && fm[cont2])
		cont2++;
	return (set_width_aux2(fm, pf_fters, cont, cont2));
}
