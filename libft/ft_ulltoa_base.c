/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:11:52 by gcollett          #+#    #+#             */
/*   Updated: 2017/04/16 00:28:40 by gcollett         ###   ########.fr       */
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

char	*ft_convert_unsigned_long_long_signed_base(\
	long long n, int base, int upcase)
{
	unsigned long long	tmpn;
	int					len;
	int					negative;
	char				*str;

	len = 2;
	negative = ((n < 0) ? 1 : 0);
	tmpn = ((negative == 1) ? -n : n);
	while (tmpn /= base)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	tmpn = ((n < 0) ? -n : n);
	while (len--)
	{
		str[len] = ft_convert_caractere(tmpn % base, upcase);
		tmpn /= base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_convert_unsigned_long_long_unsigned_base(\
	unsigned long long n, int base, int upcase)
{
	unsigned long long	tmpn;
	char				*str;
	int					len;

	len = 2;
	tmpn = n;
	while (tmpn /= base)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ft_convert_caractere(n % base, upcase);
		n = n / base;
	}
	return (str);
}

char	*ft_ulltoa_base(long long n, int base, int negatif, int uppercase)
{
	char	*str;

	if (base > 0)
	{
		if (negatif == 0)
			return (ft_convert_unsigned_long_long_unsigned_base(n,\
			base, uppercase));
		else
			return (ft_convert_unsigned_long_long_signed_base(n,\
			base, uppercase));
	}
	str = NULL;
	return (str);
}

char	*ull_base(long long n, int base, int negatif, int uppercase)
{
	return (ft_ulltoa_base(n, base, negatif, uppercase));
}
