# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:04:39 by marcrodr          #+#    #+#              #
#    Updated: 2023/01/15 12:33:54 by marcrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
ENCODER		= encoder
DECODER		= decoder

## Main Header
INCS		= compress.h
INCS_DIR	= includes

## Includes
INC_FLAGS	= -I $(INCS_DIR)

## Source
SRCS_DIR	= ./src
MAIN_ENCO	= main_encoder.c

INSERT_DIR	= insert
INSERT_SRC	= insert_sorted.c

INIT_DIR	= initialize
INIT_SRC	= init.c init_dict.c

UTILS_DIR	= utils
UTILS_SRC	= remove.c check_freq.c tree_height.c length_string.c size_file.c read_file.c check_flags.c share_freq_table.c share_text.c

TREE_DIR	= tree
TREE_SRC	= tree.c

DICT_DIR	= dictionary
DICT_SRC	= dictionary.c

ENCODER_DIR	= encoder
ENCODER_SRC	= encoder.c

DECODER_DIR	= decoder
DECODER_SRC	= decoder.c

MEM_DIR		= memory_share
MEM_SRC		= mem_shared.c

EXIT_DIR	= exit
EXIT_SRC	= free_linkedlist.c exit_program.c

SRCS_ENCO	=	$(MAIN_ENCO) \
				$(addprefix $(INIT_DIR)/, $(INIT_SRC)) \
				$(addprefix $(INSERT_DIR)/, $(INSERT_SRC)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRC)) \
				$(addprefix $(TREE_DIR)/, $(TREE_SRC)) \
				$(addprefix $(DICT_DIR)/, $(DICT_SRC)) \
				$(addprefix $(ENCODER_DIR)/, $(ENCODER_SRC)) \
				$(addprefix $(DECODER_DIR)/, $(DECODER_SRC)) \
				$(addprefix $(EXIT_DIR)/, $(EXIT_SRC)) \
				$(addprefix $(MEM_DIR)/, $(MEM_SRC))

MAIN_DECO	= main_decoder.c



SRCS_DECO	= 	$(MAIN_DECO) \
			  	$(addprefix $(MEM_DIR)/, $(MEM_SRC)) \
				$(addprefix $(INSERT_DIR)/, $(INSERT_SRC)) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRC)) \
				$(addprefix $(INIT_DIR)/, $(INIT_SRC)) \
				$(addprefix $(DICT_DIR)/, $(DICT_SRC)) \
				$(addprefix $(DECODER_DIR)/, $(DECODER_SRC)) \
				$(addprefix $(ENCODER_DIR)/, $(ENCODER_SRC)) \
				$(addprefix $(EXIT_DIR)/, $(EXIT_SRC)) \
				$(addprefix $(TREE_DIR)/, $(TREE_SRC))

SRCS_PATH	= $(addprefix $(SRCS_DIR)/, $(SRCS_ENCO))

OBJS_DIR	= ./objs
OBJS_ENCO	= $(addprefix $(OBJS_DIR)/, $(SRCS_ENCO:.c=.o))
OBJS_DECO	= $(addprefix $(OBJS_DIR)/, $(SRCS_DECO:.c=.o))
DIR_OBJS	= mkdir -p $(@D)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(DIR_OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

all: $(ENCODER) $(DECODER)

$(ENCODER): $(OBJS_ENCO)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS_ENCO) -o $@

$(DECODER): $(OBJS_DECO)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS_DECO) -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(ENCODER) $(DECODER) 42zip.mm

re: fclean all

debug:
	$(CC) -g $(CFLAGS) $(INC_FLAGS) $(SRCS_PATH) -o $@
	gdb --args ./debug mewmew.42
	rm debug

.PHONY: re fclean clean all
	
