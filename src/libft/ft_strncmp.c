/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:59:54 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:23:37 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while ((*s11 != '\0' || *s22 != '\0') && n > 0)
	{
		if (*s11 > *s22)
		{
			return (1);
		}
		else if (*s11 < *s22)
		{
			return (-1);
		}
		s11++;
		s22++;
		n--;
	}
	return (0);
}
