/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:00:15 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/12 21:07:24 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	launch(t_philo *phil, t_args *args, pthread_t *th)
{
	int	i;

	i = 0;
	phil[0].start = get_current_time();
	while (i < args->nophil)
	{
		phil[i].time = phil[0].start;
		pthread_create(&th[i], NULL, runit, &phil[i]);
		pthread_detach(th[i]);
		i++;
	}
}
