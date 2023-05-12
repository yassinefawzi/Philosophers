/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:11:02 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/12 21:07:08 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	routine(t_philo *p)
{
	pthread_mutex_lock(p->lfork);
	print_time(p, "has taken left fork.");
	if (p->args->nophil == 1)
	{
		mysleep(p->args->die);
		pthread_mutex_unlock(p->lfork);
		return ;
	}
	pthread_mutex_lock(p->rfork);
	print_time(p, "has taken right fork.");
	p->time = get_current_time();
	print_time(p, "is eating.");
	mysleep(p->args->eat);
	pthread_mutex_unlock(p->rfork);
	pthread_mutex_unlock(p->lfork);
	print_time(p, "is sleeping.");
	mysleep(p->args->sleep);
	print_time(p, "is thinking...");
	p->noteat++;
}

void	*runit(void *arg)
{
	t_philo	*p;

	p = arg;
	if (p->id % 2)
		usleep(500);
	while (1)
	{
		routine(p);
		if (p->noteat == p->args->ntoeat)
		{
			print_time(p, "finished all his meals.");
			p->args->neatlim++;
		}
	}
}

int	looper(t_philo *phil, t_args *args, pthread_mutex_t *m_death)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(m_death);
		if (check_for_death(0, args, &phil[i], m_death) < 0)
		{
			pthread_mutex_unlock(m_death);
			return (-1);
		}
		if (args->neatlim == args->nophil)
		{
			pthread_mutex_unlock(m_death);
			return (-2);
		}
		i++;
		pthread_mutex_unlock(m_death);
		if (i >= args->nophil)
			i = 0;
	}
}
