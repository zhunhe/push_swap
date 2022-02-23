/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:36:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/23 13:45:15 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc - 1, ++argv);
	else
		quit_push_swap(NULL, PLEASE_INPUT_NUMBERS);
	return (0);
}
