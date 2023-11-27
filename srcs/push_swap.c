/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:12:52 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/23 09:04:34 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	*free_fill(t_stack *stack, char **args, int check, int check_size)
{
	int	i;

	if (check_size && stack->size > 0)
		free(stack->array);
	free(stack);
	if (check)
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
	}
	return (NULL);
}

static int	check_int(char *s)
{
	if (s[0] == '-')
	{
		if (ft_strlen(s) > 11)
			return (0);
		if (ft_strlen(s) < 11)
			return (1);
		if (s[1] >= '2' && s[2] >= '1' && s[3] >= '4')
			if (s[4] >= '7' && s[5] >= '4' && s[6] >= '8')
				if (s[7] >= '3' && s[8] >= '6' && s[9] >= '4')
					if (s[10] > '8')
						return (0);
	}
	else
	{
		if (ft_strlen(s) > 10)
			return (0);
		if (ft_strlen(s) < 10)
			return (1);
		if (s[0] >= '2' && s[1] >= '1' && s[2] >= '4')
			if (s[3] >= '7' && s[4] >= '4' && s[5] >= '8')
				if (s[6] >= '3' && s[7] >= '6' && s[8] >= '4')
					if (s[9] > '7')
						return (0);
	}
	return (1);
}

t_stack	*fill_stack(int size, char **args, int free_check)
{
	t_stack		*stack;
	char		**my_args;
	int			i;

	stack = malloc(sizeof(t_stack));
	my_args = args;
	if (size == 1 && !check_args(my_args))
	{
		my_args = ft_split(*args, ' ');
		free_check = 1;
		size = 0;
		while (my_args[size])
			size++;
	}
	if (!check_args(my_args))
		return (free_fill(stack, my_args, free_check, 0));
	stack->array = malloc((size + 1) * sizeof(int));
	stack->size = size;
	i = -1;
	while (my_args[++i])
		stack->array[i] = ft_atoi(my_args[i]);
	if (free_check)
		free_tab(my_args);
	return (stack);
}

static int	check_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (!check_int(args[i]))
			return (0);
		while (args[i][j])
		{
			if ((args[i][j] < '0' || args[i][j] > '9') && args[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (check_duplicate(args));
}
