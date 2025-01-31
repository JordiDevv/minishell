debug:
	gcc $(filter-out main.c, src/*.c src/*/*.c) -g -lreadline inc/libft/libft.a

PHONY: debug