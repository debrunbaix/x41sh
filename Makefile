CC = gcc
CFLAGS = -g -c -fno-stack-protector
LDFLAGS = -e _start

SRCDIR = src
BUILDDIR = build
LIBCDIR = src/libc

MAIN_SRC = $(SRCDIR)/main.c
LIBC_SRCS = $(wildcard $(LIBCDIR)/*.c)
ALL_SRCS = $(MAIN_SRC) $(LIBC_SRCS)

MAIN_OBJ = $(BUILDDIR)/main.o
LIBC_OBJS = $(patsubst $(LIBCDIR)/%.c,$(BUILDDIR)/%.o,$(LIBC_SRCS))
ALL_OBJS = $(MAIN_OBJ) $(LIBC_OBJS)

41sh: $(ALL_OBJS) $(BUILDDIR)/crt0.o
	ld $(LDFLAGS) -o $@ $^

$(BUILDDIR)/main.o: $(SRCDIR)/main.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: $(LIBCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILDDIR)/crt0.o: crt0.asm
	@mkdir -p $(BUILDDIR)
	nasm -f elf64 $< -o $@

clean:
	rm -rf $(BUILDDIR)/* 41sh

debug:
	@echo "Sources libc détectées: $(LIBC_SRCS)"
	@echo "Objets libc générés: $(LIBC_OBJS)"

.PHONY: clean debug
