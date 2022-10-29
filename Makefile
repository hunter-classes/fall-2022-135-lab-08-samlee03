main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o	

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

funcs.o: funcs.cpp imageio.h

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f sample.o imageio.o main.o funcs.o
