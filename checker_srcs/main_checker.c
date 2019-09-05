/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:25:38 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 18:18:43 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		execute_commands(t_stack *a, t_stack *b, t_commands *head)
{
	t_commands	*tmp;

	tmp = head;
	print_stack(a, b);
	while (tmp)
	{
		if (tmp->fun_for_a != NULL)
			tmp->fun_for_a(a);
		else if (tmp->fun_for_b != NULL)
			tmp->fun_for_b(b);
		else if (tmp->fun_for_two != NULL)
			tmp->fun_for_two(a, b);
		print_stack(a, b);
		tmp = tmp->next;
	}
}

t_commands	*read_input(void)
{
	char		*line;
	t_commands	*head;
	int			fun;

	line = NULL;
	head = (t_commands*)malloc(sizeof(t_commands));
	head->next = NULL;
	head->command = NULL;
	while ((get_next_line(0, &line)) > 0)
	{
		if ((fun = validate_commands(line)) == -1)
		{
			ft_printf("Error\n");
			delete_commands_list(head);
			free(head->command);
			free(head);
			free(line);
			return (NULL);
		}
		else
			head = add_command(head, line, fun);
		free(line);
	}
	return (head);
}

void	checker(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_commands	*head;

	head = NULL;
	a = create_argv_stack(argc, argv);
	if (is_it_sort(a) == 0 || (is_it_dup(a) == 1))
	{
		del_stack(a);
		return ;
	}
	b = create_second_stack(a);
	set_to_zero_stack(b);
	if ((head = read_input()) == NULL)
	{
		del_stack(a);
		del_stack(b);
		return ;
	}
	execute_commands(a, b, head);
	if (is_it_sort(a) == 0 && b->used_size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	delete_commands_list(head);
	free(head->command);
	free(head);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if ((validate_arg(argv[1])) == -1)
		{
			ft_printf("Error\n");
			exit(0);
		}
	}
	else if (argc > 2)
	{
		if ((validate_args(++argv)) == -1)
		{
			ft_printf("Error\n");
			exit(0);
		}
	}
	if (argc >= 2)
		checker(argc, argv);
}