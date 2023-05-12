/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:46:15 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/12 22:34:36 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	mysleep(size_t sleep_time)
{
	size_t	current;

	current = get_current_time();
	while (current + sleep_time > get_current_time())
		usleep(400);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_time(t_philo *p, char *s)
{
	size_t	current;

	current = get_current_time() - p->start_time;
	pthread_mutex_lock(p->print);
	printf("%zu ms: philosopher[%d] %s\n", current, p->id + 1, s);
	pthread_mutex_unlock(p->print);
}
