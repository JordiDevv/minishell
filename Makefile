debug:
	gcc $(filter-out main.c, src/*.c src/*/*.c) -g -lreadline libft/libft.a

PHONY: debug