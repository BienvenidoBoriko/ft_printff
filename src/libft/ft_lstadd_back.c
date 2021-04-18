/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:36:26 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/13 20:17:59 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*helper;

	if (*lst == NULL)
		(*lst) = new;
	else
	{
		helper = ft_lstlast((*lst));
		if (helper != NULL)
			helper->next = new;
	}
}
