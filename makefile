NAME				=	miniRT
OS 					:=	$(shell uname)

SRC_DIR 			= 	src/
BONUS_DIR 			= 	src_bonus/
LIBFT_DIR			=	dependencies/libft/
PRINTF_DIR			=	dependencies/printf/
GNL_DIR				=	dependencies/get_next_line/
OBJ_DIR				=	obj/

PRINTF_INCL			=	dependencies/printf/includes

LIBFT_A_DIR			=	dependencies/libft/libft.a
PRINTF_A_DIR		=	dependencies/printf/libftprintf.a

CC					=	gcc
CFLAGS				= 	-Werror -Wall -Wextra -g 
OPENGL				= 	-lz -framework OpenGL -framework AppKit
INCLUDES			=	-Iincludes/ -Iincludes/bonus -I$(PRINTF_INCL) \
						-I$(GNL_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) 
ifeq ($(OS), Linux)
	MINILIBX_DIR = dependencies/minilibx_linux
	OPENGL = -lm -lbsd -lX11 -lXext
endif
ifeq ($(OS), Darwin)
	MINILIBX_DIR = dependencies/minilibx_opengl
	OPENGL = -lz -framework OpenGL -framework AppKit
endif

MINILIBX_A_DIR 		=	$(MINILIBX_DIR)/libmlx.a

SRC_FILES			=	algebra/algebra_1.c \
					algebra/algebra_2.c \
					algebra/algebra_3.c \
					geometry/cylinder.c \
					geometry/cylinder_caps.c \
					geometry/plane.c \
					geometry/sphere.c \
					geometry/square.c \
					geometry/triangle.c \
					load/load.c \
					load/load_utils.c \
					load/load_utils_3.c \
					hooks/minirt.c \
					hooks/minirt_utils.c \
					shadows/cylinder_shadows.c \
					shadows/plane_shadows.c \
					shadows/shadows.c \
					shadows/sphere_shadows.c \
					shadows/square_shadows.c \
					shadows/triangle_shadows.c \
					main/main.c \
					color.c \
					color_utils.c \
					pipeline.c \
					load/load_1.c \
					load/load_2.c \
					load/load_utils_2.c \
					camera.c \
					clean_memory.c\
					clean_memory_2.c\
 					light.c \
					error.c \
					axis.c \
					bmp.c

GNL_FILES			=	get_next_line.c \
						get_next_line_utils.c	

OBJ_FILES			=	$(SRC_FILES:.c=.o)
OBJ 				= 	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
GNL					= 	$(addprefix $(GNL_DIR), $(GNL_FILES))

all		:	dependencies $(OBJ_DIR) $(NAME)


$(OBJ_DIR)	:
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)algebra
		@mkdir -p $(OBJ_DIR)geometry
		@mkdir -p $(OBJ_DIR)hooks
		@mkdir -p $(OBJ_DIR)load
		@mkdir -p $(OBJ_DIR)main
		@mkdir -p $(OBJ_DIR)shadows
		@echo Created printf Object directory 📌

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	    $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< 

$(NAME)	:	$(OBJ)	 
	@echo Building miniRT...
	@$(CC) $(CFLAGS) $(OBJ) $(GNL) $(INCLUDES)\
	$(PRINTF_A_DIR) $(LIBFT_A_DIR) $(MINILIBX_A_DIR) $(OPENGL) \
	-o $(NAME)
	@echo success ✅

dependencies	:	
	@echo Building libft
	@make -C $(LIBFT_DIR)	
	@echo Building printf
	@make -C $(PRINTF_DIR)
	@make -C $(MINILIBX_DIR)

clean	:
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME_BONUS)
	@rm -rf $(NAME_BONUS).dSYM
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@rm -rf *.o
	@echo cleaning miniRT...

fclean	: 	clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make clean -C $(MINILIBX_DIR)

re		:	fclean all

.PHONY: clean fclean all re bonus dependencies
