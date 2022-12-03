/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 01:54:43 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/04 02:41:46 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>

void	*chk_die(void *arg)
{
	t_pro			*p;
	int				i;
	struct timeval	now;

	gettimeofday(&now, NULL);
	p = (t_pro *)arg;
	while (1)
	{
		i = 0;
		while (i < p->philo_c)
		{
			gettimeofday(&now, NULL);
			if (p->each_eat == p->philo_c)
				return (chk_die_utils(p, 0, i, now));
			if (get_time(p->philo[i].time_p, now) > (p->info.t_die / 1000))
				return (chk_die_utils(p, 1, i, now));
			i++;
		}
	}
	return (NULL);
}

size_t	get_time(struct timeval t1, struct timeval t2)
{
	return (((t2.tv_sec * 1000) + (t2.tv_usec / 1000)) \
			- ((t1.tv_sec * 1000) + (t1.tv_usec / 1000)));
}

size_t	my_usleep(unsigned int time, t_pro *p)
{
	struct timeval	t1;
	struct timeval	t2;
	size_t			iteration;

	time = time / 1000;
	gettimeofday(&t1, NULL);
	gettimeofday(&t2, NULL);
	iteration = get_time(t1, t2);
	while (iteration < time)
	{
		usleep(200);
		gettimeofday(&t2, NULL);
		iteration = get_time(t1, t2);
		if (p->alive == 0)
			break ;
	}
	return (iteration);
}

void	*chk_die_utils(t_pro *p, int mode, int i, struct timeval now)
{
	p->alive = 0;
	if (mode == 1)
		printf("%s%ldms %d die%s\n", BRED, \
			get_time(p->info.time_v, now), i + 1, RES);
	return (NULL);
}

int	free_philo(t_pro *p)
{
	free(p->philo);
	free(p->fork);
	free(p->table);
	return (1);
}
