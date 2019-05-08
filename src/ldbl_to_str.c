/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldbl_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:37:50 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:37:50 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*dbl_transform_if(t_ldouble *d)
{
	char	*res;

	if (!(res = ft_nchjoinstr(d->mantissa, '0', -(d->exponent))))
		return (NULL);
	res[1] = '.';
	res[-(d->exponent) + 1] = '1';
	res[-(d->exponent)] = '0';
	free(d->mantissa);
	d->mantissa = res;
	return (res);
}

static char			*dbl_transform(t_ldouble *d)
{
	int		l;
	char	*res;

	if (d->sign == 0 && d->exponent == -32767 && !ft_strcmp(d->mantissa, "1."))
	{
		free(d->mantissa);
		d->mantissa = ft_strdup("0.0");
	}
	else if (d->exponent < 0)
		dbl_transform_if(d);
	else if (d->exponent > 0)
	{
		if (!(res = ft_strjoinnch(d->mantissa, '0',
			d->exponent - ft_strlen(d->mantissa) + 3)))
			return (NULL);
		free(d->mantissa);
		d->mantissa = res;
		l = 1;
		while ((d->exponent)-- > 0)
		{
			res[l] = res[l + 1];
			res[l++ + 1] = '.';
		}
	}
	return (d->mantissa);
}

static t_ldouble	*get_double(long double d)
{
	__uint128_t		*n;
	int				i;
	int				l;
	t_ldouble		*res;

	n = (__uint128_t *)&d;
	if (!(res = (t_ldouble *)malloc(sizeof(t_ldouble))))
		return (NULL);
	res->sign = d < 0;
	res->exponent = (((*n) << 49 >> 49) >> 64) - 16383;
	i = 0;
	while (((*n) >> i & 1) != 1 && i < 63)
		++i;
	l = 63 - i;
	if (!(res->mantissa = ft_strnew(l + 2)))
	{
		free(res);
		return (NULL);
	}
	while (l + 1 > 0)
		res->mantissa[l-- + 1] = '0' + ((((*n) >> i++) & 1) == 1);
	res->mantissa[0] = '1';
	res->mantissa[1] = '.';
	return (res);
}

char				*ldbl_to_str(long double d)
{
	char		*res;
	char		*frac;
	char		*inte;
	t_ldouble	*dbl;

	dbl = get_double(d);
	dbl_transform(dbl);
	inte = ft_copyuntil(dbl->mantissa, '.');
	frac = ft_strchr(dbl->mantissa, '.');
	res = get_int_from_bin(inte);
	free(inte);
	inte = res;
	res = get_frac_from_bin(frac);
	frac = res;
	res = ft_strjoin(inte, frac);
	free(inte);
	free(frac);
	free(dbl->mantissa);
	free(dbl);
	return (res);
}
