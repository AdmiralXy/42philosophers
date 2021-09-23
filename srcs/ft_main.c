/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <kricky@student.21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:46:26 by kricky            #+#    #+#             */
/*   Updated: 2021/09/21 22:17:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

int	main(int argc, char **argv)
{
	t_collection	*phs;

	phs = malloc(sizeof(t_collection));
	if (argc < 5 || argc > 6)
		return (ft_throw(phs, ERROR_USAGE, 1));
	if (!ft_init(argc, argv, phs))
		return (1);
	ft_init_threads(phs);
	return (0);
}
