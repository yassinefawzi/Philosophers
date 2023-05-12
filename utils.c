/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:31:22 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/12 23:56:17 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	data_loader(t_philo *phil, t_args
*args, pthread_mutex_t *printm, char *arv5)
{
	int	i;

	pthread_mutex_init(printm, NULL);
	i = 0;
	while (i < args->nophil)
	{
		phil[i].noteat = ft_atoi(arv5);
		phil[i].id = i;
		phil[i].args = args;
		phil[i].noteat = 0;
		phil[i].lfork = &phil[i].args->mutex[i];
		phil[i].rfork = &phil[i].args->mutex[(i + 1)
			% args->nophil];
		phil[i].start_time = get_current_time();
		phil[i].death = 0;
		phil[i].print = printm;
		phil[i].pm_eat = args->m_eat;
		phil[i].pm_lim = args->m_lim;
		i++;
	}
}

int	check_for_death(int i, t_args *args, t_philo
*phil)
{
	size_t	ping;

	while (i < args->nophil)
	{
		ping = get_current_time();
		pthread_mutex_lock(phil->pm_eat);
		if ((ping - phil->time) > args->die)
		{
			pthread_mutex_unlock(phil->pm_eat);
			print_time(phil, "died.");
			return (-1);
		}
		pthread_mutex_unlock(phil->pm_eat);
		i++;
	}
	return (0);
}

t_args	*args_loader(t_args *args, char **arv)
{
	args->i = 0;
	args->m_eat = malloc(sizeof(pthread_mutex_t));
	args->m_lim = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(args->m_eat, NULL);
	pthread_mutex_init(args->m_lim, NULL);
	args->nophil = ft_atoi(arv[1]);
	args->die = ft_atoi(arv[2]);
	args->eat = ft_atoi(arv[3]);
	args->sleep = ft_atoi(arv[4]);
	args->ntoeat = ft_atoi(arv[5]);
	args->neatlim = 0;
	args->death = 0;
	return (args);
}
