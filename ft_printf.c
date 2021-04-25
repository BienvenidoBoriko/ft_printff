/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:57:52 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/25 17:08:19 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

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
		if ((count - r_count) == 0)
			len = 1;
		else
			len = count - r_count + 1;
		formatter = ft_substr(fm, r_count, len);
	}
	return (formatter);
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
	while (format[count])
	{
		if (format[count] == '%')
		{
			init_t_pf_formaters(&printf_formaters);
			str = va_arg(args, char *);
			count += ft_format((char *)format, &printf_formaters, count);
			//ft_putstr_fd("\n", 1);
			//ft_putnbr_fd(count, 1);
			//ft_putstr_fd(str, 1);
			//ft_putstr_fd("\n", 1);
		}
		//else
			//ft_putchar_fd(format[count], 1);
		count++;
	}
	return (count + printf_formaters.count_chars);
}
