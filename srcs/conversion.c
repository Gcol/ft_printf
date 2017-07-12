/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 00:10:41 by gcollett          #+#    #+#             */
/*   Updated: 2017/07/10 02:46:13 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unic(char *elem, int i, int j, char *str)
{
	if (ft_strlen(elem) <= 7)
		str = ft_strdup("0xxxxxxx");
	else if (ft_strlen(elem) <= 8 && MB_CUR_MAX == 1)
		str = ft_strdup("xxxxxxxx");
	else if (ft_strlen(elem) <= 11 && MB_CUR_MAX != 1)
		str = ft_strdup("110xxxxx10xxxxxx");
	else if (ft_strlen(elem) <= 16 && MB_CUR_MAX != 1)
		str = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else if (ft_strlen(elem) <= 21 && MB_CUR_MAX != 1)
		str = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	else
	{
		free(elem);
		return (NULL);
	}
	i = ft_strlen(elem) - 1;
	j = ft_strlen(str);
	while (j-- >= 0)
	{
		if (i >= 0)
			str[j] = ((str[j] == 'x') ? elem[i--] : str[j]);
		str[j] = ((str[j] == 'x') ? '0' : str[j]);
	}
	return (str);
}

char	*unic(char *resultat, unsigned int *inf, char *res, t_printf *dt)
{
	char	*str;
	char	*str2;
	char	*tmp;
	char	c;
	int		i;

	i = -1;
	if (resultat || (resultat = ft_ulltoa_base(inf[dt->index], 2, 0, 0)))
		if (!(str = ft_unic(resultat, 0, 0, "")))
			free(res);
	if (!str)
		return (NULL);
	str2 = ft_memalloc(ft_strlen(str) / 8);
	tmp = ft_memalloc(9);
	while (++i < ft_strlen(str) / 8)
	{
		c = ft_atoi_base(ft_strncpy(tmp, str + (i * 8), 8), 2);
		str2[i] = c;
	}
	if (dt->option[6] == 0 || ft_strlen(res) + ft_strlen(str2) <= dt->option[6])
		res = ft_stradd(res, str2, 2, 1);
	ft_free_char(str2, str, tmp, resultat);
	if (inf && inf[dt->index++] && res[0])
		return (unic(0, inf, res, dt));
	return (res);
}

/*
** cas 8 = char
** cas 9 = unicode
*/

char	*conversion(int cas, t_printf *d, char *res, va_list ol, ...)
{
	va_list	lst;
	int		base;

	va_start(lst, ol);
	base = ((cas >= 7) ? LST(ol, int) : 0);
	if (cas == 0 || base == 3)
		res = unic(ull_base(LST(lst, UI), 2, 0, 0), (UI *)0, ft_memalloc(1), d);
	else if (cas == 8)
		res = ull_base(((UC)LST(lst, int)), base, LST(ol, int), LST(ol, int));
	else if (cas == 7)
		res = ull_base(((SC)LST(lst, int)), base, LST(ol, int), LST(ol, int));
	else if (cas == 16)
		res = ull_base(((US)LST(lst, int)), base, LST(ol, int), LST(ol, int));
	else if (cas == 15)
		res = ull_base(((S)LST(lst, int)), base, LST(ol, int), LST(ol, int));
	else if (cas == 31)
		res = ull_base(LST(lst, int), base, LST(ol, int), LST(ol, int));
	else if (cas == 32)
		res = ull_base(LST(lst, UI), base, LST(ol, int), LST(ol, int));
	else if (cas == 63)
		res = ull_base(LST(lst, long), base, LST(ol, int), LST(ol, int));
	else if (cas == 64)
		res = ull_base(((UL)LST(lst, UL)), base, LST(ol, int), LST(ol, int));
	va_end(ol);
	return (apply_flag(res, d, d->option));
}

char	*get_lst(va_list lst, int opt, int cas, t_printf *data, ...)
{
	unsigned int	*i;
	char			*str;
	va_list			lst1;

	data->index = 0;
	va_start(lst1, data);
	if (cas == 1 && (i = LST(lst, unsigned int *)))
		return (apply_flag(
		unic(0, i, ft_memalloc(1), data), data, data->option));
	else if (cas == 1 && !i)
		return (conversion(1, data, ft_strdup("(null)"), lst));
	if (cas > 2 && (opt == 32 || opt == 31))
		return (conversion(opt, data, "", lst1, LST(lst, int)));
	else if (opt == 64)
		return (conversion(opt, data, "", lst1, va_arg(lst, ULL)));
	else if (opt == 63)
		return (conversion(opt, data, "", lst1, va_arg(lst, LL)));
	else if (cas == 2 || (cas >= 6 && cas < 12))
		return (conversion(opt, data, "", lst1, va_arg(lst, UL)));
	else if ((cas > 2 && cas < 6) || cas == 12)
		return (conversion(opt, data, "", lst1, va_arg(lst, long)));
	return ("");
}

/*
** cas = "sSpdDioOuUxXcC%""
*/

char	*set_conversion(va_list l, int opt, t_printf *data, int cas)
{
	char *str;

	if (cas == 0 && (str = va_arg(l, char *)))
		return (conversion(1, data, ft_strdup(str), l));
	else if (cas == 0)
		return (conversion(1, data, ft_strdup("(null)"), l));
	else if (cas == 1)
		return (get_lst(l, opt, cas, data, 2));
	else if (cas > 2 && cas < 6)
		return (get_lst(l, opt, cas, data, 10, 1, 0));
	else if (cas == 6 || cas == 7)
		return (get_lst(l, opt, cas, data, 8, 0, 0));
	else if (cas == 8 || cas == 9)
		return (get_lst(l, opt, cas, data, 10, 0, 0));
	else if (cas == 10 || cas == 2 || cas == 11)
		return (get_lst(l, opt, cas, data, 16, 0, (cas == 11) ? 1 : 0));
	else if (cas == 12)
		return (apply_flag(
			ft_memset(ft_memalloc(2), va_arg(l, int), 1), data, data->option));
	else if (cas == 13)
		return (get_lst(l, opt, cas, data, 3));
	return ("ERROR");
}
