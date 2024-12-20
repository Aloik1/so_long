/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:07:31 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/02 14:43:09 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int c)
{
	int	i;

	i = 0;
	if (c >= 10)
		i = i + ft_printf_u(c / 10);
	ft_putchar_fd((c % 10) + '0', 1);
	return (i + 1);
}
