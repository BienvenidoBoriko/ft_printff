/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:57:52 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/24 21:28:24 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

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

int	set_t_pf_formaters(t_pf_formaters	*printf_formaters, char *formatter)
{
	int len;

	len = ft_strlen(formatter);
	printf_formaters->specifier = formatter[len - 1];
	set_flags(formatter, printf_formaters);
	
	return (1);
}

char	*get_formats(char *fm, t_pf_formaters *pf_fters, int count)
{
	char	*formatter;
	int		r_count;
	int		len;

	count++;
	r_count = count;
	while (fm[count] && fm[count] != ' ' && !(ft_strrchr(pf_fters->specifiers, fm[count])))
		count++;
	if ((r_count == count) && !(ft_strrchr(pf_fters->specifiers, fm[count])))
		formatter = ft_strdup("");
	else
	{
		if((count - r_count) == 0)
			len = 1;
		else
			len = count - r_count + 1;
		formatter = ft_substr(fm, r_count, len);
	}
	return (formatter);
}

int	set_flags(char *formatter, t_pf_formaters *pf_fters)
{
	int	cont;

	cont = 0;
	while(formatter[cont])
	{
		if (formatter[cont] == '-')
			pf_fters->left_justify = 1;
		else if (formatter[cont] == '+')
			pf_fters->sign = 1;
		else if (formatter[cont] == '#')
			pf_fters->no_name = 1;
		else if (formatter[cont] == ' ')
			pf_fters->space = 1;
		else if (formatter[cont] == '0')
			pf_fters->left_pads = 1;
		cont++;
	}
	if(ft_strrchr(formatter, '*'))
	{
		free(pf_fters->width);
		pf_fters->width = ft_strdup("*");
	}
	else
		set_width_flag(formatter, pf_fters);
	if(ft_strrchr(formatter, '.'))
	{
		free(pf_fters->precision);
		set_precision_flag(formatter, pf_fters);
	}
}

int set_precision_flag(char *formatter, t_pf_formaters *pf_fters)
{
	int	cont;
	int	cont2;

	cont = 0;
	while (formatter[cont] != '.' && formatter[cont])
		cont++;
	if (formatter[cont + 1])
		cont++;
	else
		return (-1);
	cont2 = cont;
	if (formatter[cont] == '*')
	{
		pf_fters->precision = ft_substr(formatter, cont, 1);
		return (1);
	}
	while ((formatter[cont2] >= 48 && formatter[cont2] <= 57) && formatter[cont2])
		cont2++;
	if (cont2 > 0)
	{
		pf_fters->precision = ft_substr(formatter, cont, cont2 - cont + 1);
		return (1);
	}
	else
		return (-1);	
}

int set_width_flag(char *formatter, t_pf_formaters *pf_fters)
{
	int	cont;
	int	cont2;

	cont = 0;
	while(!(formatter[cont] >= 49 && formatter[cont] <= 57) && formatter[cont])
		cont++;
	cont2 = cont;
	while((formatter[cont2] >= 48 && formatter[cont2] <= 57) && formatter[cont2])
		cont2++;
	if(cont2 > 0)
	{
		free(pf_fters->width);
		pf_fters->width = ft_substr(formatter, cont, cont2 - cont + 1);
		return (1);
	}
	else
		return (-1);	
}
/*
int	set_length(char *fm, t_pf_formaters *pf_fters, int count)
{

}*/

//int	ft_format(char *fm, va_list args, t_pf_formaters *pf_fters, int count)
int	ft_format(char *fm, t_pf_formaters *pf_fters, int count)
{
	int	legth;
	char	*formatter;

	formatter = get_formats(fm, pf_fters, count);
	set_t_pf_formaters(pf_fters, formatter);
	legth = 0;
	/*legth += set_specifier(fm, pf_fters, count);
	legth += set_flags(fm, pf_fters, count);
	legth += set_length(fm, pf_fters, count);
	printf("%s", fm);
	args = NULL;
	pf_fters = NULL;*/
	free(formatter);
	return (legth);
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

int	ft_printf(const char *format, ...)
{
	va_list				args;
	char				*str;
	int					count;
	t_pf_formaters		printf_formaters;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	init_t_pf_formaters(&printf_formaters);
	//ft_putstr_fd(printf_formaters.specifiers, 1);
	while (format[count])
	{
		if (format[count] == '%')
		{
			str = va_arg(args, char *);
			count += ft_format((char *)format, &printf_formaters, count);
			//ft_putstr_fd(str, 1);
		}
		//else
			//ft_putchar_fd(format[count], 1);
		count++;
	}
	return (count + printf_formaters.count_chars);
}
