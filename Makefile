# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 18:40:37 by fmasha-h          #+#    #+#              #
#    Updated: 2019/09/04 19:19:16 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g

DIR_O = obj

INCLUDES =  push_swap.h -I libft/libft.h

LIBFT = libft/libft.a

SRCS =	main.c \
		validation.c \
		create_stack.c \
		push_swap.c \
		print_stack.c \
		quick_sort.c \
		change_stack_fun.c \
		change_a_stack.c \
		change_b_stack.c \
		change_both_stacks.c \
		find_min_max.c \
		set_to_zero_stack.c \
		is_sort_checkers.c \
		search_values.c \
		count_moves.c \
		del_stack.c \
		unit_moves.c \
		kick_values.c \
		do_moves.c \

OBJF = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SRCS)))

all: $(NAME)

$(DIR_O):
	@mkdir -p obj

$(NAME): $(DIR_O) $(OBJF)
	@make -C libft
	gcc $(FLAGS) $(OBJF) $(LIBFT) -o $(NAME)

$(DIR_O)/%.o: ./%.c 
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all