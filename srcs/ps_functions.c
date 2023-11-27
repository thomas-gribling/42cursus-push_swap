/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:25:56 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/21 08:46:45 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (0);
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	return (1);
}

int	ps_rotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	if (stack->size < 2)
		return (0);
	tmp = stack->array[0];
	i = -1;
	while (++i < stack->size - 1)
		stack->array[i] = stack->array[i + 1];
	stack->array[i] = tmp;
	return (1);
}

int	ps_rrotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	if (stack->size < 2)
		return (0);
	tmp = stack->array[stack->size - 1];
	i = stack->size;
	while (--i > 0)
		stack->array[i] = stack->array[i - 1];
	stack->array[i] = tmp;
	return (1);
}

int	ps_push(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return (0);
	stack_add(to, from->array[0]);
	stack_pop(from);
	return (1);
}

void	ps_do(char *move, t_stack *a, t_stack *b)
{
	int	state;

	state = 0;
	if (!ft_strcmp(move, "sa") || !ft_strcmp(move, "ss"))
		state = ps_swap(a);
	if (!ft_strcmp(move, "sb") || !ft_strcmp(move, "ss"))
		state = ps_swap(b);
	if (!ft_strcmp(move, "pa"))
		state = ps_push(b, a);
	if (!ft_strcmp(move, "pb"))
		state = ps_push(a, b);
	if (!ft_strcmp(move, "ra") || !ft_strcmp(move, "rr"))
		state = ps_rotate(a);
	if (!ft_strcmp(move, "rb") || !ft_strcmp(move, "rr"))
		state = ps_rotate(b);
	if (!ft_strcmp(move, "rra") || !ft_strcmp(move, "rrr"))
		state = ps_rrotate(a);
	if (!ft_strcmp(move, "rrb") || !ft_strcmp(move, "rrr"))
		state = ps_rrotate(b);
	if (state)
		ft_putndl(move);
}
