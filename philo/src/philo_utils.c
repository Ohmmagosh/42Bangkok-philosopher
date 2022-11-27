/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 01:54:43 by psuanpro          #+#    #+#             */
/*   Updated: 2022/11/27 19:05:54 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*chk_die(void *arg)
{
	t_pro			*p;
	int				i;
	struct timeval	now;

	p = (t_pro *)arg;
	while (1)
	{
		i = 0;
		while (i < p->philo_c)
		{
			gettimeofday(&now, NULL);
			if (p->each_eat == p->philo_c)
			{
				p->alive = 0;
				return (NULL);
			}
			if (get_time(p->philo[i].time_p, now) > (p->info.t_die / 1000))
			{
				p->alive = 0;
				printf("%ldms %d dead\n", get_time(p->info.time_v, now),i + 1);
				return (NULL);
			}
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

size_t	my_usleep(unsigned int	time)
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