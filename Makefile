PUSH_SWAP = push_swap
CHECKER = checker

#sources and objects
COMMON_SRC =        push_algo.c \
					parsers.c \
					parse_check.c \
					algo_bubble.c \
					list_operate.c \
					init.c \
					print_lists.c \
					clean.c \
					sort_algo.c \
					sort_help.c \
					sort_help_2.c \
					find_algo.c \
					memory_algo.c \
					sort_less.c \
					sort_less_help.c \
					sort_less_1_4.c \
					sort_less_1_3.c \
					sort_less_min.c \
					sort_less_2_.c \
					sort_less_3_.c

PUSH_SWAP_SRC =     push_swap.c

CHECKER_SRC =       checker.c \
					checker_algo.c

PUSH_SWAP_SRC_PATH = = $(addprefix $(SRCDIR), $(PUSH_SWAP_SRC))
CHECKER_SRC_PATH = $(addprefix $(SRCDIR), $(CHECKER_SRC))
COMMON_SRC_PATH = $(addprefix $(SRCDIR), $(COMMON_SRC))

PUSH_SWAP_OBJ = $(addprefix $(OBJDIR), $(PUSH_SWAP_SRC:%.c=%.o))
CHECKER_OBJ = $(addprefix $(OBJDIR), $(CHECKER_SRC:%.c=%.o))
COMMON_OBJ = $(addprefix $(OBJDIR), $(COMMON_SRC:%.c=%.o))

#directories
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR  = ./obj/

#includes
INC = -I ./includes

#flags
FLAGS = -Wall -Wextra -Werror

#library
FT		= ./libftprintf/
FT_LIB	= $(addprefix $(FT),libftprintf.a)
FT_INC	= -I ./libftprintf/includes -I ./libftprintf/srcs/libft/includes/
FT_LNK	= ./libftprintf/libftprintf.a

all: obj $(FT_LIB) $(PUSH_SWAP) $(CHECKER)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(COMMON_OBJ)
	gcc $(PUSH_SWAP_OBJ) $(COMMON_OBJ) $(FT_LNK) -o $(PUSH_SWAP)

$(CHECKER): $(CHECKER_OBJ) $(COMMON_OBJ)
	gcc $(CHECKER_OBJ) $(COMMON_OBJ) $(FT_LNK) -o $(CHECKER)

$(FT_LIB):
	make -C $(FT)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re
