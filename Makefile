CC ?= /usr/bin/clang
CFLAGS ?= -I/usr/local/opt/readline/include
LDFLAGS ?= -L/usr/local/opt/readline/lib
LIBS = -lreadline -lncurses

rdemo: main.c
	$(CC) -Wall $(CFLAGS) $(LDFLAGS) $(LIBS) -o $@ $?
