/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:10:59 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/13 20:18:12 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*helper;

	if ((*lst) != NULL)
	{
		while ((*lst))
		{
			helper = (*lst)->next;
			del((*lst)->content);
			free((*lst));
			(*lst) = helper;
		}
	}
}
