/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:30:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/24 14:51:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static unsigned long	convert_base(long tmp, bool uppercase)
{
	if (tmp >= 10 && false == uppercase)
		return (tmp - 10 + 'a');
	else if (tmp >= 10 && true == uppercase)
		return (tmp - 10 + 'A');
	else
		return (tmp + '0');
}

char	*ft_ltoa_base(unsigned long number, unsigned int base, \
				bool uppercase, char type)
{
	int				i;
	char			*str;
	unsigned long	tmp;

	if ((long)number < 0 && type != 'p')
		number = -number;
	i = 1;
	tmp = number;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	str = (char *)malloc((i + 1) * sizeof(char));
	if (NULL == str)
		return (NULL);
	str[i--] = 0;
	while (i >= 0)
	{
		tmp = number % base;
		str[i] = convert_base(tmp, uppercase);
		number /= base;
		i--;
	}
	return (str);
}
