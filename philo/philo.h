/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:23 by psuanpro          #+#    #+#             */
/*   Updated: 2022/11/27 19:20:57 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/_types/_timeval.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct	s_philo
{
	pthread_t		pt;
	int				id;
	int				fork_left;
	int				fork_right;
	struct	timeval	time_p;
	int				len_eat;
}				t_philo;

typedef struct	s_info
{
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				e_philo;
	struct timeval	time_v;
}				t_info;

typedef struct	s_pro
{
	int				philo_c;
	int				alive;
	int				each_eat;
	int				index;
	t_info			info;
	t_philo			*philo;
	pthread_t		chk;
	pthread_mutex_t *fork;
	pthread_mutex_t *table;
}				t_pro;

int		get_av(int ac, char **av, t_pro *p);
int		ft_atoi(char *str);
int		chk_argv(int ac, t_pro *p);
int		chk_digit(int ac, char **av);
int		chk_positive(int ac, t_pro *p);
int		chk_minmax(int ac, t_pro *p);
int		print_error(void);
int		philo(t_pro *p);
int		create_philo(t_pro *p);
int		create_fork(t_pro *p);
int		create_phread(t_pro *p);
int		philo_eat_forkleft(t_pro *p, struct timeval time, int i);
int		philo_eat_forkright(t_pro *p, struct timeval time, int i);
int		philo_think(t_pro *p, struct timeval time, int i);
int		philo_sleep(t_pro *p, struct timeval time, int i);
int		chk_eat(t_pro *p, int i);
int		detach_destroy(t_pro *p);
void	*routine(void *arg);
void	init_argv(int ac, char **av, t_pro *p);
void	putstr_fd(int fd, char *s);
void	*chk_die(void *arg);
size_t	my_usleep(unsigned int	time);
size_t	get_time(struct timeval t1, struct timeval t2);

#endif
