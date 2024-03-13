/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:12:24 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/13 16:19:08 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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
	ft_itoa_base(data, number); // TODO:
	set_num_padding_zeros(data);
	set_num_padding_spaces(data);
	if (data->flags.minus)
	{

	}
	else
	{

	}
}
