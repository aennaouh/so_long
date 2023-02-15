# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 20:37:13 by aennaouh          #+#    #+#              #
#    Updated: 2023/02/14 22:45:07 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = so_long
Nameb = so_long_b
CC  = cc
CFLAGS = -Wall -Wextra -Werror -g
mlx = -lmlx -framework OpenGL -framework AppKit
HEADER = mandatory/so_long.h
HEADER_bo = bonus/so_long.h

SRC = mandatory/movepla.c mandatory/so_long_utilis.c mandatory/maps.c mandatory/so_long.c mandatory/back.c  mandatory/so_long_utilis2.c mandatory/move.c mandatory/get_next_line/get_next_line.c \
	mandatory/get_next_line/get_next_line_utils.c\

SRC1 = bonus/movepla.c  bonus/enemy_mov.c bonus/so_long_utilis.c bonus/maps.c bonus/so_long_b.c bonus/back.c  bonus/ft_mov_en.c bonus/so_long_utilis2.c bonus/move.c bonus/get_next_line/get_next_line.c \
	bonus/get_next_line/get_next_line_utils.c\

OBJS = ${SRC:.c=.o}

OBJS1= ${SRC1:.c=.o}
 
all : $(Name)

$(Name): ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${mlx}  -o ${Name}


%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@



bonus :$(Nameb)

$(Nameb): ${OBJS1}
	${CC} ${CFLAGS} ${OBJS1} ${mlx} -o ${Nameb}

%.o: %.c ${HEADER_bo}
	${CC} ${CFLAGS} -c $<  -o $@

clean:
	rm -f ${Name} ${Nameb}
	
fclean: clean
	rm -f ${OBJS} ${OBJS1}

re : fclean all 

re_bonus : fclean bonus 
