/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 03:43:06 by aozkaya           #+#    #+#             */
/*   Updated: 2026/05/07 05:03:14 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	gc_remove(t_gc *gc, void *ptr)
{
	t_gc_node	*current;
	t_gc_node	*prev;

	if (!gc || !ptr || !gc->head)
		return ;
	prev = NULL;
	current = gc->head;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				gc->head = current->next;
			free(current);
			gc->count--;
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	gc_free_all(t_gc *gc)
{
	t_gc_node	*current;
	t_gc_node	*next;

	if (!gc)
		return ;
	current = gc->head;
	while (current)
	{
		next = current->next;
		if (current->ptr)
			free(current->ptr);
		free(current);
		current = next;
	}
	gc->head = NULL;
	gc->count = 0;
}
