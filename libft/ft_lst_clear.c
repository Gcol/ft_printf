/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:25:51 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/10 13:31:19 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_clear(t_list **begin_list)
{
	t_list	*clist;
	t_list	*tmp;

	if (begin_list)
	{
		clist = *begin_list;
		tmp = NULL;
		while (clist)
		{
			if (clist->next)
				tmp = clist->next;
			else
				tmp = NULL;
			free(clist);
			clist = tmp;
		}
	}
}
