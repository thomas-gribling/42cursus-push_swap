/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:05:59 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/21 08:47:07 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	size_t		size;
	int			*array;
}				t_stack;

int		check_args(char **args);
void	ft_small_sort(t_stack *a);
void	ft_sort(t_stack *a);
void	ft_convert(t_stack *a);
int		find_closest_path(t_stack *stack, int a, int b);
void	do_fast_push_a(t_stack *a, t_stack *b, int i);
void	do_fast_push_b(t_stack *a, t_stack *b, int i);

t_stack	*fill_stack(int size, char **args, int free_check);
void	free_stack(t_stack **stack);
void	stack_add(t_stack *stack, int element);
void	stack_pop(t_stack *stack);
size_t	stack_get_index(t_stack *stack, int value);
int		stack_scan(t_stack *stack, int start, int end);
void	print_stack(t_stack *stack);

void	ps_do(char *move, t_stack *a, t_stack *b);

char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
void	ft_putndl(char *str);
int		ft_atoi(char *nptr);
int		ft_strcmp(char *s1, char *s2);
void	free_tab(char **tab);

int		tab_min(int *tab, size_t size);
int		is_sorted(int *tab, size_t size, int ascending);
void	tab_sort(int *tab, size_t size);

#endif