/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:30:16 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/13 20:18:30 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*helper;

	if (lst == NULL || lst->next == NULL)
		return (lst);
	helper = lst;
	while (helper->next != NULL)
	{
		helper = helper->next;
	}
	return (helper);
}
