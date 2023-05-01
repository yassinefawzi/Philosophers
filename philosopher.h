/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfawzi <yfawzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:22:40 by yfawzi            #+#    #+#             */
/*   Updated: 2023/05/01 16:13:11 by yfawzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct t_args
{
	int				nophil;
	int				die;
	int				eat;
	int				sleep;
	int				ntoeat;
	int				neatlim;
	int				death;
	pthread_mutex_t	*mutex;
}	t_args;

typedef struct t_philo
{
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*print;
	t_args			*args;
	size_t			start;
	size_t			time;
	size_t			death;
	size_t			start_time;
	int				id;
	int				noteat;
}	t_philo;

void	*runit(void *arg);
void	routine(t_philo *p);
size_t	get_current_time(void);
int		ft_atoi(const char *str);
void	mysleep(size_t sleep_time);
int		ft_negative_error(t_args args);
void	print_time(t_philo *p, char *s);
size_t	timeret(size_t time, size_t start);
int		ft_non_number_error(int arc, char **str, int i, int j);
#endif