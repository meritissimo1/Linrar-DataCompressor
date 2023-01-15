#ifndef COMPRESS_H
# define COMPRESS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>

# define SIZE 256
# define BLOCK_SIZE 4096
# define IPC_RESULT_ERROR (-1)
# define FILENAME "fabin.42"

typedef struct s_node
{
	unsigned char	c;
	int				freq;
	struct s_node	*right;
	struct s_node	*left;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	t_node	*head;
	int		size;
}			t_list;

void	exit_program(unsigned char *text, unsigned char *encoded, char **dict);
void	check_frequency(unsigned char *text, unsigned int freq_table[]);
void	creat_dict(char **dict, t_node *root, char *bits, int columns);
void	write_file(unsigned char *encode, int i, int j, FILE *file);
void	descompact(t_node *tree, unsigned char *str, int j);
void	insert_list(unsigned int table[], t_list *list);
void	read_file(unsigned char *text, char *archive);
void	share_freq_table(unsigned int freq_table[]);
void	insert_sorted(t_list *list, t_node *node);
void	init_table(unsigned int freq_table[]);
void	share_text(unsigned char *str);
void	compact(unsigned char *encode);
void	free_linkedlist(t_node *node);
void	init_list(t_list *list);
void	ft_atob(char *cod);

t_node	*remove_node(t_list *list);
t_node	*create_tree(t_list *list);

int	length_string(char **dict, unsigned char *cod);
int	tree_height(t_node *root);
int	size_file(char *archive);

unsigned int	*attach_memory_block(char *filename, int size);

unsigned char	*attach_memory_text(char *filename, int size);
unsigned char	*encoder(char **dict, unsigned char *text);
unsigned char	*decoder(unsigned char *str, char**dict);
unsigned char	*check_flags(int argc, char **str);


char	**init_dictionary(int columns);

bool	detach_mem_block(unsigned int *block);
bool	destroy_mem_block(char *filename);

#endif