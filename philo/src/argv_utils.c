/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:00:03 by psuanpro          #+#    #+#             */
/*   Updated: 2022/11/27 04:20:22 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <limits.h>

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	chk_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	chk_positive(int ac, t_pro *p)
{
	if (p->info.t_die < 0 ||p->info.t_eat < 0 || p->info.t_sleep < 0)
		return (0);
	if (p->philo_c < 0)
		return (0);
	if (ac == 6)
	{
		if (!p->info.e_philo)
			return (0);
	}
	return (1);
}

int	chk_minmax(int ac, t_pro *p)
{
	if (p->info.t_die > INT_MAX ||p->info.t_eat > INT_MAX || p->info.t_sleep > INT_MAX)
		return (0);
	if (p->philo_c > INT_MAX)
		return (0);
	if (p->info.t_die <= 0 || p->info.t_eat <= 0 || p->info.t_sleep <= 0)
		return (0);
	if (p->philo_c <= 0)
		return (0);
	if (ac == 6)
	{
		if (p->info.e_philo > INT_MAX || p->info.e_philo <= 0)
			return (0);
	}
	return (1);
}

void	putstr_fd(int fd, char *s)
{	
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}