CC ?= clang
CFLAGS ?= -Wall -Werror -g -Og

ARCH := $(shell uname -m)
ARCH ?= out

CHECK := $(realpath ../check.sh)

.SUFFIXES: .o .$(ARCH)
.o.$(ARCH):
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

