/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:32:18 by gcollett          #+#    #+#             */
/*   Updated: 2016/12/06 23:36:31 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	t;
	char	*str;

	t = -1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (++t < size)
		str[t] = '\0';
	return (str);
}
