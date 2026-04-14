##
## EPITECH PROJECT, 2022
## Unix System Programming, my_top
## File description:
## Makefile
##

NAME	=		my_top

CFLAGS	= 		-W -Wall -Wextra -I./include

SRC		=		./src/main.c \
	./src/print.c \
	./src/parse.c \
	./src/parse_args.c \
	./src/help.c \
	./src/ncurses_utils.c \
	./src/data_getters.c \
	./src/mem_info.c \
	./src/task_info.c \
	./src/cpu_info.c \
	./src/loop.c \
	./my_printf/src/my_0.c \
	./my_printf/src/my_c.c \
	./my_printf/src/my_d.c \
	./my_printf/src/my_e.c \
	./my_printf/src/my_ee.c \
	./my_printf/src/my_f.c \
	./my_printf/src/my_g.c \
	./my_printf/src/my_o.c \
	./my_printf/src/my_p.c \
	./my_printf/src/my_plus.c \
	./my_printf/src/my_printf_core.c \
	./my_printf/src/my_put_decimal.c \
	./my_printf/src/my_s.c \
	./my_printf/src/my_space.c \
	./my_printf/src/my_u.c \
	./my_printf/src/my_w.c \
	./my_printf/src/my_x.c \
	./my_printf/src/my_xx.c \
	./other_functions/my_strcat.c \
	./other_functions/my_revstr.c \
	./other_functions/my_strlen.c \
	./other_functions/my_strdup.c \
	./other_functions/my_strcmp.c \
	./other_functions/my_put_nbr.c \
	./other_functions/my_isneg.c \
	./other_functions/my_isdigit.c \
	./other_functions/my_swap.c \
	./other_functions/my_evil_str.c \
	./other_functions/my_getnbr.c \
	./other_functions/my_sort_int_array.c \
	./other_functions/my_strcpy.c \
	./other_functions/my_strncpy.c \
	./other_functions/my_strstr.c \
	./other_functions/my_strncmp.c \
	./other_functions/my_strupcase.c \
	./other_functions/my_strlowcase.c \
	./other_functions/my_strcapitalize.c \
	./other_functions/my_str_isalpha.c \
	./other_functions/my_str_isnum.c \
	./other_functions/my_str_isfloat.c \
	./other_functions/my_str_islower.c \
	./other_functions/my_str_isupper.c \
	./other_functions/my_showstr.c \
	./other_functions/my_showmem.c \
	./other_functions/my_strncat.c \
	./other_functions/print_only_alpha.c \
	./other_functions/my_array_len.c \
	./other_functions/my_atoi.c \
	./other_functions/my_print_word_count.c \
	./other_functions/my_strchr.c \
	./other_functions/my_strrchr.c \
	./other_functions/my_str_contains_all.c \
	./other_functions/my_str_contains.c \
	./other_functions/my_str_count_char.c \
	./other_functions/my_str_count_word.c \
	./other_functions/my_str_isalnum.c \
	./other_functions/my_strjoin.c \
	./other_functions/my_str_replace.c \
	./other_functions/my_strtrim.c

OBJ		=		$(SRC:.c=.o)

all:	$(OBJ)
		clang $(OBJ) -o $(NAME) $(CFLAGS) -lncurses

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

debug:	CFLAGS+= -g
debug:	all

.PHONY:	all clean fclean re debug
