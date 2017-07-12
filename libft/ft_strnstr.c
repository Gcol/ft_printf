/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:55:26 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/09 02:22:10 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	itn;
	char	*it1;
	char	*it2;

	if (!*little)
		return ((void *)big);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			itn = len;
			it1 = (void *)big + 1;
			it2 = (void *)little + 1;
			while (itn-- && *it1 && *it2 && *it1 == *it2)
			{
				++it1;
				++it2;
			}
			if (!*it2)
				return ((void *)big);
		}
		big++;
	}
	return (NULL);
}
