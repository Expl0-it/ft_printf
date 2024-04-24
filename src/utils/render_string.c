/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:03 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/24 14:39:07 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// NOTE: flags in str: ('-' justify left) && (width) && precision
static void	set_str_padding(t_data *data, char *s)
{
	int		length;

	length = ft_strlen(s);
	if (0 < data->flags.width)
	{
		if (0 <= data->flags.precision)
		{
			if (length < data->flags.precision)
				data->utils.padding = data->flags.width - length;
			else if (length > data->flags.precision)
				data->utils.padding = data->flags.width - data->flags.precision;
		}
		else
		{
			data->utils.padding = data->flags.width - length;
		}
	}
}

void	render_str(t_data *data, char *s)
{
	if (NULL == s)
		s = "(null)";
	set_str_padding(data, s);
	if (data->flags.minus)
	{
		if (0 <= data->flags.precision)
			buf_put_string(s, data->flags.precision, data);
		else
			buf_put_string(s, ft_strlen(s), data);
		buf_put_chars(' ', data->utils.padding, data);
	}
	else
	{
		buf_put_chars(' ', data->utils.padding, data);
		if (0 <= data->flags.precision)
			buf_put_string(s, data->flags.precision, data);
		else
			buf_put_string(s, ft_strlen(s), data);
	}
}
