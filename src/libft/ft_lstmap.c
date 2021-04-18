/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:32:17 by bboriko-          #+#    #+#             */
/*   Updated: 2021/04/18 13:05:54 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lista;
	t_list	*helper;

	if (lst != NULL && f != NULL)
	{
		n_lista = ft_lstnew(f(lst->content));
		helper = n_lista;
		while (lst->next)
		{
			lst = lst->next;
			helper->next = ft_lstnew(f(lst->content));
			if (helper->next == NULL)
			{
				ft_lstclear(&n_lista, del);
				return (NULL);
			}
			helper = helper->next;
		}
		return (n_lista);
	}
	return (NULL);
}
