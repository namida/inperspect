CC=g++
CFLAGS=-W -Wall -g
INCLUDES=-I/usr/include/opencv -I/usr/local/include/libfreenect -I/usr/include/libusb-1.0
LIBDIRS=-L/usr/local/lib
LDFLAGS=-lGL -lGLU -lglut -lcxcore -lcv -lhighgui -lml
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: compile

compile:
	g++ $(CFLAGS) $(INCLUDES) $(LDFLAGS) *.cpp -o prog

clean:
	rm prog

