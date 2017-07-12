/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 22:52:33 by gcollett          #+#    #+#             */
/*   Updated: 2017/04/18 02:26:45 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *s1, char *s2, int prefix, int clean)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (prefix == 1)
	{
		clean = (clean == 1) ? 2 : 1;
		return (ft_stradd(s2, s1, 2, clean));
	}
	new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		*(new_str + i) = *(s1 + i);
	while (++j < ft_strlen(s2) && *(s2 + j) != '\0')
		*(new_str + i++) = *(s2 + j);
	if (clean == 1 || clean == 3)
		free(s1);
	else if (clean == 2 || clean == 3)
		free(s2);
	return (new_str);
}

char	*ft_stradd_len(char *s1, char *s2, size_t len_s2, int clean)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		*(new_str + i) = *(s1 + i);
	while (++j < len_s2)
		*(new_str + i++) = *(s2 + j);
	if (clean == 1 || clean == 3)
		free(s1);
	else if (clean == 2 || clean == 3)
		free(s2);
	return (new_str);
}
