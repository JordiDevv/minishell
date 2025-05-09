NAME = minishell
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
LDFLAGS = -lreadline -lncurses -lhistory
SRCSDIR = src
OBJSDIR = obj
SRCSFILES = main.c \
			built-ins/cd.c \
			built-ins/echo.c \
			built-ins/env.c \
			built-ins/exit.c \
			built-ins/export.c \
			built-ins/pwd.c \
			built-ins/unset.c \
			ex-flow/built_flow.c \
			ex-flow/executor.c \
			ex-flow/native_flow.c \
			redirections/create_pipes.c \
			redirections/open_file.c \
			redirections/redirect.c \
			utils/export_utils.c \
			utils/ft_realloc.c \
			utils/get_path.c \
			utils/mat_utils.c \
			utils/strccmp.c \
			utils/strmcat.c \
			utils/wait_children.c \
			utils/dbl_pipe.c \
			parser/env_parser.c \
			parser/fill_cmd.c \
			parser/free.c \
			parser/ft_split_adv.c \
			parser/home_exp.c \
			parser/mark_handlers.c \
			parser/proc_line.c \
			parser/prompt.c \
			parser/signals.c
OBJSFILES = $(SRCSFILES:.c=.o)
SRCS = $(addprefix $(SRCSDIR)/, $(SRCSFILES))
OBJS = $(addprefix $(OBJSDIR)/, $(OBJSFILES))
HEAD = -I inc

all: $(NAME)

$(NAME): inc/libft/libft.a $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) inc/libft/libft.a $(LDFLAGS) -o $(NAME)

inc/libft/libft.a:
	make -C inc/libft

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | obj
	$(GCC) $(CFLAGS) $(HEAD) -c $< -o $@ 

obj:
	mkdir -p $(OBJSDIR)
	mkdir -p obj/built-ins
	mkdir -p obj/ex-flow
	mkdir -p obj/redirections
	mkdir -p obj/utils
	mkdir -p obj/parser

clean:
	rm -rf $(OBJSDIR)
	make -C inc/libft clean

fclean: clean
	rm -f $(NAME)
	make -C inc/libft fclean

re: fclean all

debug:
	gcc $(filter-out main.c, src/*.c src/*/*.c) -Wall -Wextra -g -lreadline inc/libft/libft.a -o minishell

.PHONY: clean fclean re debug

-include $(OBJS:.o=.d)