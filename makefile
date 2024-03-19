word: main.o Dictionary.o Grid.o
	g++ -o word main.o Dictionary.o Grid.o
main.o: main.cpp Dictionary.h
	g++ -c main.cpp -o main.o
Dictionary.o: Dictionary.cpp Dictionary.h Heap.h
	g++ -c Dictionary.cpp -o Dictionary.o
Grid.o: Grid.cpp Grid.h
	g++ -c Grid.cpp -o Grid.o
clean:
	rm -f *o