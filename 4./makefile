# Makefile for Eulerian Circuit project with code coverage, profiling, and Valgrind

CXX = g++
CXXFLAGS = -std=c++11 -Wall
PROFILING_FLAGS = -pg
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

TARGET = eulerian
SRCS = main.cpp Graph.cpp
OBJS = $(SRCS:.cpp=.o)

# Phony targets
.PHONY: all clean profile callgraph valgrind coverage

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(PROFILING_FLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compilation target for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(PROFILING_FLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(TARGET) $(OBJS) *.gcno *.gcda *.gcov gmon.out callgrind.out.* \
		analysis.txt analysis_annotated.txt callgraph.png valgrind-report.txt
	rm -rf coverage_report

# Profile target
profile: clean $(TARGET)
	./$(TARGET) -v 5 -e 8 -s 42
	gprof $(TARGET) gmon.out > analysis.txt
	gprof -A $(TARGET) gmon.out > analysis_annotated.txt
	cat analysis.txt

# Call graph target using gprof2dot and Graphviz
callgraph: clean $(TARGET)
	./$(TARGET) -v 5 -e 8 -s 42
	gprof $(TARGET) gmon.out | gprof2dot | dot -Tpng -o callgraph.png

# Valgrind target for memory leak and error detection
valgrind: clean $(TARGET)
	valgrind $(VALGRIND_FLAGS) ./$(TARGET) -v 5 -e 8 -s 42 > valgrind-report.txt 2>&1

# Coverage target using gcov and lcov
coverage: clean $(TARGET)
	./$(TARGET) -v 5 -e 8 -s 42
	gcov $(SRCS)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report

