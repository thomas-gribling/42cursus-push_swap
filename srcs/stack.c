/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:21:00 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/20 11:19:14 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_add(t_stack *stack, int element)
{
	int		*tmp;
	size_t	i;

	if (stack->size == 0)
	{
		stack->array = malloc(2 * sizeof(int));
		stack->array[0] = element;
	}
	else
	{
		tmp = malloc((stack->size + 2) * sizeof(int));
		i = 0;
		tmp[0] = element;
		while (++i < stack->size + 1)
			tmp[i] = stack->array[i - 1];
		free(stack->array);
		stack->array = malloc((stack->size + 2) * sizeof(int));
		i = -1;
		while (++i < stack->size + 1)
			stack->array[i] = tmp[i];
		free(tmp);
	}
	stack->size++;
}

void	stack_pop(t_stack *stack)
{
	int		*tmp;
	size_t	i;

	if (stack->size == 0)
		return ;
	else if (stack->size == 1)
		free(stack->array);
	else
	{
		tmp = malloc((stack->size) * sizeof(int));
		i = 0;
		while (++i < stack->size)
			tmp[i - 1] = stack->array[i];
		free(stack->array);
		stack->array = malloc((stack->size) * sizeof(int));
		i = -1;
		while (++i < stack->size)
			stack->array[i] = tmp[i];
		free(tmp);
	}
	stack->size--;
}

void	free_stack(t_stack **stack)
{
	if ((*stack)->size > 0)
		free((*stack)->array);
	free(*stack);
}

size_t	stack_get_index(t_stack *stack, int value)
{
	size_t	i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->array[i] == value)
			return (i);
	}
	return (0);
}

int	stack_scan(t_stack *stack, int start, int end)
{
	size_t	i;

	i = -1;
	while (++i < stack->size)
	{
		if (stack->array[i] >= start && stack->array[i] <= end)
			return (1);
	}
	return (0);
}
