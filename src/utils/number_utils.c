/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:27:54 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/15 19:37:50 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	precision_zero_padding(t_data *data)
{
	if (data->flags.precision >= 0)
	{
		if (data->flags.precision > data->flags.tmp_len)
		{
			data->flags.padding_zeros = data->flags.precision - \
											data->flags.tmp_len;
			return (1);
		}
	}
	return (0);
}

void	set_num_padding_zeros(t_data *data)
{
	if (precision_zero_padding(data))
		return ;
	if (data->flags.zero)
	{
		if (data->flags.minus)
			return ;
		if (data->flags.width > data->flags.tmp_len)
			data->flags.padding_zeros = data->flags.width - \
											data->flags.tmp_len;
		if ('u' == data->flags.type)
			return ;
		else if ((ft_strchr("xX", data->flags.type) && data->flags.hash
				&& data->flags.tmp[0] != '0') || data->flags.type == 'p')
			data->flags.padding_zeros -= 2;
		else if (data->flags.is_negative || (!data->flags.is_negative 
			&& (data->flags.plus || data->flags.space)))
			data->flags.padding_zeros -= 1;
	}
	if (data->flags.padding_zeros < 0)
		data->flags.padding_zeros = 0;
}

void	set_num_padding_spaces(t_data *data)
{
	data->flags.padding = data->flags.width - data->flags.padding_zeros \
		- data->flags.tmp_len;
	if (ft_strchr("uxXp", data->flags.type))
	{
		if ((ft_strchr("xX", data->flags.type) && data->flags.hash
				&& data->flags.tmp[0] != '0') || data->flags.type == 'p')
			data->flags.padding -= 2;
		return ;
	}
	if (data->flags.is_negative)
	{
		data->flags.padding--;
		return ;
	}
	if (!data->flags.is_negative && (data->flags.plus || data->flags.space))
		data->flags.padding--;
}
