# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 10:25:51 by dacortes          #+#    #+#              #
#    Updated: 2024/06/03 17:20:52 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                               VARIABLES                                      #
################################################################################

LIBC = ar -rcs
RMV = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
TOTAL_FILES = $(words $(SOURCES))

DIRECTORIES_UTILS = obj
OBJECTS = $(addprefix $(DIRECTORIES_UTILS)/, $(SOURCES:.c=.o))
DEPENDENCIES = $(addprefix $(DIRECTORIES_UTILS)/, $(SOURCES:.c=.d))
BONUS_OBJECTS = $(addprefix $(DIRECTORIES_UTILS)/, $(BONUS:.c=.o))
BONUS_DEPENDENCIES = $(addprefix $(DIRECTORIES_UTILS)/, $(BONUS:.c=.d))

SOURCES =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_memchr.c\
				ft_strchr.c ft_memcmp.c ft_strrchr.c ft_strncmp.c ft_strnstr.c\
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_printf.c ft_type_cs.c ft_type_idupxX.c\
				get_next_line_bonus.c get_next_line_utils_bonus.c\
				get_next_line.c get_next_line_utils.c\
				ft_addend_char.c ft_addstart_char.c ft_strchrpos.c\
				ft_double_ptrlen.c ft_close_del.c\
				fd_type_cs.c fd_type_idup.c fd_type_xX.c fd_printf.c\
				ft_difcpy.c ft_cutdel.c ft_strcpy.c ft_strncpy.c\
				ft_strndup.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

################################################################################
#                               BOLD COLORS                                    #
################################################################################

END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m

################################################################################
#  FONT                                                                        #
################################################################################

ligth = \033[1m
dark = \033[2m
italic = \033[3m

################################################################################
#                               MAKE RULES                                     #
################################################################################

all: dir progress

$(NAME): $(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS)
	@echo "\n✅ ==== $(BLUE)$(ligth)Project $(NAME) compiled!$(E) ==== ✅"

$(DIRECTORIES_UTILS)/%.o: %.c
	@$(CC) -MMD $(CFLAGS) -c $< -o $@
	@$(call progress,$<)

bonus: dir $(BONUS_OBJECTS) $(NAME)
	if [ -f bonus ]; then\
		echo "\n$(BLUE)$(ligth)make:$(E)$(ligth) 'bonus' is up to date.$(E)";\
	else\
		$(LIBC) $(NAME) $(OBJ) $(BONUS_OBJECTS);\
		touch bonus;\
		echo "\n$(BLUE)$(ligth)⏳Compiling $(NAME):$(END)";\
	fi

dir:
	-mkdir -p $(DIRECTORIES_UTILS)
progress: $(OBJECTS) $(NAME)

################################################################################
#                               CLEAN                                          #
################################################################################

clean:
	$(RMV) $(OBJECTS) $(DIRECTORIES_UTILS) $(NAME)
	echo "✅ ==== $(PURPLE)$(ligth)Libft object files cleaned!$(E) ==== ✅"

fclean: clean
	$(RMV) $(NAME)
	echo "✅ ==== $(PURPLE)$(ligth)$(NAME) executable files and name cleaned!$(E) ==== ✅"

define progress
	@$(eval COMPILED_FILES=$(shell expr $(COMPILED_FILES) + 1))
	@bash -c 'PROG_BAR_WIDTH=50; \
	PROGRESS=$$(($(COMPILED_FILES) * $$PROG_BAR_WIDTH / $(TOTAL_FILES))); \
	EMPTY=$$(($$PROG_BAR_WIDTH - $$PROGRESS)); \
	PROGRESS=$$((PROGRESS < 0 ? 0 : PROGRESS)); \
	EMPTY=$$((EMPTY < 0 ? 0 : EMPTY)); \
	printf "\r$(ligth)[$(GREEN)"; \
	for ((i = 0; i < $$PROGRESS; i++)); do echo -n "█"; done; \
	for ((i = 0; i < $$EMPTY; i++)); do echo -n " "; done; \
	printf "$(END)$(ligth)] "; \
	printf "%d%%$(END)" $$((100 * $(COMPILED_FILES) / $(TOTAL_FILES)));'
endef

-include $(DEPENDENCIES)

re: fclean all
.PHONY: all clean progress fclean
COMPILED_FILES=0
.SILENT: