all: prog

prog: tAluno.h tAluno.o FiltrarAlunos.c
	gcc -o prog FiltrarAlunos.c tAluno.o

tAluno.o: tAluno.h tAluno.c
	gcc -Wno-return-stack-address -c tAluno.c

run: prog
	./prog

clean:
	@rm prog *.o
