/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 22:08:05 by gcollett          #+#    #+#             */
/*   Updated: 2017/04/17 22:09:24 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_parse_str(char *src, int start, int len, int clean)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (len + 1));
	new_str[len] = '\0';
	while (--len >= 0)
		new_str[len] = src[start + len];
	if (clean == 1)
		free(src);
	return (new_str);
}
