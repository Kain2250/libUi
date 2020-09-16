# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 20:22:23 by bdrinkin          #+#    #+#              #
#    Updated: 2020/09/16 22:28:22 by bdrinkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libui.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -c

# Список фреймворков и их пути:
FRAME_SDL2_DIR = Frameworks
FRAME_SDL2 = $(FRAME_SDL2_DIR)/SDL2.framework
FRAME_SDL2_IMAGE = $(FRAME_SDL2_DIR)/SDL2_image.framework
FRAME_SDL2_MIXER = $(FRAME_SDL2_DIR)/SDL2_mixer.framework
FRAME_SDL2_TTF = $(FRAME_SDL2_DIR)/SDL2_ttf.framework
FRAME_SDL2_NET = $(FRAME_SDL2_DIR)/SDL2_net.framework
FRAMEWORKS = -F Frameworks \
	-framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_mixer \
	-framework SDL2_ttf \
	-framework SDL2_net \
	-rpath $(FRAME_SDL2_DIR)

INCLUDE = -I$(HEADERS_DIRECTORY)
HEADERS_LIST = libui.h
HEADERS_DIRECTORY = $(CURDIR)/include/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
INCLUDES_SDL2 = -F $(FRAME_SDL2_DIR) \
	-I $(FRAME_SDL2)/Headers \
	-I $(FRAME_SDL2_IMAGE)/Headers \
	-I $(FRAME_SDL2_MIXER)/Headers \
	-I $(FRAME_SDL2_TTF)/Headers \
	-I $(FRAME_SDL2_NET)/Headers

SOURCES_DIRECTORY = $(CURDIR)/src/
SOURCES_LIST = ft_functions.c \
			acces_pixel.c \
			blit_surf_scale.c \
			blit_surface.c \
			draw_circl.c \
			draw_color_point.c \
			draw_line.c \
			draw_rect.c \
			draw_smoothed_fill_rect.c \
			draw_smoothed_rect.c \
			fill_functions.c \
			struct_timer.c \
			timer.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)Созданы объектные файлы$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) Был создан$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) Был создан$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES_SDL2) $(INCLUDE) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)Объектные файлы были удалены$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) Был удален$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
