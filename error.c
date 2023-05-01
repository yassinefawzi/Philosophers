/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:26:30 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/01 18:02:32 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_zero_error_message(void)
{
	write(2, "Error zero had been found\n", 26);
}

int	ft_negative_error(t_args args)
{
	if (args.nophil == 0 || args.die == 0)
	{
		ft_zero_error_message();
		return (-2);
	}
	if (args.eat == 0)
	{
		ft_zero_error_message();
		return (-2);
	}
	if (args.sleep == 0)
	{
		ft_zero_error_message();
		return (-2);
	}
	return (0);
}

void	ft_non_number_error_messgae(void)
{
	write(2, "Error non number found\n", 23);
}

int	ft_non_number_error(int arc, char **str, int i, int j)
{
	if (arc < 5 || arc > 6)
	{
		printf("Error\n");
		return (-1);
	}
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				ft_non_number_error_messgae();
				return (-3);
			}
			j++;
		}
		i++;
	}
	return (0);
}

