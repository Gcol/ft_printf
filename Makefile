# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 13:56:15 by gcollett          #+#    #+#              #
#    Updated: 2017/07/10 02:53:02 by gcollett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ft_printf.c \
			conversion.c \
			flag.c

SRCDIR = ./srcs/

OBJ = $(SRC:.c=.o)

LIBSRC = 	ft_atoi.c 							\
			ft_strcmp.c							\
			ft_strncpy.c						\
			ft_memalloc.c 						\
			ft_memset.c							\
 			ft_stradd.c							\
 			ft_stradd_in.c						\
 			ft_strchr.c							\
 			ft_strlen.c							\
 			ft_strlendup.c						\
 			ft_ulltoa_base.c					\
			ft_atoi_base.c						\
			ft_strdup.c							\
			ft_strnew.c							\
			ft_c_in_str.c						\
			ft_free_factory.c					\

LIBOBJ = $(LIBSRC:.c=.o)

LDFLAGS = -I./include/

CFLAGS = -Wall -Werror -Wextra

LIBDIR = ./libft/
OBJDIR	= ./objs/
SRCDIR	= ./srcs/

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

LIBS = libft/libft.a

RM = rm -f

all : $(NAME)

$(NAME) :
	@make -C libft/ re
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation in progress..."
	@gcc $(GCC_FLAGS) -Ilibft/ -Iincludes/ -c $(SRCS)
	@ar rc $(NAME) $(OBJ) $(addprefix $(LIBDIR), $(LIBOBJ))
	@ranlib $(NAME)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)
	@ranlib $(NAME)
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation completed sucessfully !"

clean :
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the library \033[1;34m$(NAME)\033[0m"
	@rm -rf objs
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the library \033[1;34m$(NAME)\033[0m completed successfully !"
	@make -C libft/ clean

fclean : clean
	@$(RM) $(NAME)
	@echo "\t\033[1;31m'FCLEAN' ->\tDestruction\033[0m of library \033[1;34m$(NAME)\033[0m completed successfully !"
	@make -C libft/ fclean

re : fclean all

compile :
	@gcc $(CFLAGS) $(addprefix $(SRCDIR), $(SRC)) main.c libft/libft.a -g

cc:
	@gcc -o test $(addprefix $(SRCDIR), $(SRC)) main.c libft/libft.a -g

compexec : compile
	@./a.out

cexec : cc
	@./a.out
