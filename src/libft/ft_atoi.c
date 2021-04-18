/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:00:21 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:02:40 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	char	*string;
	int		neg;
	long	num;

	num = 0;
	neg = 1;
	string = str;
	while (*string == ' ' || (*string >= 9 && *string <= 13))
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			neg *= -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		num *= 10;
		num += *string - '0';
		string++;
	}
	return (num * neg);
}
