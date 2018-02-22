CPPFLAGS=--std=gnu++11 -g
CC=g++
LD=g++

alpacaFracas: main.o alpacaFracasPack.o alpaca.o randalpaca.o fracas.o randPack.o
	g++ $(CPPFLAGS) -o alpacaFracas $^

clean:
	rm -f *.o alpacaFracas
