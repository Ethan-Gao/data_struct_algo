CC	=	gcc
LD	=	gcc
CFLAGS	=	-g -Wall -O0
LFLAGS	=

all:main.elf

run:
	./main.elf
	
clean:
	rm -rf *.o *.elf
	
#######################
main.elf:main.o tree.o queue.o
	$(LD) -o $@ $^ $(FLAGS)

%.o:%.c
	$(CC) -c -o $@ $< $(CLAGS)
