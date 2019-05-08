# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thansen <thansen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 17:37:04 by thansen           #+#    #+#              #
#    Updated: 2019/05/08 17:37:04 by thansen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC		=	ft_printf.c \
			token_processing.c \
			print_char.c \
			print_string.c \
			print_pointer.c \
			print_decimal.c \
			print_number.c \
			print_octal.c \
			print_hex.c \
			print_bhex.c \
			print_unsigned.c \
			print_double.c \
			str_adding.c \
			bin_transform.c \
			dbl_to_str.c \
			ldbl_to_str.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/inc

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIBFT_DIR)/obj/*.o
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_H) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

norm:
	@make -C libft norm
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm