/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_factory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 02:47:41 by gcollett          #+#    #+#             */
/*   Updated: 2017/07/10 02:50:47 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_free_factory(int nb, ...)
{
	int		i;
	va_list	lst;

	i = 0;
	va_start(lst, nb);
	while (i < nb)
	{
		free(va_arg(lst, void *));
	}
}

void	ft_free_char(char *s1, char *s2, char *s3, char *s4)
{
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}
