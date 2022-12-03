/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:24:20 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/04 01:06:32 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_pro	p;

	if (ac == 5 || ac == 6)
	{
		if (!get_av(ac, av, &p))
			return (print_error());
		if (!philo(&p))
			return (print_error());
	}
	else
		print_error();
	return (0);
}
