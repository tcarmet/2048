#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/02 20:53:06 by tcarmet           #+#    #+#              #
#    Updated: 2015/03/19 15:03:29 by jgigault         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS	= -Wall -Wextra -Werror
NAME	= game_2048
LDFLAGS	= -I./include/

SRC		= \
			wkw.c \
			wkw_atoi.c \
			wkw_check_argv.c \
			wkw_check_gameplay.c \
			wkw_display_menu.c \
			wkw_display_numbers.c \
			wkw_display_panel.c \
			wkw_display_ui.c \
			wkw_env_init.c \
			wkw_env_reinit.c \
			wkw_env_reinit_changes.c \
			wkw_error.c \
			wkw_game_over.c \
			wkw_generate_random.c \
			wkw_generate_random_init.c \
			wkw_itoa.c \
			wkw_utils.c \
			wkw_moves.c \
			wkw_ncurses.c \
			wkw_putendl_fd.c \
			wkw_putchar.c \
			wkw_strlen.c \
			wkw_strjoin.c \
			wkw_wait.c \
			wkw_wait_time.c

OBJ		= $(SRC:.c=.o)
SRCDIR	= ./src/
OBJDIR	= ./
INCDIR	= ./include/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
INCS	= $(addprefix $(INCDIR), $(INC))


all: $(NAME)

$(NAME): $(INCS)
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -lncurses
	@echo "\\033[1;32mSuccess.\\033[0;39m"

.PHONY: clean fclean re

clean:
	@echo "\\033[1;34mDeleting objects...\\033[0;39m"
	@rm -f $(OBJS)

fclean: clean
	@echo "\\033[1;34mDeleting $(NAME)\\033[0;39m"
	@rm -f $(NAME)

re: fclean all
