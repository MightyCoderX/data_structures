CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c23 -g

SRCS = $(shell find -name '*.c')

main: ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o $@

run: main
	./main

clean: main
	rm main

