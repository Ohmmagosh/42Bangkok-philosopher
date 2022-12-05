/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:06:30 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/05 17:23:37 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	philo_fork(t_pro *p, struct timeval time, int index)
{
	sem_wait(p->table);
	sem_wait(p->fork);
	gettimeofday(&time, NULL);
	printf("%s%ldms %d has taken a fork%s\n", \
		BYEL, get_time(p->info.time_v, time), index + 1, RES);
	sem_wait(p->fork);
	gettimeofday(&time, NULL);
	printf("%s%ldms %d has taken a fork%s\n", \
		BBLU, get_time(p->info.time_v, time), index + 1, RES);
	sem_post(p->table);
	return (1);
}

int	philo_eat(t_pro *p, struct timeval time, int index)
{
	gettimeofday(&time, NULL);
	p->time_p = time;
	printf("%ldms %d is eating\n", \
		get_time(p->info.time_v, time), index + 1);
	my_usleep(p->info.t_eat);
	sem_post(p->fork);
	sem_post(p->fork);
	p->each_eat++;
	return (1);
}

int	philo_sleepthink(t_pro *p, struct timeval time, int index)
{
	gettimeofday(&time, NULL);
	printf("%ldms %d is sleeping\n", \
		get_time(p->info.time_v, time), index + 1);
	my_usleep(p->info.t_sleep);
	gettimeofday(&time, NULL);
	printf("%ldms %d is think\n", \
		get_time(p->info.time_v, time), index + 1);
	return (1);
}
