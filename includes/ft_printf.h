/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 13:07:07 by gcollett          #+#    #+#             */
/*   Updated: 2017/07/10 03:36:11 by gcollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# define ULL unsigned long long
# define US unsigned short
# define UL unsigned long
# define UC unsigned char
# define UI unsigned int
# define SC signed char
# define LL long long
# define S short
# define L long
# define LST(liste, type) (va_arg(liste, type))
# define TYPE "sSpdDioOuUxXcC"
# define FLAG "0123456789-#+lhzj ."

typedef struct	s_printf
{
	char	*str;
	int		start;
	int		end;
	char	*result;
	int		len_res;
	int		len_total;
	int		option[8];
	int		index;
}				t_printf;

char			*set_conversion(va_list l, int opt, t_printf *data, int cas);
int				ft_printf(const char *format, ...);
void			main_flag(t_printf *data, int i, int state, int *option);
char			*apply_flag(char *res, t_printf *data, int *option);

#endif
