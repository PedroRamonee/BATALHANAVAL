all: compile link

compile:
	g++ -ISFML/include -c main.cpp

link:
	g++ main.o -o main -LSFML/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 