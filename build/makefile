# -*- MakeFile -*-

src = ../src/
enc = $(src)/encryption/
bin = ../bin/

#Debug flags and conditionals
dbf = 
debuginfo = 1

ifeq ($(debuginfo), 1)
	bdf = -g
endif

#Rules
pass: main.o Account.o FirstEncrypter.o Persistence.o GenerateManager.o PrintTools.o
	g++ main.o Account.o FirstEncrypter.o Persistence.o GenerateManager.o PrintTools.o -o $(bin)pass

Account.o: $(src)Account.hpp $(src)Account.cpp
	g++ -c $(src)Account.cpp

GenerateManager.o: $(src)GenerateManager.cpp $(src)GenerateManager.hpp $(src)Account.hpp $(src)Persistence.hpp $(enc)FirstEncrypter.hpp $(src)PrintTools.hpp
	g++ -c $(src)GenerateManager.cpp

Persistence.o: $(src)Persistence.hpp $(src)Persistence.cpp $(src)Account.hpp
	g++ -c $(src)Persistence.cpp

FirstEncrypter.o: $(enc)FirstEncrypter.cpp $(enc)FirstEncrypter.hpp
	g++ -c $(enc)FirstEncrypter.cpp

PrintTools.o: $(src)PrintTools.cpp $(src)PrintTools.hpp
	g++ -c $(src)PrintTools.cpp

main.o: $(src)main.cpp $(src)Account.hpp $(src)Persistence.hpp $(enc)FirstEncrypter.hpp $(enc)FirstEncrypter.cpp
	g++ -c $(src)main.cpp

clean:
	rm *.o *.exe