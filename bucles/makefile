program.o: program.s
	nasm -f elf program.s

program.exe: program.o
		gcc -o program.exe program.o
