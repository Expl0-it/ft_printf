/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:46:14 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/13 11:01:31 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	render_format(t_data *data)
{
	char	type;

	type = data->flags.type;
	if ('%' == type)
		render_char(data, '%');
	if ('c' == type)
		render_char(data, va_arg(data->ap, int));
	if ('s' == type)
		render_str(data, va_arg(data->ap, char *));
	// TODO: int, hex
}
