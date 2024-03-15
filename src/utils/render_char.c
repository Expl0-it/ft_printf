/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:03 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/15 21:16:07 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// NOTE: flags in char: ('-' justify left) && (width)
void	render_char(t_data *data, int c)
{
	int	width;

	if ('%' == data->flags.type)
	{
		buf_put_chars('%', 1, data);
		return ;
	}
	width = data->flags.width;
	if (1 < width)
	{
		if (data->flags.minus)
		{
			buf_put_chars(c, 1, data);
			buf_put_chars(' ', (width - 1), data);
		}
		else
		{
			buf_put_chars(' ', (width - 1), data);
			buf_put_chars(c, 1, data);
		}
	}
	else
		buf_put_chars(c, 1, data);
}
