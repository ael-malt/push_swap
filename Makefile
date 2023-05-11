NAME		= push_swap

### SRC

PATH_SRC	= src/

PUSH_SWAP	= cost.c do_move.c input_check.c position.c push_swap.c push.c \
				reverse_rotate.c rotate.c sort.c stack.c swap.c tiny_sort.c \
				utils.c

SRC += $(PUSH_SWAP)

vpath %.c $(PATH_SRC)

### HEADER

INCLUDE	= -Iinclude/

HEADER		+= push_swap.h

vpath %.h $(PATH_HEADER)

### OBJS

PATH_OBJS	= objs/
OBJS		= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRC))

### COMPILATION

CC			= clang
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -I.

AR = ar rcs

all: 		$(NAME)

$(NAME):	$(OBJS)
			${MAKE} -C ./libft
			$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o ${NAME}

$(OBJS):	$(PATH_OBJS)/%.o: %.c
			mkdir -p $(PATH_OBJS)
			$(CC) $(CFLAGS) -c -g $< -o $@ $(INCLUDE)

clean:
			${MAKE} -C ./libft fclean
			$(RM) -r $(PATH_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

%:
	@:

ARG			= $(filter-out $@,$(MAKECMDGOALS))

test:		$(NAME)
			$(eval ARG = $(shell shuf -i 0-5000 -n $(ARG)))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "Instructions: "
			@./push_swap $(ARG) | wc -l

.PHONY:		all clean fclean re te