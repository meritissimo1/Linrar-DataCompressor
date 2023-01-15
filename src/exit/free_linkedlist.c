/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linkedlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:15:11 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:51 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

void	free_linkedlist(t_node *node)
{
	t_node	*aux;
	t_node	*next;
	int		i;

	i = 0;
	aux = node;
	while (aux->next)
	{
		next = aux->next;
		free(aux);
		aux = next;
		i++;
	}
}
