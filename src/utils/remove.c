/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:55 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:32 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

t_node	*remove_node(t_list *list)
{
	t_node	*aux;

	aux = NULL;
	if (list->head)
	{
		aux = list->head;
		list->head = aux->next;
		aux->next = NULL;
		list->size--;
	}
	return (aux);
}
