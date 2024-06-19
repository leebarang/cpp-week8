CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

# Object files
OBJS = address.o echo_service_installer.o service_installer.o link_installer.o manual_router.o message_service_installer.o
FIRST_OBJS = first.o $(OBJS)
SECOND_OBJS = second.o $(OBJS)

all: first second

first: $(FIRST_OBJS)
	$(CC) $(CFLAGS) -o first $(FIRST_OBJS)

second: $(SECOND_OBJS)
	$(CC) $(CFLAGS) -o second $(SECOND_OBJS)

first.o: scenarios/first.cpp
	$(CC) $(CFLAGS) -c scenarios/first.cpp

second.o: scenarios/second.cpp
	$(CC) $(CFLAGS) -c scenarios/second.cpp

address.o: address.cpp address.h
	$(CC) $(CFLAGS) -c address.cpp

echo_service_installer.o: echo_service_installer.cpp echo_service_installer.h
	$(CC) $(CFLAGS) -c echo_service_installer.cpp

service_installer.o: service_installer.cpp service_installer.h
	$(CC) $(CFLAGS) -c service_installer.cpp

link.o: link.cpp link.h
	$(CC) $(CFLAGS) -c link.cpp

link_installer.o: link_installer.cpp link_installer.h
	$(CC) $(CFLAGS) -c link_installer.cpp

message_service_installer.o: message_service_installer.cpp message_service_installer.h
	$(CC) $(CFLAGS) -c message_service_installer.cpp

manual_router.o: manual_router.cpp manual_router.h
	$(CC) $(CFLAGS) -c manual_router.cpp

clean:
	rm -f *.o first second