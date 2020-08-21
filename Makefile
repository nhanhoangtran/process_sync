
# ifeq ($(CC),)
# ifeq ($(origin CC),undefined)
# #     CC := clang
# 	@echo "aaaa"
# endif


CC=clang
CFLAGS=-g -pthread
# CC      = mips-linux-gnu-gcc
# CFLAGS  = $(INCLUDES) -g -Wall -Wextra -D_FILE_OFFSET_BITS=64 -Wa,-mips32r2 -Wa,-mips32r2 -DWITH_THREADS -fPIC -EL -pthread
BIN1=process_1
BIN2=process_2

all: $(BIN1) $(BIN2)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM $(BIN1) $(BIN2)