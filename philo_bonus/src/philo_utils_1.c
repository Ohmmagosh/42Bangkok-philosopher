/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:06:30 by psuanpro          #+#    #+#             */
/*   Updated: 2022/11/30 21:27:53 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../philo_bonus.h"

// int	philo_eat_forkright(t_pro *p, struct timeval time, int i)
// {
// 	pthread_mutex_lock(&p->fork[p->philo[i].fork_right]);
// 	gettimeofday(&time, NULL);
// 	if (p->alive == 0)
// 	{
// 		pthread_mutex_unlock(&p->fork[p->philo[i].fork_right]);
// 		return (0);
// 	}
// 	pthread_mutex_lock(p->table);
// 	printf("%ldms %d has taken a fork\n", \
// 		get_time(p->info.time_v, time), p->philo[i].id);
// 	pthread_mutex_unlock(p->table);
// 	return (1);
// }

// int	philo_eat_forkleft(t_pro *p, struct timeval time, int i)
// {
// 	pthread_mutex_lock(&p->fork[p->philo[i].fork_left]);
// 	gettimeofday(&time, NULL);
// 	p->philo[i].time_p = time;
// 	if (p->alive == 0)
// 	{
// 		pthread_mutex_unlock(&p->fork[p->philo[i].fork_left]);
// 		pthread_mutex_unlock(&p->fork[p->philo[i].fork_right]);
// 		return (0);
// 	}
// 	pthread_mutex_lock(p->table);
// 	printf("%ldms %d has taken a fork\n", get_time(p->info.time_v, time), \
// 		p->philo[i].id);
// 	printf("%ldms %d is eating\n", get_time(p->info.time_v, time), \
// 		p->philo[i].id);
// 	if (p->info.e_philo != -1 && p->info.e_philo != 0)
// 		p->philo[i].len_eat++;
// 	if (p->philo[i].len_eat == p->info.e_philo)
// 		p->each_eat++;
// 	pthread_mutex_unlock(p->table);
// 	my_usleep(p->info.t_eat);
// 	pthread_mutex_unlock(&p->fork[p->philo[i].fork_left]);
// 	pthread_mutex_unlock(&p->fork[p->philo[i].fork_right]);
// 	return (1);
// }

// int	philo_sleep(t_pro *p, struct timeval time, int i)
// {
// 	gettimeofday(&time, NULL);
// 	if (p->alive == 0)
// 		return (0);
// 	printf("%ldms %d is sleeping\n", get_time(p->info.time_v, time), \
// 		p->philo[i].id);
// 	my_usleep(p->info.t_sleep);
// 	return (1);
// }

// int	philo_think(t_pro *p, struct timeval time, int i)
// {
// 	gettimeofday(&time, NULL);
// 	if (p->alive == 0)
// 		return (0);
// 	printf("%ldms %d is thinking\n", get_time(p->info.time_v, time), \
// 		p->philo[i].id);
// 	return (1);
// }

// int	detach_destroy(t_pro *p)
// {
// 	int	i;

// 	i = 0;
// 	while (i < p->philo_c)
// 	{
// 		pthread_detach(p->philo[i].pt);
// 		if (pthread_mutex_destroy(&p->fork[i]) != 0)
// 			return (0);
// 		i++;
// 	}
// 	if (pthread_mutex_destroy(p->table) != 0)
// 		return (0);
// 	return (1);
// }
