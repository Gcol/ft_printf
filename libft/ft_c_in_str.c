/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_in_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:37:22 by gcollett          #+#    #+#             */
/*   Updated: 2017/07/10 03:28:22 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in(char car, char *string)
{
	while (*string)
	{
		if (car == *string)
			return (1);
		string++;
	}
	return (0);
}

int	ft_c_in_str(char car, char *string)
{
	return (ft_is_in(car, string));
}
