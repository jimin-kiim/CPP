## g++ main.cpp -o OUT -lGL -lGLU -lglut

CC = g++
CFLAGS = -c
UNAME_S := $(shell uname 2>/dev/null || echo Unknown)

ifeq ($(OS), Windows_NT)
    TARGET := main.exe
	LINKING = -lglut -lGL -lGLU 
else ifeq ($(UNAME_S), Linux)
    TARGET := main.linux.out
	LINKING = -lglut -lGL -lGLU 
else ifeq ($(UNAME_S), Darwin)
    TARGET := main.mac.out
	LINKING = -framework OpenGL -framework GLUT
else
    TARGET := main.unknown.out
endif

objects = CSphere.o CWall.o sources.o main.o 
hpps = sources.hpp CWall.hpp CSPhere.hpp

main.out : $(objects) 
	$(CC) $(objects) -o $(TARGET) $(LINKING)

main.o: sources.hpp 
	$(CC) -c main.cpp

sources.o: CWall.hpp CSphere.hpp
	$(CC) -c sources.cpp

CWall.o: CWall.hpp sources.hpp
	$(CC) -c CWall.cpp

CSphere.o: sources.hpp CSphere.hpp
	$(CC) -c -std=c++11 CSphere.cpp

clean:
	rm -f *.o