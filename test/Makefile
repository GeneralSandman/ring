test_Reader:api.o reader.o test_Reader.o
	g++ -o test_Reader api.o reader.o test_Reader.o

test_Regex:token.o regex.o reader.o test_Regex.o api.o 
	g++ -o test_Regex token.o regex.o reader.o test_Regex.o api.o -lboost_regex 

test_Lexer:lexer.o token.o reader.o regex.o test_Lexer.o api.o
	g++ -o test_Lexer lexer.o token.o reader.o regex.o test_Lexer.o api.o -lboost_regex


api.o:../api.cc
	g++ -std=c++11 -c -o api.o ../api.cc
reader.o:../reader.cc
	g++ -std=c++11 -c -o reader.o ../reader.cc
regex.o:../regex.cc
	g++ -std=c++11 -c -o regex.o ../regex.cc
token.o:../token.cc
	g++ -std=c++11 -c -o token.o ../token.cc
lexer.o:../lexer.cc
	g++ -std=c++11 -c -o lexer.o ../lexer.cc
	

test_Reader.o:test_Reader.cc
	g++ -std=c++11 -c test_Reader.cc
test_Regex.o:test_Regex.cc
	g++ -std=c++11 -c test_Regex.cc
test_Lexer.o:test_Lexer.cc
	g++ -std=c++11 -c test_Lexer.cc
	




clean:
	rm *.o