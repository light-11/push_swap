/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42.ja>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:45 by ayanaga           #+#    #+#             */
/*   Updated: 2026/07/27 16:13:48 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->rank = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **stack, int content)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew(content);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	count_node(t_list **stack)
{
	t_list *first_node;
	int count;

	count = 0;
	first_node = *stack;
	if (*stack == NULL)
		return (0);
	while ((*stack)->next != NULL)
	{
		count++;
		*stack = (*stack)->next;
	}
	count++;
	*stack = first_node;
	return (count);
}