/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:35:10 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/09 22:29:26 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char			*s1;
	unsigned int	i;

	i = -1;
	s1 = dst;
	while (++i < n)
		*(s1 + i) = *(char *)(src + i);
	return (dst);
}
