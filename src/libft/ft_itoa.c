/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:53:45 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:04:43 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	number_len(unsigned int nbl)
{
	int	len;

	len = 0;
	while (nbl > 9)
	{
		len++;
		nbl = nbl / 10;
	}
	len++;
	return (len);
}

static char	*aux_ft_itoa(char *number, int len, unsigned int nbl)
{
	number[len] = '\0';
	len--;
	if (nbl == 0)
	{
		number[len] = nbl + 48;
		return (number);
	}
	while (nbl > 0)
	{
		number[len] = ((nbl % 10) + 48);
		nbl = nbl / 10;
		len--;
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char			*number;
	int				len;
	unsigned int	nbl;
	int				neg;

	len = 0;
	neg = 0;
	if (n < 0)
	{
		nbl = n * -1;
		neg = 1;
		len++;
	}
	else
		nbl = n;
	len += number_len(nbl);
	number = (char *)malloc((len + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	if (neg == 1)
		number[0] = '-';
	aux_ft_itoa(number, len, nbl);
	return (number);
}
