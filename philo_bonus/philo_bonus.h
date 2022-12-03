/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:23 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/04 01:46:37 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stddef.h>
# include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/_types/_pid_t.h>
# include <sys/_types/_timeval.h>
# include <sys/semaphore.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "philo_color.h"
# include <signal.h>

enum e_philo {
	PHILO_DONE,
	PHILO_DIED
};

typedef struct s_info
{
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	long long int	e_philo;
	struct timeval	time_v;
	int				len_eat;
}				t_info;

typedef struct s_pro
{
	int				philo_c;
	int				alive;
	int				each_eat;
	int				index;
	t_info			info;
	pthread_t		pt;
	sem_t			*table;
	sem_t			*fork;
	sem_t			*chk;
	sem_t			*print;
	sem_t			*chk_eat;
	pid_t			*pid;
	struct timeval	time_p;
}				t_pro;

int		get_av(int ac, char **av, t_pro *p);
int		ft_atoi(char *str);
int		chk_argv(int ac, t_pro *p);
int		chk_digit(int ac, char **av);
int		chk_positive(int ac, t_pro *p);
int		chk_minmax(int ac, t_pro *p);
int		print_error(void);
int		philo(t_pro *p);
int		create_sem(t_pro *p);
int		routine(t_pro *p, int index);
int		process(t_pro *p);
int		process_utils(t_pro *p, int status);
int		philo_fork(t_pro *p, struct timeval time, int index);
int		philo_eat(t_pro *p, struct timeval time, int index);
int		philo_sleepthink(t_pro *p, struct timeval time, int index);
void	free_philo_bonus(t_pro *p);
void	init_argv(int ac, char **av, t_pro *p);
void	putstr_fd(int fd, char *s);
void	*chk_die(void *arg);
void	chk_die_utils(t_pro *p, int mode, int i, struct timeval now);
size_t	my_usleep(unsigned int time);
size_t	get_time(struct timeval t1, struct timeval t2);

#endif
