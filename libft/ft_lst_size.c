/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:20:31 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/10 13:31:08 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list *begin_list)
{
	t_list	*nlist;
	int		compt;

	nlist = begin_list;
	compt = 0;
	if (nlist)
	{
		while (nlist)
		{
			nlist = nlist->next;
			compt += 1;
		}
	}
	return (compt);
}
