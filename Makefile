# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 12:09:12 by tunsal            #+#    #+#              #
#    Updated: 2024/02/19 19:42:18 by tunsal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Printf/libft
FT_PRINTF_PATH	= ./lib/ft_printf/
FT_PRINTF_NAME	= libftprintf.a
FT_PRINTF		= $(FT_PRINTF_PATH)$(FT_PRINTF_NAME)

# Sources
SRCS_DIR		= src/
SRCS			= $(SRCS_DIR)fractol.c $(SRCS_DIR)example.c

COMPLEX_DIR		= $(SRCS_DIR)complex/
COMPLEX_SRCS	= $(COMPLEX_DIR)complex_mult.c $(COMPLEX_DIR)complex_add.c $(COMPLEX_DIR)complex_zero.c

FRACTALS_DIR	= $(SRCS_DIR)fractals/
FRACTALS_SRCS	= $(FRACTALS_DIR)mandelbrot.c $(FRACTALS_DIR)julia.c $(FRACTALS_DIR)frac_color.c $(FRACTALS_DIR)frac_draw.c $(FRACTALS_DIR)frac_init.c $(FRACTALS_DIR)zoom.c $(FRACTALS_DIR)move.c

UTILS_DIR		= $(SRCS_DIR)util/
UTILS_SRCS		= $(UTILS_DIR)exit_error.c $(UTILS_DIR)print_usage.c $(UTILS_DIR)parse_args.c $(UTILS_DIR)map.c $(UTILS_DIR)color.c $(UTILS_DIR)handler_mouse.c $(UTILS_DIR)handler_keyboard.c

ALL_SRCS		= $(SRCS) $(UTILS_SRCS) $(COMPLEX_SRCS) $(FRACTALS_SRCS)

# Compilation
OBJS			= lib/MLX42/build/libmlx42.a lib/ft_printf/libftprintf.a ${ALL_SRCS:.c=.o}
NAME			= fract-ol

CC				= gcc
CFLAGS			= -Wextra -Wall -Ofast #-Werror -Wunreachable-code # TODO: open me!
LIBS			= ./lib/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
INC				= -I ./lib/MLX42/include -I ./lib/ft_printf

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(LIBS) $(FT_PRINTF) $(INC) -o $(NAME)

lib/ft_printf/libftprintf.a:
				make -C ./lib/ft_printf all

lib/MLX42/build/libmlx42.a:
				cmake ./lib/MLX42 -B ./lib/MLX42/build && make -C ./lib/MLX42/build -j4

clean:
				rm -rf $(OBJS)
				rm -rf lib/MLX42/build

fclean: clean
				rm -rf $(NAME)

re: clean all