/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:36 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:27:49 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

void	insert_sorted(t_list *list, t_node *node)
{
	t_node	*aux;

	if (list->head == NULL)
		list->head = node;
	else if (node->freq < list->head->freq)
	{
		node->next = list->head;
		list->head = node;
	}
	else
	{
		aux = list->head;
		while (aux->next && aux->next->freq <= node->freq)
			aux = aux->next;
		node->next = aux->next;
		aux->next = node;
	}
	list->size++;
}

void	insert_list(unsigned int table[], t_list *list)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < SIZE)
	{
		if (table[i] > 0)
		{
			new = malloc(sizeof(t_node));
			if (new)
			{
				new->c = i;
				new->freq = table[i];
				new->right = NULL;
				new->left = NULL;
				new->next = NULL;
				insert_sorted(list, new);
			}
			else
				break;
		}
		i++;
	}
}
