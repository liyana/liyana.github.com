main: main.o one.o two.o three.o
	gcc main.o one.o two.o three.o -I. -o main

main.o: main.c one.h two.h three.h
	gcc -c main.c

one.o: one.c 
	gcc -c one.c

two.o: two.c 
	gcc -c two.c

three.o: three.c 
	gcc -c three.c

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean
