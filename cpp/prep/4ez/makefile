CC = g++

SOURCES = $(wildcard *.cc)
OBJECTS = $(patsubst %.cc, %.o, $(SOURCES))

TARGET = main

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o: %.cc
	$(CC) -o $@ -c $<

clean:
	rm $(OBJECTS) $(TARGET)