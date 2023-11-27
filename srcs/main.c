/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:36:36 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/20 11:18:58 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		return (1);
	stack = fill_stack(ac - 1, av + 1, 0);
	if (!stack)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(stack->array, stack->size, 1))
	{
		if (stack->size <= 5)
			ft_small_sort(stack);
		else
			ft_sort(stack);
	}
	free_stack(&stack);
	return (0);
}
