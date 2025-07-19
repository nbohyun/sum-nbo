all: sum-nbo

sum-nbo: sum-nbo.cpp
	g++ sum-nbo.cpp -o sum-nbo	

clean: 
	rm -f sum-nbo
	rm -f *.o
