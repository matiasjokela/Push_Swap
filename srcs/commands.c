/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:33:57 by mjokela           #+#    #+#             */
/*   Updated: 2022/06/30 15:34:07 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap first two elements of a stack, do nothing if fewer than two elements */
void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->next == NULL || stack->next->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

/* Push first element from stack src to stack dst, do nothing if src is empty */
void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if ((*src)->next == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*	Shift up all elements in a stack, first becomes last.
	Do nothing if fewer than two elements */
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return ;
	tmp = (*stack);
	head = (*stack)->next;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack) = head;
}

/*	Shift down all elements in a stack, last becomes first.
	Do nothing if fewer than two elements */
void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return ;
	tmp = *stack;
	while ((*stack)->next->next->next != NULL)
		*stack = (*stack)->next;
	head = (*stack)->next;
	(*stack)->next = head->next;
	head->next = tmp;
	(*stack) = head;
}
