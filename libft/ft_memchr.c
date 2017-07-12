/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:49:12 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/08 23:17:09 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s1;
	size_t	i;

	if (n == 0)
		return (NULL);
	i = -1;
	s1 = (char *)s;
	while (++i < n)
		if (s1[i] == (char)c)
			return (s1 + i);
	return (NULL);
}
