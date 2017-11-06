CC	=	gcc
LD	=	gcc
CFLAGS	=	-g -Wall -O0
LFLAGS	=	

all:main.elf

run:
	./main.elf

clean:
	rm -rf *.o *.elf

#############################	
main.elf:main.o dll.o
	$(LD) -o $@ $^ $(LFLAGS)
	
%.o:%.c
	$(CC) -c -o $@ $< $(CFLAGS)
