/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 06:41:12 by gcollett          #+#    #+#             */
/*   Updated: 2017/01/16 06:42:56 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_atoi2(char nb)
{
	if (nb == '-')
		return ('n');
	if (nb == '+')
		return ('p');
	else
		return ('a');
}

int				ft_atoi(const char *nb)
{
	int		a;
	char	c;
	int		ret;

	a = 0;
	ret = 0;
	while ((nb[a] >= 8 && nb[a] <= 13) || nb[a] == 32)
		a++;
	if ('a' < (c = ft_atoi2(nb[a])))
		a++;
	while (nb[a] > 47 && nb[a] < 58 &&
			((ret * -10 - (nb[a] - '0')) > -2147483648))
		ret = ret * 10 + (nb[a++] - '0');
	if (nb[a] > 47 && nb[a] < 58 &&
			(ret * -10 - (nb[a] - '0')) == -2147483648 && c == 'n')
		return (-2147483648);
	else if ((nb[a] < 48 || nb[a] > 57) && c != 'n')
		return (ret);
	else if ((nb[a] < 48 || nb[a] > 57) && c == 'n')
		return (-ret);
	return (0);
}
