test_Reader:api.o reader.o test_Reader.o
	g++ -o test_reader api.o reader.o test_Reader.o

api.o:../api.cc
	g++ -std=c++11 -c -o api.o ../api.cc
reader.o:../reader.cc
	g++ -std=c++11 -c -o reader.o ../reader.cc
test_Reader.o:test_Reader.cc
	g++ -std=c++11 -c test_Reader.cc


clean:
	rm *.o