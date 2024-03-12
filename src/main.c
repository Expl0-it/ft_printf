/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:49:08 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/12 20:53:51 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int num1 = ft_printf("[%-10c]", 'a');
	ft_printf("\n");
	int num2 = ft_printf("[%-*c]", 10, 'a');
	ft_printf("\n");
	int num3 = ft_printf("[%3c]", 'a');
	ft_printf("\n");
	int num4 = ft_printf("%%%% %cbc $$%%\\", 'a');
	ft_printf("\n");
	printf("%d, %d, %d, %d\n", num1, num2, num3, num4);

	num1 = printf("[%-10c]", 'a');
	printf("\n");
	num2 = printf("[%-*c]", 10, 'a');
	printf("\n");
	num3 = printf("[%3c]", 'a');
	printf("\n");
	num4 = printf("%%%% %cbc $$%%\\", 'a');
	printf("\n");
	printf("%d, %d, %d, %d\n", num1, num2, num3, num4);
}
