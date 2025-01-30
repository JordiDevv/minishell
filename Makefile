debug:
	gcc $(filter-out main_testing.c, src/*.c src/*/*.c) -g -lreadline libft/libft.a

PHONY: debug