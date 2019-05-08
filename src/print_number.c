/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thansen <thansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:38 by thansen           #+#    #+#             */
/*   Updated: 2019/05/08 17:46:38 by thansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_positive(char *str, t_token *tok)
{
	char	sign;
	char	*str_new;
	int		res;

	sign = '\0';
	res = 0;
	if ((tok->flags & F_SPACE) == F_SPACE)
		sign = ' ';
	if ((tok->flags & F_PLUS) == F_PLUS)
		sign = '+';
	if (((tok->flags & F_ZERO) == F_ZERO) &&
		((tok->flags & F_MINUS) != F_MINUS))
	{
		sign != '\0' ? res += ft_putchar(sign) : (0);
		res += print_no_flag(str, tok->width - (sign != '\0'), -1, '0');
	}
	else
	{
		str_new = ft_chjoinstr(sign, str);
		res += ((tok->flags & F_MINUS) == F_MINUS) ?
			print_with_flag(str_new, tok->width, -1, ' ') :
			print_no_flag(str_new, tok->width, -1, ' ');
		free(str_new);
	}
	return (res);
}

static int	print_positive_with_prec(char *str, t_token *tok)
{
	int		l;
	int		res;
	char	*temp;

	l = ft_strlen(str);
	if (str[l - 1] == '0' && tok->precision == 0)
		return (print_positive("", tok));
	tok->flags = tok->flags & (~F_ZERO);
	if (tok->precision <= l)
		return (print_positive(str, tok));
	temp = ft_nchjoinstr(str, '0', tok->precision - l);
	res = print_positive(temp, tok);
	free(temp);
	return (res);
}

static int	print_negative(char *str, t_token *tok)
{
	int		res;

	res = 0;
	if (((tok->flags & F_ZERO) == F_ZERO) &&
		((tok->flags & F_MINUS) != F_MINUS))
	{
		res += ft_putchar('-');
		res += print_no_flag(str + 1, tok->width - 1, -1, '0');
	}
	else
	{
		res += ((tok->flags & F_MINUS) == F_MINUS) ?
			print_with_flag(str, tok->width, -1, ' ') :
			print_no_flag(str, tok->width, -1, ' ');
	}
	return (res);
}

static int	print_negative_with_prec(char *str, t_token *tok)
{
	int		l;
	int		res;
	char	*temp;
	char	*temp1;

	tok->flags = tok->flags & (~F_ZERO);
	l = ft_strlen(str) - 1;
	if (tok->precision <= l)
		return (print_negative(str, tok));
	temp = ft_nchjoinstr(str + 1, '0', tok->precision - l);
	temp1 = ft_chjoinstr('-', temp);
	res = print_negative(temp1, tok);
	free(temp);
	free(temp1);
	return (res);
}

int			print_number(char *str, t_token *tok, int sign)
{
	if (sign && tok->precision == -1)
		return (print_positive(str, tok));
	if (sign && tok->precision != -1)
		return (print_positive_with_prec(str, tok));
	if (!sign && tok->precision != -1)
		return (print_negative_with_prec(str, tok));
	return (print_negative(str, tok));
}
