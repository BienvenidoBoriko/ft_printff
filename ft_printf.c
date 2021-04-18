/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:57:52 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 21:10:21 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	set_specifier(char *fm, t_pf_formaters *pf_fters, int count)
{
	int	r_count;

	r_count = count;
	while (!ft_strrchr(pf_fters->specifiers, fm[count]) && fm[count] != ' ')
		count++;
	if (r_count == count)
		return (-1);
	pf_fters->specifier = fm[count]; 
	return (1);
}

int	set_flags(char *fm, t_pf_formaters *pf_fters, int count)
{

}

int	set_length(char *fm, t_pf_formaters *pf_fters, int count)
{

}

int	ft_format(char *fm, va_list args, t_pf_formaters *pf_fters, int count)
{
	int	legth;

	legth = 0;
	legth += set_specifier(fm, pf_fters, count);
	legth += set_flags(fm, pf_fters, count);
	legth += set_length(fm, pf_fters, count);
	printf("%s", fm);
	args = NULL;
	pf_fters = NULL;
	return (legth);
}

t_pf_formaters	*init_t_pf_formaters(t_pf_formaters	*printf_formaters)
{
	printf_formaters->specifiers = ft_strdup("cspdiuxX%nfge");
	printf_formaters->lengths = ft_strdup("l ll h hh");
	printf_formaters->length = ft_strdup("");
	printf_formaters->left_justify = 0;
	printf_formaters->sign = 0;
	printf_formaters->with = 0;
	printf_formaters->left_pads = 0;
	printf_formaters->precision = 0;
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
	ft_putstr_fd(printf_formaters.specifiers, 1);
	while (format[count])
	{
		if (format[count] == '%')
		{
			str = va_arg(args, char *);
			count += ft_format((char *)format, args, &printf_formaters, count);
			ft_putstr_fd(str, 1);
		}
		else
			ft_putchar_fd(format[count], 1);
		count++;
	}
	return (count + printf_formaters.count_chars);
}
