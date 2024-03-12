/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:03 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/12 13:31:37 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// NOTE: flags in char: ('-' justify left) && (width)
void	render_char(t_data *data, int c)
{
	int	width;

	width = data->flags.width;
	if (1 < width)
	{
		if (data->flags.minus)
		{
			put_padding(c, 1, data);
			put_padding(' ', (width - 1), data);
		}
		else
		{
			put_padding(' ', (width - 1), data);
			put_padding(c, 1, data);
		}
	}
	else
		put_padding(c, 1, data);
}
