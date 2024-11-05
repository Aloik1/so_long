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
	// check if the number of arguments is valid
	if (argc != 2)
	{
		ft_printerror("Error: Invalid number of arguments\n");
		return (0);
	}
	// check if the map file is valid
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printerror("Error: Invalid map file\n");
		return (0);
	}
	return (1);
}
