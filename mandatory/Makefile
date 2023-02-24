# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 20:37:13 by aennaouh          #+#    #+#              #
#    Updated: 2023/02/23 17:17:56 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = movepla.c so_long_utilis.c maps.c so_long.c move_suite.c so_long_utilise3.c so_long_utilis2.c move.c back_track.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCB = ../bonus/movepla_bonus.c  ../bonus/enemy_mov_bonus.c ../bonus/move_suite_bonus.c ../bonus/so_long_utilis_bonus.c ../bonus/so_long_utilise3_bonus.c ../bonus/maps_bonus.c ../bonus/so_long_bonus.c ../bonus/back_track_bonus.c  ../bonus/ft_mov_en_bonus.c \
../bonus/so_long_utilis2_bonus.c ../bonus/move_bonus.c ../bonus/get_next_line/get_next_line.c ../bonus/get_next_line/get_next_line_utils.c \

MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

HEAD =  so_long.h

B_HEAD = ../bonus/so_long.h

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRCB:.c=.o}


%.o: %.c  $(HEAD) $(B_HEAd)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)  
	$(CC) $(FLAGS) $(OBJ)  $(MLX) -o $@

all : ${NAME}

bonus : ${OBJ_B} 
	$(CC) $(FLAGS) ${OBJ_B} $(MLX)  -o so_long_bonus
	


fclean : clean
	rm -rf ${NAME}
	rm -rf so_long so_long_bonus


clean : 
	rm -rf ${OBJ} ${OBJ_B}

re : fclean all