CC	=	gcc
LD	=	gcc
CFLAGS	=	-g -Wall -O0
LFLAGS	=

all:main.elf

run:
	./main.elf
	
clean:
	rm -rf *.o *.elf
	
######################
main.elf:main.o common.o bub.o
	$(CC) -o $@ $^ $(LFLAGS)
	
%.o:%.c
	$(LD) -c -o $@ $< $(CFLAGS)
