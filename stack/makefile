add.o: add.s
	nasm -f elf add.s -o add.o

program.o : program.c
		gcc -c -Wall program.c

program.run: program.o  add.o
		gcc -o program.run program.o  add.o

clean :
	rm *.o
	
