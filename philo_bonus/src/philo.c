/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:52:47 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/04 20:46:03 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	routine(t_pro *p, int index)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	gettimeofday(&(p->time_p), NULL);
	while (1)
	{
		p->index = index;
		philo_fork(p, time, index);
		philo_eat(p, time, index);
		philo_sleepthink(p, time, index);
	}
	return (1);
}

int	philo(t_pro *p)
{
	create_sem(p);
	process(p);
	free_philo_bonus(p);
	return (1);
}

int	create_sem(t_pro *p)
{
	sem_unlink("/fork");
	sem_unlink("/table");
	sem_unlink("/chk");
	p->fork = sem_open("/fork", O_CREAT, 0644, p->philo_c);
	p->table = sem_open("/table", O_CREAT, 0644, 1);
	p->chk = sem_open("/chk", O_CREAT, 0644, 1);
	return (1);
}

int	process(t_pro *p)
{
	int	i;
	int	status;

	status = 0;
	i = 0;
	p->pid = (pid_t *)malloc(sizeof(pid_t) * p->philo_c);
	if (!p->pid)
		return (0);
	gettimeofday(&(p->info.time_v), NULL);
	while (i < p->philo_c)
	{
		p->pid[i] = fork();
		if (p->pid[i] == 0)
		{
			pthread_create(&(p->pt), NULL, chk_die, p);
			routine(p, i);
			pthread_detach(p->pt);
			break ;
		}
		usleep(100);
		i++;
	}
	process_utils(p, status);
	return (1);
}

int	process_utils(t_pro *p, int status)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->philo_c)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == PHILO_DIED)
		{
			j = 0;
			while (i < p->philo_c)
			{
				kill(p->pid[i], SIGKILL);
				j++;
			}
			break ;
		}
		i++;
	}
	return (1);
}
