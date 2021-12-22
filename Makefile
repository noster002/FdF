CC		= gcc
CFLAGS	= -Wall -Werror -Wextra $(GNLBUF) $(MLXOBJ)
GNLBUF	= -D BUFFER_SIZE=10
MLXOBJ	= -I/usr/include -Imlx_linux -O3
MAKELIB	= make -C libft/
MLXEXE	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
LFLAGS	= -L./libft/ -lft
RM		= rm -f
NAME	= fdf
HEAD	= main.h
OBJ		= \
main.o src_c/colors_create.o src_c/colors_change.o \
get_next_line/get_next_line.o get_next_line/get_next_line_utils.o \
src_c/event_keypress.o src_c/render.o src_c/render_line.o src_c/render_frame.o \
src_c/frame.o src_c/points.o src_c/fdf_file.o src_c/free.o \
src_c/read_file.o src_c/split_lines.o src_c/arrlen.o

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKELIB)
	$(CC) $(OBJ) $(LFLAGS) $(MLXEXE) -o $(NAME)

%.o:		%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKELIB) fclean
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re