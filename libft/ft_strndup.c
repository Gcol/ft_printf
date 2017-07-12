/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:32:12 by gcollett          #+#    #+#             */
/*   Updated: 2016/12/07 01:18:34 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strndup(const char *s1, size_t len)
{
	char	*scpy;
	size_t	i;

	scpy = (char *)malloc(sizeof(*scpy) * (len + 1));
	if (!scpy)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[(s1[i]) ? len : i] = '\0';
	return (scpy);
}
