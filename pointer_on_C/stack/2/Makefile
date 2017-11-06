CC	=	gcc
LD	=	gcc
CFLAGS	=	-g -Wall -O0
LFLAGS	=	

all:stack.elf

run:
	./stack.elf
	
clean:
	rm -rf *.o *.elf

###################
stack.elf:main.o stack.o
	$(LD) -o $@ $^ $(LFLAGS)
	
%.o:%.c
	$(CC) -c -o $@ $< $(CFLAGS)
