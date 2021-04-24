/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:53:51 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/24 16:22:35 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*helper;

	size = 0;
	if (lst == NULL)
		return (size);
	if (lst->next == NULL)
		return (1);
	size++;
	helper = lst;
	if (helper->next != NULL)
		helper = helper->next;
	while (helper != NULL)
	{
		size++;
	}
	return (size);
}
