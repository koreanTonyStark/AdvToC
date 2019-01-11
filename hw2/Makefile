all : encoding decoding

encoding : encoding.o Tries.o TriesNode.o
	g++ -o encoding encoding.o Tries.o TriesNode.o
	
decoding: decoding.o dTries.o dTriesNode.o
	g++ -o decoding decoding.o dTries.o dTriesNode.o

encoding.o: Tries.h encoding.cpp 
Tries.o: Tries.h Tries.cpp
TriesNode.o: TriesNode.h TriesNode.cpp

decoding.o: dTries.h decoding.cpp
dTries.o: dTries.h dTries.cpp
dTriesNode.o: dTriesNode.h dTriesNode.cpp


clean: 
	rm -f *.o encoding decoding
