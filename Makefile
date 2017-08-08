main:lexer.o reader.o rule.o main.o
	g++ -o main lexer.o reader.o rule.o main.o


reader.o:reader.cc
	g++ -std=c++11 -c reader.cc

rule.o:rule.cc
	g++ -std=c++11 -c rule.cc

lexer.o:lexer.cc rule.cc
	g++ -std=c++11 -c lexer.cc 



main.o:main.cc
	g++ -std=c++11 -c main.cc


clean:
	rm *.o