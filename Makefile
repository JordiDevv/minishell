NAME = minishell
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline
SRCSDIR = src
OBJSDIR = obj
SRCSFILES = built-ins/cd.c \
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
			utils/wait_childs.c \
			env_parser.c \
			fill_cmd.c \
			free.c \
			ft_split_adv.c \
			home_exp.c \
			main_testing.c \
			mark_handlers.c \
			proc_line.c \
			prompt.c \
			signals.c
OBJSFILES = $(SRCSFILES:.c=.o)
SRCS = $(addprefix $(SRCSDIR)/, $(SRCSFILES))
OBJS = $(addprefix $(OBJSDIR)/, $(OBJSFILES))
HEAD = -I inc

all: $(NAME)

$(NAME): libft $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

libft:
	make -C inc/libft

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | obj
	$(GCC) $(CFLAGS) -c $< -o $@ $(HEAD) 

obj:
	mkdir -p $(OBJSDIR)
	mkdir -p obj/built-ins
	mkdir -p obj/ex_flow
	mkdir -p obj/redirections
	mkdir -p obj/utils

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	gcc $(filter-out main.c, src/*.c src/*/*.c) -g -lreadline inc/libft/libft.a

.PHONY: clean fclean re debug