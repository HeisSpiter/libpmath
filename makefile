CC       = g++
AS       = as
CFLAGS   = -fomit-frame-pointer -g

all: x86 x86_64

x86:
	$(CC) $(CFLAGS) -m32 -c -o int_x86.o int.cpp
	$(CC) $(CFLAGS) -m32 -c -o tests_x86.o tests.cpp
	$(AS) --32 -o int_s_x86.o ./i386/int.S
	$(CC) $(CFLAGS) -o tests_x86 tests_x86.o int_x86.o int_s_x86.o

x86_64:
	$(CC) $(CFLAGS) -m64 -c -o int_x86_64.o int.cpp
	$(CC) $(CFLAGS) -m64 -c -o tests_x86_64.o tests.cpp
	$(AS) --64 -o int_s_x86_64.o ./amd64/int.S
	$(CC) $(CFLAGS) -o tests_x86_64 tests_x86_64.o int_x86_64.o int_s_x86_64.o

clean:
	rm -f *.o *~
