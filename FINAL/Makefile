all: main

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm

LIBS = -lncurses

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)

HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -lncurses -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -lncurses $(LIBS) -o "$@"

clean:
	rm -f main main-debug
