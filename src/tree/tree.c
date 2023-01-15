/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:31:25 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:27:19 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

t_node	*create_tree(t_list *list)
{
	t_node	*first;
	t_node	*second;
	t_node	*new;

	while (list->size > 1)
	{
		first = remove_node(list);
		second = remove_node(list);
		new = malloc(sizeof(t_node));
		if (new)
		{
			new->c = '*';
			new->freq = first->freq + second->freq;
			new->left = first;
			new->right = second;
			new->next = NULL;
			insert_sorted(list, new);
		}
		else
			return (NULL);
	}
	return (list->head);
}
