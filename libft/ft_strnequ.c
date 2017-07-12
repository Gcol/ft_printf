/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:24:53 by gcollett          #+#    #+#             */
/*   Updated: 2016/11/10 00:52:33 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!s1[i] || !s2[i])
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < (n - 1))
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
