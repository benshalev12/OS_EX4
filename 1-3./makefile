# Makefile for Eulerian Circuit project

CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = eulerian
SRCS = main.cpp Graph.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean
