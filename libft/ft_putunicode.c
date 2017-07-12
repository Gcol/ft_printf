/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:27:23 by gcollett          #+#    #+#             */
/*   Updated: 2017/04/18 02:29:33 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunicode(char *str)
{
	int	i;
	int	j;
	int	k;
	int	*tab;

	i = -1;
	k = 0;
	j = ft_strlen(str) / 8;
	tab = malloc(sizeof(int) * 4);
	while (str[++i] == ' ')
		write(1, " ", 1);
	while (k < 4)
	{
		if (k < j)
			tab[k] = ft_atoi_base(ft_parse_str(str, (k * 8) + i, 8, 0), 2);
		else
			tab[k] = 0;
		k++;
	}
	write(1, &tab[0], 1);
	write(1, &tab[1], 1);
	write(1, &tab[2], 1);
	write(1, &tab[3], 1);
	free(str);
}
