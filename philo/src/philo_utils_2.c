/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:29:44 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/05 20:33:27 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*one_routine(void *arg)
{
	t_pro	*p;
	p = (void *)arg;
	pthread_mutex_lock(&p->fork[p->philo[0].fork_right]);
	printf("%s%dms 1 has take fork%s\n", BYEL, 0, RES);
	usleep(p->info.t_die);
	printf("%s%dms 1 is die %s\n", BRED, p->info.t_die / 1000, RES);
	return (NULL);
}

int	one_philo(t_pro *p)
{
	p->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p->philo_c);
	if (pthread_mutex_init(&(p->fork[0]), NULL) == -1)
		return (0);
	p->philo = (t_philo *)malloc(sizeof(t_philo) * p->philo_c);
	p->philo[0].fork_right = 0;
	pthread_create(&(p->philo[0].pt), NULL, one_routine, p);
	pthread_join(p->philo[0].pt, NULL);
	pthread_detach(p->philo[0].pt);
	pthread_mutex_destroy(p->fork);
	free(p->fork);
	free(p->philo);
	return (0);
}