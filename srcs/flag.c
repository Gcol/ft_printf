/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:21:36 by gcollett          #+#    #+#             */
/*   Updated: 2017/07/10 03:54:32 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_flag(char *res, int option[7], int length, t_printf *data)
{
	char param;

	param = data->str[data->end];
	if ((param == 'c' || param == 'C') && length == 0)
	{
		res = ft_memalloc(2);
		data->len_res += 1;
	}
	if (length > option[6] && option[6] != 0 && (param == 'S' || param == 's'))
	{
		if (option[6] < 0)
			option[6] = 0;
		while (option[6] < ft_strlen(res))
			res = ft_strlendup(res, ft_strlen(res) - 1, 1);
	}
	return (res);
}

char	*int_flag(char *res, int opt[7], char param, int len)
{
	opt[4] = (opt[6] < opt[5] && opt[6]) ? 0 : opt[4];
	if (opt[0] && (opt[7] = 2))
	{
		if ((param == 'x' && res[0] != '0'))
			res = ft_stradd("0x", res, 0, 2);
		else if (param == 'X' && res[0] != '0')
			res = ft_stradd("0X", res, 0, 2);
		else if (ft_is_in(param, "Oo") &&
				(res[0] != '0' || opt[6] < 0) && opt[7]--)
			res = ft_stradd("0", res, 0, 2);
		else
			opt[7] = 0;
	}
	opt[7] = (res[0] == '-' && (len--)) ? opt[7] + 1 : opt[7];
	while (opt[6] && res && opt[6]-- > len + (opt[7] && ft_is_in(param, "Oo")))
		res = ft_stradd_in("0", res, opt[7], 2);
	if (param == 'D' || param == 'd' || param == 'i')
		if (opt[1] && !opt[7] && (opt[7] = 1))
			res = ft_stradd("+", res, 0, 2);
	if (param == 'D' || param == 'd' || param == 'i')
		if (opt[2] && !opt[1] && !opt[7] && (opt[7] = 1))
			res = ft_stradd(" ", res, 0, 2);
	if (opt[6] < 0 && res[0] == '0' && len == 1)
		res = ft_strlendup(res, ft_strlen(res) - 1, 1);
	return (res);
}

char	*apply_flag(char *res, t_printf *data, int *option)
{
	int length;

	if (res)
	{
		if (ft_is_in(data->str[data->end], "SscC"))
			res = char_flag(res, option, ft_strlen(res), data);
		else if (ft_is_in(data->str[data->end], TYPE))
			res = int_flag(res, option, data->str[data->end], ft_strlen(res));
		if (data->str[data->end] == 'p' && (option[7] += 2))
			res = ft_stradd("0x", res, 0, 2);
		length = ft_strlen(res) + (data->str[data->end] == 'c' && res[0] == 0);
		while (option[5] > 0 && option[5]-- > length)
		{
			if (option[3] == 1)
				res = ft_stradd(" ", res, 1, 2);
			else if (option[4])
				res = ft_stradd_in("0", res, option[7], 2);
			else
				res = ft_stradd(" ", res, 0, 2);
		}
		data->len_res += ft_strlen(res);
	}
	else
		data->len_total = -1;
	return (res);
}

/*
** option = gere la presence de flags
** option[0] = #;
** option[1] = +;
** option[2] = space;
** option[3] = -;
** option[4] = 0;
** option[5] = padding;
** option[6] = precision;
** option[7] = where add my 0;
*/

void	main_flag(t_printf *data, int i, int state, int *option)
{
	char *str;

	str = data->str;
	while (i++ < data->end - 1)
	{
		state = (state == 2 && str[i] == '.') ? 3 : state;
		state = (str[i] == '.' && state < 2) ? 2 : state;
		if (str[i] == '#')
			option[0] = 1;
		else if (str[i] == '+')
			option[1] = 1;
		else if (str[i] == ' ')
			option[2] = 1;
		else if (str[i] == '-')
			option[3] = 1;
		else if (state == 0 && str[i] == '0')
			option[4] = 1;
		else if (state == 0 && str[i] > '0' && str[i] <= '9' && (state = 1))
			option[5] = ft_atoi(str + i);
		else if (state == 2 && str[i] > '0' && str[i] <= '9' && (state = 3))
			option[6] = ft_atoi(str + i) != 0 ? ft_atoi(str + i) : -1;
	}
	option[6] = (((state == 2 || state == 3) && option[6] == 0) ?
			-1 : option[6]);
}
