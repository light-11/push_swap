/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayanaga <ayanaga@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:44:13 by ayanaga           #+#    #+#             */
/*   Updated: 2026/06/30 21:44:19 by ayanaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	compute_disorder(t_list **stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*now_node;
	t_list	*next_node;

	mistakes = 0;
	total_pairs = 0;
	now_node = *stack_a;
	next_node = (*stack_a)->next;
	while (now_node->next != NULL)
	{
		while (next_node->next != NULL)
		{
			if ((now_node->content) > (next_node->content))
				mistakes++;
			total_pairs++;
			next_node = next_node->next;
		}
		now_node = now_node->next;
		next_node = now_node->next;
	}
	return (mistakes / total_pairs);
}

int	check_duplication(t_list **stack_a, int value)
{
	t_list	*check_node;

	check_node = *stack_a;
	if (check_node == NULL)
		return (1);
	while (check_node->next != NULL)
	{
		if (check_node->content == value)
			return (0);
		check_node = check_node->next;
	}
	if (check_node->content == value)
		return (0);
	return (1);
}

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

void	check_adaptive(float disorder, t_list **stack_a, t_list **stack_b)
{
	if (disorder < 0.2)
		simple(&stack_a, &stack_b);
	if (0.2 <= disorder && disorder < 0.5)
		medium(&stack_a, &stack_b);
	if (0.5 <= disorder)
		complex(&stack_a, &stack_b);
}
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	push_swap(int argc, char *argv[])
{
	int		i;
	int		count;
	t_list	*stack_a;
	t_list	*stack_b;
	char	*flg;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
		}
		else
		{
			if (stack_a == NULL)
				stack_a = ft_lstnew(ft_atoi(argv[i]));
			else
			{
				if (!check_duplication(&stack_a, ft_atoi(argv[i])))
				{
					write(2, "Error\n", 6);
					return (0);
				}
				ft_lstadd_back(&stack_a, ft_atoi(argv[i]));
			}
			i++;
		}
	}
	if (stack_a == NULL || stack_a->next == NULL)
		return (0);
	if (compute_disorder(&stack_a) == 0)
		return (0);
	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench"))
			bench();
		if (ft_strncmp(argv[i], "--simple"))
			simple(&stack_a, &stack_b);
		else if (ft_strncmp(argv[i], "--medium"))
			medium(&stack_a, &stack_b);
		else if (ft_strncmp(argv[i], "--complex"))
			complex(&stack_a, &stack_b);
		else if (ft_strncmp(argv[i], "--adaptive"))
			check_adaptive(compute_disorder(agc, argv), &stack_a, &stack_b);
		else
			count++;
		i++;
	}
	if (count == argc - 1)
		check_adaptive(compute_disorder(agc, argv), &stack_a, &stack_b);
}

int	small_search(t_list **stack)
{
	t_list	*first_node;
	int		small_content;
	int		count;
	int		small_content_count;

	count = 0;
	first_node = *stack;
	small_content = (*stack)->content;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		count++;
		if ((*stack)->content < small_content)
		{
			small_content = (*stack)->content;
			small_content_count = count;
		}
	}
	*stack = first_node;
	return (small_content_count);
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
	int	small_content_count;
	int	node_count;
	int	i;

	i = 0;
	node_count = count_node(stack_a);
	while (count_node(stack_a) > 0)
	{
		small_content_count = small_search(stack_a);
		while (i < small_content_count)
		{
			if (small_content_count >= node_count / 2)
				reverse_rotate_a(stack_a);
			else
				rotate_a(stack_a);
			i++;
		}
		i = 0;
		push_a(stack_a, stack_b);
	}
	while (node_count > 0)
	{
		push_b(stack_a, stack_b);
		node_count--;
	}
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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_first_node;

	a_first_node = *stack_a;
	if ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	a_first_node->next = *stack_b;
	*stack_b = a_first_node;
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*b_first_node;

	b_first_node = *stack_b;
	if ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	b_first_node->next = *stack_a;
	*stack_a = b_first_node;
	write(1, "pb\n", 3);
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}
