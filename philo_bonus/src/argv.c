/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:30:32 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/04 01:50:14 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_atoi(char *str)
{
	int						opt;
	unsigned long long		number;

	number = 0;
	opt = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			opt *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - 48;
		if (number > 9223372036854775807 && opt > 0)
			return (-1);
		if (number > 9223372036854775807 && opt < 0)
			return (0);
		str++;
	}
	return (opt * number);
}

int	get_av(int ac, char **av, t_pro *p)
{
	if (!chk_digit(ac - 1, av + 1))
		return (0);
	init_argv(ac, av, p);
	if (!p->philo_c || !p->info.t_die || !p->info.t_eat || !p->info.t_sleep)
		return (0);
	if (ac == 6)
	{
		if (!p->info.e_philo)
			return (0);
	}
	if (!chk_argv(ac, p))
		return (0);
	return (1);
}

void	init_argv(int ac, char **av, t_pro *p)
{
	p->alive = 1;
	p->philo_c = ft_atoi(av[1]);
	p->info.t_die = ft_atoi(av[2]);
	p->info.t_eat = ft_atoi(av[3]) * 1000;
	p->info.t_sleep = ft_atoi(av[4]) * 1000;
	p->info.e_philo = -1;
	p->each_eat = 0;
	if (ac == 6)
		p->info.e_philo = ft_atoi(av[5]);
}

int	chk_argv(int ac, t_pro *p)
{
	if (!chk_positive(ac, p))
		return (0);
	if (!chk_minmax(ac, p))
		return (0);
	return (1);
}

int	print_error(void)
{
	putstr_fd(2, "./philo <1> <2> <3> <4> <5> #UINT ONLY\n");
	putstr_fd(2, "1 -> N of philo \n");
	putstr_fd(2, "2 -> N of time to die\n");
	putstr_fd(2, "3 -> N of time to eat\n");
	putstr_fd(2, "4 -> N of time to sleep\n");
	putstr_fd(2, "5 -> N of each time to eat\n");
	return (0);
}
