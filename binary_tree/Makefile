CC = gcc
# CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
CFLAGS = -std=c99 -Wall -Wextra -pedantic

SRCS := $(shell find -name '*.c')
EXE_NAME := main

main: $(SRCS)
	${CC} ${CFLAGS} $(SRCS) -o $(EXE_NAME)

run: main
	./main

debug: $(SRCS)
	${CC} ${CFLAGS} -g -fsanitize=address $(SRCS) -o $(EXE_NAME)
	gdb ./main

clean: main
	rm main

