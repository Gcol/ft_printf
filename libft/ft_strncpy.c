/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:58:02 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/08 23:01:07 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	max;

	i = -1;
	max = 0;
	while (src[max])
		max++;
	while (++i < len)
	{
		if (i < max)
			dst[i] = src[i];
		else
			dst[i] = '\0';
	}
	return (dst);
}
