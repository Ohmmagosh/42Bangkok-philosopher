/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 01:54:43 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/04 20:46:59 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*chk_die(void *arg)
{
	t_pro			*p;
	struct timeval	now;

	p = (t_pro *)arg;
	while (1)
	{
		gettimeofday(&now, NULL);
		if (p->info.e_philo != -1 && p->each_eat >= p->info.e_philo)
			chk_die_utils(p, 0, p->index, now);
		if (get_time(p->time_p, now) > (p->info.t_die))
			chk_die_utils(p, 1, p->index, now);
	}
	return (NULL);
}

size_t	get_time(struct timeval t1, struct timeval t2)
{
	return (((t2.tv_sec * 1000) + (t2.tv_usec / 1000)) \
			- ((t1.tv_sec * 1000) + (t1.tv_usec / 1000)));
}

size_t	my_usleep(unsigned int time)
{
	struct timeval	t1;
	struct timeval	t2;
	size_t			iteration;

	time = time / 1000;
	gettimeofday(&t1, NULL);
	usleep(time * 0.9);
	gettimeofday(&t2, NULL);
	iteration = get_time(t1, t2);
	while (iteration < time)
	{
		usleep(time * 0.01);
		gettimeofday(&t2, NULL);
		iteration = get_time(t1, t2);
	}
	return (iteration);
}

void	chk_die_utils(t_pro *p, int mode, int i, struct timeval now)
{
	if (mode == 1)
	{
		sem_wait(p->chk);
		usleep(100 * p->philo_c);
		printf("%s%ldms %d die%s\n", BRED, \
			get_time(p->info.time_v, now), i + 1, RES);
		exit(PHILO_DIED);
	}
	else if (mode == 0)
		exit(PHILO_DONE);
	return ;
}

void	free_philo_bonus(t_pro *p)
{
	free(p->pid);
	sem_close(p->fork);
	sem_close(p->table);
	sem_close(p->chk);
}