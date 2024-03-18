word: main.o Dictionary.o
	g++ -o word main.o Dictionary.o
main.o: main.cpp Dictionary.h
	g++ -c main.cpp -o main.o
Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp -o Dictionary.o
clean:
	rm -f *o