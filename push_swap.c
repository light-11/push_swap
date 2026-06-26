/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:44:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/27 07:43:39 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int	ft_atoi(char *nptr)
{
	int		i;
	int		minus;
	long	num;

	i = 0;
	minus = 1;
	num = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(num * minus));
}

t_list	*ft_lstnew(void *int_a1)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
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

int	compute_disorder(int count, char *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < count - 2)
	{
		while (i + 1 < count - 2)
		{
			if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
				mistakes++;
			total_pairs++;
		}
	}
	return (mistakes / total_pairs);
}

int	push_swap(int argc, char *argv[])
{
	int		disorder;
	int		i;
	int		int_a;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 2;
	disorder = compute_disorder(agc, argv);
	if (disorder == 0)
		return (0);
	stack_a = ft_lstnew(ft_atoi(argv[1]));
	stack_b = ft_lstnew(ft_atoi(argv[1]));
	while (argc > i)
	{
		ft_lstadd_back(&stack_a, ft_atoi(argv[i]));
		ft_lstadd_back(&stack_b, NULL);
	}
}

int	small_search(t_list **stack)
{
	t_list	*first_node;
	int		small_content;
	int		count;
	int		small_content_count;

	first_node = *stack_a;
	small_content = *stack_a->content;
	while ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		count++;
		if ((*stack_a)->content > small_content)
		{
			small_content = (*stack_a)->content;
			small_content_count = count;
		}
	}
}

int	count_node(t_list **stack)
{
	t_list	*first_node;
	int		count;

	count = 0;
	first_node = *stack;
	while ((*stack)->next != NULL)
	{
		count++;
		*stack = (*stack)->next;
	}
	count++;
	*stack = first_node;
	return (count);
}

void	simple(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_first_node;
	int		small_content;

	a_first_node = *stack_a;
	small_content = *stack_a->content;
	while ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->content > small_content)
			small_content = (*stack_a)->content;
	}
	a_first_node->next = *stack_b;
	*stack_b = a_first_node;
}

void	swap_a(t_list **lst)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	if ((*stack)->next != NULL)
		second_node = (*stack)->next;
	first_node->next = second_node;
	second_node->next = first_node;
}

void	swap_b(t_list **lst)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	if ((*stack)->next != NULL)
		second_node = (*stack)->next;
	first_node->next = second_node;
	second_node->next = first_node;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_first_node;

	a_first_node = *stack_a;
	if ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	a_first_node->next = *stack_b;
	*stack_b = a_first_node;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*b_first_node;

	b_first_node = *stack_b;
	if ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	b_first_node->next = *stack_a;
	*stack_a = b_first_node;
}

void	rotate_a(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	if ((*stack)->next != NULL)
		second_node = (*stack)->next;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	first_node->next = NULL;
	(*stack)->next = first_node;
	*stack = second_node;
}

void	rotate_b(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	if ((*stack)->next != NULL)
		second_node = (*stack)->next;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	first_node->next = NULL;
	(*stack)->next = first_node;
	*stack = second_node;
}

void	reverse_rotate_a(t_list **stack)
{
	t_list	*first_node;
	t_list	*next_last_node;
	t_list	*last_node;

	first_node = *stack;
	last_node = *stack;
	while (last_node->next != NULL)
	{
		next_last_node = last_node;
		last_node = last_node->next;
	}
	next_last_node->next = NULL;
	last_node->next = first_node;
	*stack = last_node;
}

void	reverse_rotate_b(t_list **stack)
{
	t_list	*first_node;
	t_list	*next_last_node;
	t_list	*last_node;

	first_node = *stack;
	last_node = *stack;
	while (last_node->next != NULL)
	{
		next_last_node = last_node;
		last_node = last_node->next;
	}
	next_last_node->next = NULL;
	last_node->next = first_node;
	*stack = last_node;
}
