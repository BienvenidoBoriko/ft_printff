# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 16:57:26 by bboriko-          #+#    #+#              #
#    Updated: 2021/04/18 12:39:12 by bboriko-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT = ./src/libft/libft.a

SRCS			=	ft_printf.c

HEADER			= -I ./include
OBJS			= $(SRCS:.c=.o)
OBJS_LIBFT		= ./src/libft/*.o

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft_printf.a
$(NAME):	$(OBJS)
			@echo "\ncompilando libft"
			@make -C ./src/libft bonus
			@cp $(LIBFT) ./$(NAME)
			@echo "acabada la compilacion de libft\n"
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS) $(OBJS_LIBFT)

fclean:			clean
				$(RM) $(NAME) $(LIBFT)
nm:
	norminette
ej:
	gcc $(CFLAGS) libft_printf.a ft_main_printf.c

re:				fclean $(OBJS)
			@echo "\ncompilando libft"
			@make -C ./src/libft re
			@cp $(LIBFT) ./$(NAME)
			@echo "acabada la compilacion de libft\n"
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus nm ej