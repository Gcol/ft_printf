/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:32:12 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/08 22:51:25 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*scpy;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	scpy = (char *)malloc(sizeof(*scpy) * (i + 1));
	if (!scpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
