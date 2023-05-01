/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:22:19 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/01 18:05:02 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
 // needs to be parsed
int	main(int arc, char **arv)
{
	pthread_t		*th;
	t_args			*args;
	t_philo			*phil;
	pthread_mutex_t	*printm;
	int				i;

	args = malloc(sizeof(t_args));
	if (ft_non_number_error(arc, arv, 1, 0) < 0)
		return (-4);
	i = 0;
	args->nophil = ft_atoi(arv[1]);
	args->die = ft_atoi(arv[2]);
	args->eat = ft_atoi(arv[3]);
	args->sleep = ft_atoi(arv[4]);
	args->ntoeat = ft_atoi(arv[5]);	
	if (ft_negative_error(*args) < 0)
		return (-5);
	args->neatlim = 0;
	args->death = 0;
	phil = malloc(args->nophil * sizeof(t_philo));
	args->mutex = malloc(args->nophil * sizeof(pthread_mutex_t));
	printm = malloc(sizeof(pthread_mutex_t));
	th = malloc((args->nophil) * sizeof(pthread_t));
	while (i < args->nophil)
		pthread_mutex_init(&args->mutex[i++], NULL);
	i = 0;
	pthread_mutex_init(printm, NULL);
	while (i < args->nophil)
	{
		phil[i].noteat = ft_atoi(arv[5]);
		phil[i].id = i;
		phil[i].args = args;
		phil[i].noteat = 0;
		phil[i].lfork = &phil[i].args->mutex[i];
		phil[i].rfork = &phil[i].args->mutex[(i + 1) %
			args->nophil];
		phil[i].start_time = get_current_time();
		phil[i].death = 0;
		phil[i].print = printm;
		i++;
	}
	i = 0;
	phil[0].start = get_current_time();
	while (i < args->nophil)
	{
		phil[i].time = phil[0].start;
		pthread_create(&th[i], NULL, runit, &phil[i]);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < args->nophil)
		{
			size_t ping = get_current_time();

			if ((ping - phil[i].time) >= args->die)
			{
				print_time(&phil[i], "died.");
				return (0);
			}	
			i++;
		}
		if (args->neatlim == args->nophil)
			return (0);
	}
	i = 0;
	while (i < args->nophil)
		pthread_detach(th[i++]);
	i = 0;
	while (i < args->nophil)
		pthread_mutex_destroy(&args->mutex[i++]);
	return (0);
}
