/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlendup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 01:24:48 by gcollett          #+#    #+#             */
/*   Updated: 2017/04/17 01:24:54 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strlendup(char *s1, size_t len, int clean)
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
	if (clean == 1)
		free(s1);
	return (scpy);
}
