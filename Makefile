
objects = Character.o test_character.o main.o Mario.o Yoshi.o bin

bin : main.o test_character.o Character.o Mario.o Yoshi.o
	g++ -std=c++11 main.o test_character.o Character.o Mario.o Yoshi.o -o bin

main.o: main.cpp test_character.h Character.h Mario.h Yoshi.h
	g++ -std=c++11 -o main.o -c main.cpp

test_character.o: test_character.cpp test_character.h Character.h Mario.h Yoshi.h
	g++ -std=c++11 -o test_character.o -c test_character.cpp

Mario.o: Mario.cpp Mario.h Character.h
	g++ -std=c++11 -o Mario.o -c Mario.cpp

Yoshi.o: Yoshi.cpp Yoshi.h Character.h
	g++ -std=c++11 -o Yoshi.o -c Yoshi.cpp

Character.o: Character.cpp Character.h
	g++ -std=c++11 -o Character.o -c Character.cpp

clean:
	rm $(objects)
