## g++ main.cpp -o OUT -lGL -lGLU -lglut

CC = g++
LINKING = -lglut -lGL -lGLU 
CFLAGS = -c

ifeq ($(OS), Windows_NT)
	TARGET := main.exe
else
	TARGET := main.out
endif


objects = CSphere.o CWall.o sources.o main.o 
hpps = sources.hpp CWall.hpp CSPhere.hpp
# cpps = sources.cpp CWall.cpp CSPhere.cpp

main.out : $(objects) 
	$(CC) $(objects) -o main.out $(LINKING)

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