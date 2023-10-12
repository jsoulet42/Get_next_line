/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:01:33 by jsoulet           #+#    #+#             */
/*   Updated: 2023/10/12 17:29:48 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_lst	*stack[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	read_stack(fd, &stack[fd]);
	if (!stack[fd])
		return (NULL);
	extract_line(stack[fd], &line);
	clean_stack(&stack[fd]);
	if (line[0] == '\0')
	{
		free_stack(stack[fd]);
		stack[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_stack(int fd, t_lst **stack)
{
	char	*buffer;
	int		r_read;

	r_read = 1;
	while (!chearch_endline(*stack) && r_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		r_read = read(fd, buffer, BUFFER_SIZE);
		if ((!*stack && r_read == 0) || r_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[r_read] = '\0';
		go_to_stack(stack, buffer, r_read);
		free(buffer);
	}
}

void	go_to_stack(t_lst **stack, char *buffer, int r_read)
{
	t_lst	*end;
	t_lst	*new_temp;
	int		i;

	new_temp = malloc(sizeof(t_lst));
	if (!new_temp)
		return ;
	new_temp->next = NULL;
	new_temp->content = malloc(sizeof(char) * (r_read + 1));
	if (!new_temp->content)
		return ;
	i = 0;
	while (buffer[i] && i < r_read)
	{
		new_temp->content[i] = buffer[i];
		i++;
	}
	new_temp->content[i] = '\0';
	if (!*stack)
	{
		*stack = new_temp;
		return ;
	}
	end = lst_getlast(*stack);
	end->next = new_temp;
}

void	extract_line(t_lst *stack, char **line)
{
	int	i;
	int	j;

	if (!stack)
		return ;
	generate_line(stack, line);
	if (!*line)
		return ;
	j = 0;
	while (stack)
	{
		i = 0;
		while (stack->content[i])
		{
			if (stack->content[i] == '\n')
			{
				(*line)[j++] = stack->content[i];
				break ;
			}
			(*line)[j++] = stack->content[i++];
		}
		stack = stack->next;
	}
	(*line)[j] = '\0';
}

void	clean_stack(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*last;
	int		i;
	int		j;

	temp = malloc(sizeof(t_lst));
	if (!stack || !temp)
		return ;
	temp->next = NULL;
	last = lst_getlast(*stack);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	temp->content = malloc(sizeof(char) * (ft_strlen(last->content + i) + 1));
	if (!temp->content)
		return ;
	j = 0;
	while (last->content[i])
		temp->content[j++] = last->content[i++];
	temp->content[j] = '\0';
	free_stack(*stack);
	*stack = temp;
}
