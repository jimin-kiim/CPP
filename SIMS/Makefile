main.out : student.o user_interaction.o functioning.o main.o
	g++ student.o user_interaction.o functioning.o main.o -o main.out

main.o: user_interaction.h user_interaction.cpp functioning.h functioning.cpp student.h student.cpp
	g++ -c main.cpp

student.o: student.h student.cpp
	g++ -c student.cpp

user_interaction.o: user_interaction.h user_interaction.cpp functioning.h functioning.cpp
	g++ -c user_interaction.cpp

functioning.o: user_interaction.h user_interaction.cpp functioning.h functioning.cpp student.h student.cpp
	g++ -c functioning.cpp


