/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:24:20 by psuanpro          #+#    #+#             */
/*   Updated: 2022/11/27 22:10:37 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
