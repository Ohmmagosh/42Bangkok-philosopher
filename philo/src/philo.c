/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:52:47 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/04 02:40:07 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>

void	*routine(void *arg)
{
	t_pro			*p;
	int				i;
	struct timeval	time;

	gettimeofday(&time, NULL);
	p = (t_pro *)arg;
	i = p->index;
	p->philo[i].time_p = p->info.time_v;
	while (p->alive)
	{
		if (!philo_eat_rightfork(p, time, i))
			return (NULL);
		if (!philo_eat_leftfork(p, time, i))
			return (NULL);
		if (!philo_sleep(p, time, i))
			return (NULL);
		if (!philo_think(p, time, i))
			return (NULL);
	}
	return (NULL);
}

int	philo(t_pro *p)
{
	if (!create_fork(p))
		return (0);
	if (!create_philo(p))
		return (0);
	if (!create_phread(p))
		return (0);
	if (!detach_destroy(p))
		return (0);
	if (!free_philo(p))
		return (0);
	return (1);
}

int	create_fork(t_pro *p)
{
	int	i;

	i = 0;
	p->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p->philo_c);
	p->table = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	if (!p->fork || !p->table)
		return (0);
	while (i < p->philo_c)
	{
		if (pthread_mutex_init(&p->fork[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(p->table, NULL) != 0)
		return (0);
	return (1);
}

int	create_philo(t_pro *p)
{
	int	i;

	i = 0;
	p->philo = (t_philo *)malloc(sizeof(t_philo) * p->philo_c);
	if (!p->philo)
		return (0);
	while (i < p->philo_c)
	{
		if (i == p->philo_c -1)
			p->philo[i].fork_left = 0;
		else
			p->philo[i].fork_left = i +1;
		p->philo[i].fork_right = i;
		i++;
	}
	i = 0;
	while (i < p->philo_c)
	{
		p->philo[i].id = i + 1;
		p->philo[i].len_eat = 0;
		i++;
	}
	return (1);
}

int	create_phread(t_pro *p)
{
	int	i;

	i = 0;
	while (i < p->philo_c)
	{
		p->index = i;
		if (pthread_create(&(p->philo[i].pt), NULL, &routine, p) != 0)
			return (0);
		i++;
		usleep(800);
	}
	i = 0;
	if (pthread_create(&(p->chk), NULL, &chk_die, p) != 0)
		return (0);
	while (i < p->philo_c)
	{
		if (pthread_join(p->philo[i].pt, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(p->chk, NULL) != 0)
		return (0);
	return (1);
}
