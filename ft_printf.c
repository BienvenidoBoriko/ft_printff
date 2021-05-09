/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:57:52 by bboriko-          #+#    #+#             */
/*   Updated: 2021/05/09 20:29:01 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

static int	ft_process(t_pf_formaters *pf_fters, va_list *args)
{
	ft_putstr_fd("\n width = ", 1);
	ft_putstr_fd(pf_fters->width, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n precision = ", 1);
	ft_putstr_fd(pf_fters->precision, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n specifier = ", 1);
	ft_putchar_fd(pf_fters->specifier, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n left_justify = ", 1);
	ft_putnbr_fd(pf_fters->left_justify, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n sign = ", 1);
	ft_putnbr_fd(pf_fters->sign, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n left_pads = ", 1);
	ft_putnbr_fd(pf_fters->left_pads, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n no_name = ", 1);
	ft_putnbr_fd(pf_fters->no_name, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n space = ", 1);
	ft_putnbr_fd(pf_fters->space, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n length = ", 1);
	ft_putstr_fd(pf_fters->length, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n specifiers = ", 1);
	ft_putstr_fd(pf_fters->specifiers, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n lengths = ", 1);
	ft_putstr_fd(pf_fters->lengths, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n c_chars = ", 1);
	ft_putnbr_fd(pf_fters->c_chars, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\nh------------------------------------------------\n", 1);
	/*ft_putstr_fd("\n", 1);
	ft_putstr_fd(pf_fters->width, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(pf_fters->width, 1);
	ft_putstr_fd("\n", 1);*/
	return (1);
}

char	*get_formats(char *fm, t_pf_formaters *pf_fters, int count)
{
	char	*formatter;
	int		r_count;
	int		len;

	count++;
	r_count = count;
	while (fm[count] && (ft_strrchr(pf_fters->specifiers, fm[count])) == 0)
		count++;
	if ((r_count == count) && !(ft_strrchr(pf_fters->specifiers, fm[count])))
		formatter = ft_strdup("");
	else if (fm[count] == '\0')
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

int	ft_format(char *fm, t_pf_formaters *pf_fters, int count)
{
	int		len;
	char	*formatter;
	int		r_setlen;

	len = 0;
	formatter = get_formats(fm, pf_fters, count);
	if (set_flags(formatter, pf_fters) == -1)
		return (-1);
	if (set_width(formatter, pf_fters) == -1)
		return (-1);
	if (set_precision(formatter, pf_fters) == -1)
		return (-1);
	if (set_length(formatter, pf_fters) == -1)
		return (-1);
	if (set_specifier(formatter, pf_fters) == -1)
		return (-1);
	free(formatter);
	return (ft_strlen(formatter));
}

int	ft_printf_aux(char *format, va_list	*args)
{
	int					result;
	t_pf_formaters		printf_formaters;
	int					count;
	int					len;

	count = 0;
	len = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			init_t_pf_formaters(&printf_formaters);
			result = ft_format((char *)format, &printf_formaters, count);
			if (result != -1)
			{
				count += result;
				len += ft_process(&printf_formaters, args);
			}
		}
		//else
			//ft_putchar_fd(format[count], 1);
		count++;
	}
	return (len + count);
}

int	ft_printf(const char *format, ...)
{
	va_list				args;

	if (!format)
		return (-1);
	va_start(args, format);
	return (ft_printf_aux((char *)format, &args));
}
