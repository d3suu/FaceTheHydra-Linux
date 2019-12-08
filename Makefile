fth: main.c stack.h stack.c cards.h cards.c
	gcc main.c stack.h stack.c cards.h cards.c -o fth

fth-debug: main.c stack.h stack.c cards.h cards.c
	gcc -g main.c stack.h stack.c cards.h cards.c -o fth-debug

debug: fth-debug
