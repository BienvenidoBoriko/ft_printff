/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:54:38 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/13 20:18:24 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*helper;

	if (lst != NULL)
	{
		while (lst != NULL)
		{
			helper = lst->next;
			f(lst->content);
			lst = helper;
		}
	}
}
