/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:10:47 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/10 00:53:14 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		str = (char *)malloc(sizeof(char) * i + 1);
		if (!str)
			return (NULL);
		i = -1;
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
