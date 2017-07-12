/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 14:05:05 by gcollett          #+#    #+#             */
/*   Updated: 2017/04/15 15:45:05 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_convert_caractere(int n, int uppercase)
{
	char	*str;

	if (uppercase == 0)
		str = "0123456789abcdefghijklmnopqrstuvwxyz";
	else
		str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return (str[n]);
}

char	*ft_convert_signed_base(int n, int base, int uppercase)
{
	long	tmpn;
	int		len;
	int		negative;
	char	*str;

	tmpn = n;
	len = 2;
	negative = ((n < 0) ? 1 : 0);
	n = ((n < 0) ? -n : n);
	while (tmpn /= base)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	tmpn = ((n < 0) ? -n : n);
	while (len--)
	{
		str[len] = ft_convert_caractere(tmpn % base, uppercase);
		tmpn /= base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_convert_unsigned_base(unsigned int n, int base, int uppercase)
{
	unsigned int	tmpn;
	char			*str;
	int				len;

	len = 2;
	tmpn = n;
	while (tmpn /= base)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ft_convert_caractere(n % base, uppercase);
		n = n / base;
	}
	return (str);
}

char	*ft_itoa_base(int n, int base, int negatif, int uppercase)
{
	char	*str;

	if (base > 0)
	{
		if (negatif == 0)
			return (ft_convert_unsigned_base(n, base, uppercase));
		else
			return (ft_convert_signed_base(n, base, uppercase));
	}
	str = NULL;
	return (str);
}
