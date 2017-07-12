/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:47:07 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/10 13:49:18 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_front(t_list **begin_list, void *content, \
		size_t content_size)
{
	t_list *nlist;

	if (*begin_list)
	{
		nlist = ft_lstnew(content, content_size);
		nlist->next = *begin_list;
		*begin_list = nlist;
	}
	else
		*begin_list = ft_lstnew(content, content_size);
}
