/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:46:14 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/15 20:05:45 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

// NOTE: types possible: cspdiuxX%
//
// WARNING: PROMOTIONS!!!
//			di	- signed int	=> long
//			p	- void *		=> unsigned long
//			xXu	- unsigned int	=> unsigned long
static void	promote_int(t_data *data, char type, t_union_long *number)
{
	if (ft_strchr("di", type))
	{
		number->signed_l = (long)va_arg(data->ap, int);
		data->flags.is_signed = true;
		if (0 > number->signed_l)
			data->flags.is_negative = true;
	}
	else if ('p' == type)
	{
		number->unsigned_l = (unsigned long)va_arg(data->ap, void *);
		data->flags.is_signed = false;
		data->flags.is_negative = false;
	}
	else if (ft_strchr("xXu", type))
	{
		number->unsigned_l = (unsigned long)va_arg(data->ap, unsigned int);
		data->flags.is_signed = false;
		data->flags.is_negative = false;
	}
}

void	render_format(t_data *data)
{
	char			type;
	t_union_long	number;

	type = data->flags.type;
	if ('%' == type)
		render_char(data, '%');
	if ('c' == type)
		render_char(data, va_arg(data->ap, int));
	if ('s' == type)
		render_str(data, va_arg(data->ap, char *));
	if (ft_strchr("pdiuxX", type))
	{
		promote_int(data, type, &number);
		render_number(data, number);
	}
}
