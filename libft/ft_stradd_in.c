/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:53:34 by gcollett          #+#    #+#             */
/*   Updated: 2017/04/17 01:26:27 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_in(char *elem_add, char *src, size_t pos, int clean)
{
	char	*new_str;
	int		i;
	int		j;
	int		k;

	if (!elem_add || !src)
		return (NULL);
	new_str = ft_strnew(ft_strlen(src) + ft_strlen(elem_add));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	k = -1;
	while (++i < (int)ft_strlen(src) && i < (int)pos)
		*(new_str + i) = *(src + ++j);
	while (++k < (int)ft_strlen(elem_add) && *(elem_add + k) != '\0')
		*(new_str + i++) = *(elem_add + k);
	while (j++ < (int)ft_strlen(src))
		*(new_str + i++) = *(src + j);
	if (clean == 1 || clean == 3)
		free(elem_add);
	if (clean == 2 || clean == 3)
		free(src);
	return (new_str);
}
