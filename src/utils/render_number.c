/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:12:24 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/24 14:37:05 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// NOTE:
// - / +  || 0x
static void	num_put_sign(t_data *data)
{
	if ((ft_strchr("xX", data->flags.type) && data->flags.hash
			&& data->utils.tmp[0] != '0') || data->flags.type == 'p')
	{
		if (data->utils.uppercase)
			buf_put_string("0X", 2, data);
		else
			buf_put_string("0x", 2, data);
	}
	else if (data->utils.is_signed)
	{
		if (data->utils.is_negative)
			buf_put_chars('-', 1, data);
		else if (!data->utils.is_negative)
		{
			if (data->flags.plus)
				buf_put_chars('+', 1, data);
			else if (data->flags.space && !data->flags.plus)
				buf_put_chars(' ', 1, data);
		}
	}
}

/*
//  NOTE: flags in number:
//  ('-' justify left)
//  ('+' force sign)
//  (' ' if no sign then blank space before number)
//  ('#' indicate base)
//  ('0' left pad with zeros instead of spaces)
//  (width - number or '*' for argument - minimum width)
//  (precision - .number or '*' for argument - minimum number of digits)
*/
void	render_number(t_data *data, t_union_long number)
{
	data->utils.tmp = ft_ltoa_base(number.signed_l, \
					data->utils.base, data->utils.uppercase, data->flags.type);
	data->utils.tmp_len = ft_strlen(data->utils.tmp);
	set_num_padding_zeros(data);
	set_num_padding_spaces(data);
	if (data->flags.minus)
	{
		num_put_sign(data);
		buf_put_chars('0', data->utils.padding_zeros, data);
		buf_put_string(data->utils.tmp, data->utils.tmp_len, data);
		free(data->utils.tmp);
		buf_put_chars(' ', data->utils.padding, data);
	}
	else
	{
		buf_put_chars(' ', data->utils.padding, data);
		num_put_sign(data);
		buf_put_chars('0', data->utils.padding_zeros, data);
		buf_put_string(data->utils.tmp, data->utils.tmp_len, data);
		free(data->utils.tmp);
	}
}
