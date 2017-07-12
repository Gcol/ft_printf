/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 01:36:48 by gcollett          #+#    #+#             */
/*   Updated: 2017/07/10 02:45:45 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_to_str(char *res, char *str, int option, t_printf *data)
{
	char	*new_str;
	int		j;
	int		k;

	j = -1;
	k = -1;
	if (data->len_total < 0)
	{
		if (res)
			free(res);
		return (NULL);
	}
	new_str = ft_memalloc(data->len_total + data->len_res);
	while (++j < data->len_total && data->len_total != 0)
		new_str[j] = res[j];
	while (++k < data->len_res)
		new_str[j + k] = str[k];
	if (res)
		free(res);
	data->len_total += data->len_res;
	if (option == 1)
		free(str);
	return (new_str);
}

char	*analyse_conversion(va_list lst, t_printf *data, int i, int size)
{
	int modif_size;
	int cas;

	modif_size = 0;
	cas = (ft_strchr(TYPE, data->str[data->end]) - TYPE);
	if (cas == 2 || cas == 9 || cas == 4 || cas == 7 || cas == 13)
		size = 64;
	else if (cas > 2 && cas < 12)
		size = 32 - (cas < 6);
	while (i < data->end && size != 64)
	{
		if ((data->str[i] == 'z' || data->str[i] == 'j') && modif_size == 0)
			modif_size += 32;
		else if (data->str[i] == 'l' && (modif_size == 0 || modif_size < 0))
			modif_size += 32 + modif_size * -1;
		else if (data->str[i] == 'h' && modif_size == 0)
			modif_size -= 16;
		else if (data->str[i] == 'h' && modif_size == -16)
			modif_size -= 8;
		i++;
	}
	size = size + modif_size;
	if ((cas == 0 || cas == 12) && size == 32)
		cas++;
	return (set_conversion(lst, size, data, cas));
}

char	*analys(t_printf *data, va_list lst)
{
	data->len_res = 0;
	main_flag(data, data->start, 0, data->option);
	if (ft_is_in(data->str[data->end], "sSpdDioOuUxXcC"))
		return (analyse_conversion(lst, data, data->start + 1, 0));
	else if (data->str[data->end] == '%')
		return (apply_flag(ft_strdup("%"), data, data->option));
	else
		return (apply_flag(ft_memset(
			ft_memalloc(2), data->str[data->end], 1), data, data->option));
}

char	*parsing(t_printf *data, va_list lst, char *result, int i)
{
	int		state;

	state = 2;
	while (data->str[++i] && data->len_total >= 0)
	{
		if (!ft_is_in(data->str[i], FLAG) && state == 1 && (data->end = i))
		{
			result = add_to_str(result, analys(data, lst), 1, data);
			state = 0;
			data->start = i + 1;
			state = 2;
		}
		else if (data->str[i] == '%')
		{
			if (state == 2 && (data->len_res = i - data->start))
				result = add_to_str(result, (data->str) + data->start, 0, data);
			state = 1;
			data->start = i;
		}
	}
	if (state == 2)
		if (data->start != i && (data->len_res = i - data->start))
			result = add_to_str(result, (data->str) + data->start, 0, data);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	int			taille;
	t_printf	*data;
	va_list		lst;

	va_start(lst, format);
	data = ft_memalloc(sizeof(t_printf));
	data->str = ft_strdup((char *)format);
	data->len_total = 0;
	data->start = 0;
	data->end = 0;
	data->len_res = 0;
	data->index = 0;
	data->result = parsing(data, lst, ft_memalloc(1), -1);
	if (data->len_total >= 0)
		taille = data->len_total;
	else
		taille = -1;
	if (data->len_total > 0)
		write(1, data->result, data->len_total);
	va_end(lst);
	free(data->result);
	free(data->str);
	free(data);
	return (taille);
}
