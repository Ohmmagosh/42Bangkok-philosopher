/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:52:47 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/01 00:31:07 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"
#include <pthread.h>
#include <sys/fcntl.h>
#include <sys/semaphore.h>
#include <sys/signal.h>
#include <sys/time.h>
#include <unistd.h>

int	routine(t_pro *p, int index)
{
	struct timeval	time;
	
	
	p->index = index;
	gettimeofday(&(p->time_p), NULL);
	while (p->alive)
	{
		sem_wait(p->table);
		sem_wait(p->fork);
		gettimeofday(&time, NULL);
		printf("%s%ldms %d has taken a fork%s\n", YEL,get_time(p->info.time_v, time), \
			p->index + 1, RES);
		sem_wait(p->fork);
		gettimeofday(&time, NULL);
		printf("%s%ldms %d has taken a fork%s\n", BBLU, get_time(p->info.time_v, time), \
			p->index + 1, RES);
		sem_post(p->table);
		gettimeofday(&time, NULL);
		gettimeofday(&(p->time_p), NULL);
		printf("%ldms %d is eating\n", \
			get_time(p->info.time_v, time), p->index + 1);
		my_usleep(p->info.t_eat, p);
		sem_post(p->fork);
		sem_post(p->fork);
		gettimeofday(&time, NULL);
		printf("%ldms %d is sleeping\n", \
			get_time(p->info.time_v, time), p->index + 1);
		my_usleep(p->info.t_sleep, p);
		gettimeofday(&time, NULL);
		printf("%ldms %d is thinking\n", \
			get_time(p->info.time_v, time), p->index + 1);
	}
	return (1);
}

int	philo(t_pro *p)
{
	// create_philo(p);
	create_sem(p);
	process(p);

	return (1);
}

int	create_sem(t_pro *p)
{
	sem_unlink("/fork");
	sem_unlink("/table");
	sem_unlink("/chk");
	p->fork = sem_open("/fork", O_CREAT, 0644, p->philo_c);
	p->table = sem_open("/table", O_CREAT, 0644, 1);
	p->chk = sem_open("/chk", O_CREAT, 0644, 0);

	if (p->fork == SEM_FAILED || p->chk == SEM_FAILED)
		exit(0);
	return (1);
}

// int	create_philo(t_pro *p)
// {
// 	int	i;

// 	i = 0;
// 	p->philo = (t_philo *)malloc(sizeof(t_philo) * 1);
// 	if (!p->philo)
// 		return (0);
// 	// while (i < p->philo_c)
// 	// {
// 	p->philo[0].id = 0;
// 	p->philo[0].len_eat = 0;
// 		// i++;
// 	// }
// 	return (1);
// }

int	process(t_pro *p)
{
	
	int	pid[5];
	int	i;


	i = 0;
	
	while (i < p->philo_c)
	{

		gettimeofday(&(p->info.time_v), NULL);
		pid[i] = fork();
		if (pid[i] == 0)
		{
			pthread_create(&(p->pt), NULL, chk_die, p);
			routine(p, i);
			pthread_join(p->pt, NULL);
			break;
		}
		// usleep(100);
		i++;
	}
	sem_wait(p->chk);
	i = 0;
	while (i < p->philo_c)
	{
		kill(pid[i], SIGKILL);
		i++;
	}	
	// waitpid(-1, &pid, 0);

	return (1);
}
