/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:40:38 by ael-khat          #+#    #+#             */
/*   Updated: 2022/03/04 19:13:02 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_list *list)
{
	if (!list)
	{
		write(2, "Error malloc\n", 14);
		exit(0);
	}
}

void	create_nodes(t_list *head_a, int n, t_list *current_a, char *argv[])
{
	int	i;

	i = 3;
	while (i <= n)
	{
		current_a = ft_lstnew((int)ft_atol(argv[i]));
		ft_exit(current_a);
		ft_lstadd_back(&head_a, current_a);
		i++;
	}
}

t_list	*create_a(int argc, char *argv[])
{
	int		n;
	t_list	*head_a;
	t_list	*current_a;

	n = argc - 1;
	if (n == 0)
		return (NULL);
	else
	{
		head_a = ft_lstnew((int)ft_atol(argv[1]));
		ft_exit(head_a);
		current_a = ft_lstnew((int)ft_atol(argv[2]));
		ft_exit(current_a);
		head_a -> next = current_a;
		current_a -> previous = head_a;
		create_nodes(head_a, n, current_a, argv);
	}
	return (head_a);
}

void	algos(t_list *head_a, t_list *head_b, int argc)
{
	if (argc == 3)
		sorting_two(&head_a);
	else if (argc == 4)
		sorting_three(&head_a);
	else if (argc == 5)
		sorting_four(&head_a, &head_b);
	else if (argc == 6)
		sorting_five(&head_a, &head_b);
	else
		sorting_above_five(&head_a, &head_b);
	ft_lstclear(&head_a);
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	if (argc >= 2)
	{
		if (check_dup(argv, (argc - 1)) == 0 || check_char(argv) == 0
			|| check_sp(argv) == 0 || check_dsi(argv) == 0)
		{
			write (2, "Error\n", 7);
			return (0);
		}
		else
		{
			if (argc == 2)
			{
				ft_atol(argv[1]);
				return (0);
			}
			head_a = create_a(argc, argv);
			head_b = NULL;
			algos(head_a, head_b, argc);
		}
	}
	return (0);
}
