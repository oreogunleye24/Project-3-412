CC = g++
CFLAGS = -Wall -Werror

all: loadbalancer

loadbalancer: main.o LoadBalancer.o Server.o RequestStruct.o
	$(CC) $(CFLAGS) -o loadbalancer main.o LoadBalancer.o Server.o RequestStruct.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h
	$(CC) $(CFLAGS) -c LoadBalancer.cpp

Server.o: Server.cpp Server.h
	$(CC) $(CFLAGS) -c Server.cpp

RequestStruct.o: RequestStruct.cpp RequestStruct.h
	$(CC) $(CFLAGS) -c RequestStruct.cpp

clean:
	rm -f loadbalancer *.o
