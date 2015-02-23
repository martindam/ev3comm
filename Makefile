CXXFLAGS =  -O2 -g -Wall -std=c++11 -fmessage-length=0 -I src/ -I include/
ARFLAGS = rcs

# Library setup
LIB_SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard include/ev3comm/*.h)
OBJS =		${LIB_SRC:.cpp=.o}
TARGET =	libev3comm.a

# Test programs
GMOCK_DIR = submodule/gmock
GTEST_DIR = $(GMOCK_DIR)/gtest
TEST_CXXFLAGS =  -O2 -g -Wall -std=c++11 -fmessage-length=0 -L . -lev3comm -I include/ \
	-isystem $(GTEST_DIR)/include -isystem $(GMOCK_DIR)/include
TEST_LIBS = -pthread $(GMOCK_DIR)/make/gmock_main.a
TEST_SRC = $(wildcard test/*-test.cpp)
TEST_OBJS = ${TEST_SRC:.cpp=.out}
TEST_TARGET = test/test-all

%.o: %.cpp $(HEADERS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJS) $(HEADERS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJS)

all:	$(TARGET) test

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)
	$(MAKE) -C submodule/gmock/make clean

test/%.out: test/%.cpp
	$(CXX) -c ${@:.out=.cpp} $(TEST_CXXFLAGS) -o $@
	
gmock:
	$(MAKE) -C submodule/gmock/make

test.build: gmock $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) $(TEST_CXXFLAGS) $(TEST_LIBS) -o $(TEST_TARGET)
	@echo "Test build complete"

test: test.build $(TEST_OBJS)
	$(TEST_TARGET)
	@echo "Test passed"

doc: 
	doxygen Doxyfile
