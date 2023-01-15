/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_encoder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:13:59 by marcrodr          #+#    #+#             */
/*   Updated: 2023/01/15 12:36:16 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <compress.h>

int	main(int argc, char **argv)
{
	t_list			list;
	t_node			*tree;
	unsigned char	*text;
	unsigned int	freq_table[SIZE];
	int				columns;
	char			**dict;
	unsigned char	*encoded;
	
	text = check_flags(argc, argv);
	if (text == NULL)
		return (0);
	init_table(freq_table);
	check_frequency(text, freq_table);
	share_freq_table(freq_table);
	share_text(text);
	init_list(&list);
	insert_list(freq_table, &list);
	tree = create_tree(&list);
	columns = tree_height(tree) + 1;
	dict = init_dictionary(columns);
	creat_dict(dict, tree, "", columns);
	encoded = encoder(dict, text);	
	decoder(encoded, dict);
	compact(encoded);
	return (0);	
}
