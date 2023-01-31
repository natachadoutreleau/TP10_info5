
objects = Character.o test_character.o main.o bin

bin : main.o test_character.o Character.o
	g++ -std=c++11 main.o test_character.o Character.o -o bin

main.o: main.cpp test_character.h Character.h
	g++ -std=c++11 -o main.o -c main.cpp

test_character.o: test_character.cpp test_character.h Character.h
	g++ -std=c++11 -o test_character.o -c test_character.cpp


Character.o: Character.cpp Character.h
	g++ -std=c++11 -o Character.o -c Character.cpp

clean:
	rm $(objects)
