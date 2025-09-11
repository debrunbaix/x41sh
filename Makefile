CC = gcc
CFLAGS = -c -fno-stack-protector
LDFLAGS = -e _start

SRCDIR = src
BUILDDIR = build
LIBCDIR = src/libc

# Détection automatique des fichiers sources
MAIN_SRC = $(SRCDIR)/main.c
LIBC_SRCS = $(wildcard $(LIBCDIR)/*.c)
ALL_SRCS = $(MAIN_SRC) $(LIBC_SRCS)

# Génération automatique des objets
MAIN_OBJ = $(BUILDDIR)/main.o
LIBC_OBJS = $(patsubst $(LIBCDIR)/%.c,$(BUILDDIR)/%.o,$(LIBC_SRCS))
ALL_OBJS = $(MAIN_OBJ) $(LIBC_OBJS)

41sh: $(ALL_OBJS) $(BUILDDIR)/crt0.o
	ld $(LDFLAGS) -o $@ $^

$(BUILDDIR)/main.o: $(SRCDIR)/main.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

# Règle générique pour tous les fichiers de libc
$(BUILDDIR)/%.o: $(LIBCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILDDIR)/crt0.o: crt0.asm
	@mkdir -p $(BUILDDIR)
	nasm -f elf64 $< -o $@

clean:
	rm -rf $(BUILDDIR)/* 41sh

# Pour débugger, affiche les fichiers détectés
debug:
	@echo "Sources libc détectées: $(LIBC_SRCS)"
	@echo "Objets libc générés: $(LIBC_OBJS)"

.PHONY: clean debug
