all: myDriver.o Pinball.o words.h
	g++ -Wall myDriver.o Pinball.o words.h -o driver.out

Pinball.o: Pinball.cpp
	g++ -Wall -c Pinball.cpp

myDriver.o: myDriver.cpp
	g++ -Wall -c myDriver.cpp

run:
	./driver.out

val:
	valgrind ./driver.out

clean:
	rm -f *.o driver.out *~ *.gch