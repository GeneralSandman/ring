test_Reader:api.o reader.o test_Reader.o
	g++ -o test_Reader api.o reader.o test_Reader.o

test_Regex:token.o regex.o reader.o test_Regex.o api.o 
	g++ -o test_Regex token.o regex.o reader.o test_Regex.o api.o -lboost_regex 


api.o:../api.cc
	g++ -std=c++11 -c -o api.o ../api.cc
reader.o:../reader.cc
	g++ -std=c++11 -c -o reader.o ../reader.cc
regex.o:../regex.cc
	g++ -std=c++11 -c -o regex.o ../regex.cc
token.o:../token.cc
	g++ -std=c++11 -c -o token.o ../token.cc
	

test_Reader.o:test_Reader.cc
	g++ -std=c++11 -c test_Reader.cc
test_Regex.o:test_Regex.cc
	g++ -std=c++11 -c test_Regex.cc




clean:
	rm *.o