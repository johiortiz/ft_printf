# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:39:38 by johyorti          #+#    #+#              #
#    Updated: 2025/01/20 15:07:33 by johyorti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= libftprintf.a
INCLUDE		= include
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar rcs
OBJ_DIR		= obj/

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

SRCS = ft_printf.c \
       ft_puthex.c \
       ft_put_utils.c

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

# ASCII Art
define ASCII_ART
   ▄███████▄    ▄████████  ▄█  ███▄▄▄▄       ███        ▄████████ 
  ███    ███   ███    ███ ███  ███▀▀▀██▄ ▀█████████▄   ███    ███ 
  ███    ███   ███    ███ ███▌ ███   ███    ▀███▀▀██   ███    █▀  
  ███    ███  ▄███▄▄▄▄██▀ ███▌ ███   ███     ███   ▀  ▄███▄▄▄     
▀█████████▀  ▀▀███▀▀▀▀▀   ███▌ ███   ███     ███     ▀▀███▀▀▀     
  ███        ▀███████████ ███  ███   ███     ███       ███        
  ███          ███    ███ ███  ███   ███     ███       ███        
 ▄████▀        ███    ███ █▀    ▀█   █▀     ▄████▀     ███        
               ███    ███                                         
endef
export ASCII_ART

# Targets

all: $(NAME)
	@echo "$$ASCII_ART"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
	@norminette $(SRCS) | grep -v Norme -B1 || true

.PHONY: all re clean fclean norm
