/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:37:23 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/08 22:27:16 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, \
		size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = -1;
	if (n == 0)
		return (NULL);
	s1 = (char *)dst;
	s2 = (char *)src;
	while (++i < n)
		if (s2[i] != (char)c)
			s1[i] = s2[i];
		else
		{
			s1[i] = s2[i];
			return (&s1[i + 1]);
		}
	return (NULL);
}
