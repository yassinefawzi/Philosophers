/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:22:19 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/12 20:41:58 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int arc, char **arv)
{
	pthread_t		*th;
	t_args			*args;
	t_philo			*phil;
	pthread_mutex_t	*printm;
	pthread_mutex_t	*m_death;
	int				i;

	args = malloc(sizeof(t_args));
	if (ft_non_number_error(arc, arv, 1, 0) < 0)
		return (-4);
	args = args_loader(args, arv);
	if (ft_negative_error(*args) < 0)
		return (-5);
	phil = malloc(args->nophil * sizeof(t_philo));
	args->mutex = malloc(args->nophil * sizeof(pthread_mutex_t));
	printm = malloc(sizeof(pthread_mutex_t));
	m_death = malloc(sizeof(pthread_mutex_t));
	th = malloc((args->nophil) * sizeof(pthread_t));
	i = 0;
	while (i < args->nophil)
		pthread_mutex_init(&args->mutex[i++], NULL);
	data_loader(phil, args, printm, arv[5]);
	pthread_mutex_init(m_death, NULL);
	launch(phil, args, th);
	if (looper(phil, args, m_death) < 0)
		return (0);
	i = 0;
	while (i < args->nophil)
		pthread_mutex_destroy(&args->mutex[i++]);
	return (0);
}
