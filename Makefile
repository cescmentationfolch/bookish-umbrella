all: test_similarity test_LSH

test_similarity: test_similarity.cc minhash.o parser.o similarity.o hash.o	
	g++ -std=c++11 -O2 -Wall -o test_similarity test_similarity.cc minhash.o parser.o similarity.o hash.o

test_LSH: test_LSH.cc minhash.o parser.o LSH.o hash.o	
	g++ -std=c++11 -O2 -Wall -o test_LSH test_LSH.cc minhash.o parser.o LSH.o hash.o

minhash.o: minhash.cc minhash.h
	g++ -std=c++11 -O2 -Wall -o minhash.o -c minhash.cc

parser.o: parser.cc parser.h
	g++ -std=c++11 -O2 -Wall -o parser.o -c parser.cc

LSH.o: LSH.cc LSH.h
	g++ -std=c++11 -O2 -Wall -o LSH.o -c LSH.cc

hash.o: hash.cc hash.h
	g++ -std=c++11 -O2 -Wall -o hash.o -c hash.cc

similarity.o: similarity.cc similarity.h
	g++ -std=c++11 -O2 -Wall -o similarity.o -c similarity.cc

clean:
	rm *.o test_LSH test_similarity
