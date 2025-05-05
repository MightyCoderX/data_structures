CC := gcc
# CFLAGS := -std=c99 -Wall -Wextra -Werror -pedantic
CFLAGS := -std=c99 -Wall -Wextra -pedantic

BUILD_DIR := ./build
DEBUG_BUILD_DIR := $(BUILD_DIR)/debug

SRCS := $(shell find -name '*.c')
EXE_NAME := main

EXE_PATH := $(BUILD_DIR)/$(EXE_NAME)
DEBUG_EXE_PATH := $(DEBUG_BUILD_DIR)/$(EXE_NAME)

main: $(SRCS)
	[ ! -d $(BUILD_DIR) ] && mkdir -p $(BUILD_DIR) || :
	${CC} ${CFLAGS} $(SRCS) -o $(EXE_PATH)

run: main
	$(EXE_PATH)

debug: $(SRCS)
	[ ! -d $(DEBUG_BUILD_DIR) ] && mkdir -p $(DEBUG_BUILD_DIR) || :
	${CC} ${CFLAGS} -g -fsanitize=address $(SRCS) -o $(DEBUG_EXE_PATH)
	gdb $(DEBUG_EXE_PATH)

clean:
	rm -r $(BUILD_DIR) $(DEBUG_BUILD_DIR)

