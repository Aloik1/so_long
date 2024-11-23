/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:30:22 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 14:30:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	basic_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printerror("Invalid number of arguments\n");
		return (0);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printerror("Invalid map file\n");
		return (0);
	}
	return (1);
}
