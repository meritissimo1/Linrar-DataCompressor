/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_decoder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:03:50 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:36:22 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

int main(void)
{
	unsigned int	*freq_table;
	t_list			list;
	int				columns;
	char			**dict;
	t_node			*tree;
	unsigned char	*enco;
	unsigned char	*deco;
	unsigned char	*text;

	freq_table = attach_memory_block(FILENAME, BLOCK_SIZE);
	if (freq_table == NULL)
	{
		printf("ERROR: couldn't get block");
		return (-1);
	}
	init_list(&list);
	insert_list(freq_table, &list);
	tree = create_tree(&list);
	columns = tree_height(tree) + 1;
	dict = init_dictionary(columns);
	creat_dict(dict, tree, "", columns);
	text = attach_memory_text(FILENAME, BLOCK_SIZE);	
	enco = encoder(dict, text);
	deco = decoder(enco, dict);
	compact(enco);
	descompact(tree, deco, 0);
	printf("\n");
	detach_mem_block(freq_table);
	free(enco);
	return (0); 
}