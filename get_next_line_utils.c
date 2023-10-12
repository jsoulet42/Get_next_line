/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:30:09 by jsoulet           #+#    #+#             */
/*   Updated: 2023/10/12 17:32:42 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*lst_getlast(t_lst *stack)
{
	t_lst	*new_temp;

	new_temp = stack;
	while (new_temp && new_temp->next)
		new_temp = new_temp->next;
	return (new_temp);
}

int	chearch_endline(t_lst *stack)
{
	int		i;
	t_lst	*new_temp;

	if (!stack)
		return (0);
	new_temp = lst_getlast(stack);
	i = 0;
	while (new_temp->content[i])
	{
		if (new_temp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	generate_line(t_lst *stack, char **line)
{
	int	len;
	int	i;

	len = 0;
	while (stack)
	{
		i = 0;
		while (stack->content[i])
		{
			if (stack->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stack = stack->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	free_stack(t_lst *stack)
{
	t_lst	*new_temp;
	t_lst	*next;

	new_temp = stack;
	while (new_temp)
	{
		free(new_temp->content);
		next = new_temp->next;
		free(new_temp);
		new_temp = next;
	}
}
