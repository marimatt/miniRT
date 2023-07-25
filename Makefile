# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 10:52:13 by marimatt          #+#    #+#              #
#    Updated: 2023/06/30 10:52:13 by marimatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	miniRT

SRCS	=	$(wildcard ./scene/*.c)\
			$(wildcard ./src/*.c)\
			$(wildcard ./geometry/*.c)\

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	#-Wall -Wextra -Werror

INCLUDES=	-Ilibft -I/usr/include -Imlx_linux -O3

LINKS	=	-L/usr/lib -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

LIBS	=	libft/libft.a	mlx_linux/libmlx_Linux.a


TEST_NAME		=	test
TEST_SRCS		=	./test.c\
					./src/errors.c ./src/memory.c \
					./src/parse_rt.c ./src/parse_scene.c ./src/parse_geometry.c \
					$(wildcard ./scene/*.c)\
					$(wildcard ./geometry/*.c)\
					# ./scene/*.c\
					# ./geometry/*.c\

TEST_OBJS		=	${TEST_SRCS:.c=.o}
TEST_INCLUDES 	=	-Ilibft
TEST_LINKS		=	-lm
TEST_LIBS		=	libft/libft.a


all:	${NAME}

$(NAME): $(OBJS)

	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LINKS) $(LIBS)
	@echo "-Compilation completed- Run ./"$(NAME) 

test:	${TEST_NAME}

$(TEST_NAME): $(TEST_OBJS)
	@make -C libft
	$(CC) $(TEST_OBJS) -o $(TEST_NAME) $(TEST_INCLUDES) $(TEST_LINKS) $(TEST_LIBS)
	@echo "-Compilation completed- Run ./"$(TEST_NAME) 

clean:
		rm -f $(OBJS) $(TEST_OBJS)
		# make clean -C libft

fclean:		clean
			rm -f $(NAME) $(TEST_NAME)
			# make fclean -C libft

re:		fclean all

.PHONY:		all clean fclean re
