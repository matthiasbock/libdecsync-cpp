
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
LDFLAGS = -lgtest -lgtest_main -pthread

TEST_SRCS = $(wildcard *_test.cpp)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

SRCS = $(filter-out $(TEST_SRCS), $(wildcard *.cpp))
OBJS = $(SRCS:.cpp=.o)

CLI = decsync_cli


.PHONY: all clean test

all: decsync test

decsync: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_OBJS) $(filter-out decsync.o, $(OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o decsync test

run_tests: test
	./test
