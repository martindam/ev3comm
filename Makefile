CXXFLAGS =  -O2 -g -Wall -std=c++11 -fmessage-length=0 -I src/ -I include/
ARFLAGS = rcs

# Library setup
LIB_SRC = $(wildcard src/*.cpp)
OBJS =		${LIB_SRC:.cpp=.o}
TARGET =	libev3comm.a

# Test programs
GMOCK_DIR = submodule/gmock
GTEST_DIR = $(GMOCK_DIR)/gtest
TEST_CXXFLAGS =  -O2 -g -Wall -std=c++11 -fmessage-length=0 -L . -lev3comm -I include/ \
	-isystem $(GTEST_DIR)/include -isystem $(GMOCK_DIR)/include  -pthread \
	$(GMOCK_DIR)/make/gmock_main.a
TEST_SRC = $(wildcard test/*.cpp)
TEST_TARGETS = ${TEST_SRC:.cpp=.out}
TESTS = ${TEST_SRC:.cpp=.test}

$(TARGET):	$(OBJS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJS)

all:	$(TARGET) test

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGETS)
	$(MAKE) -C submodule/gmock/make clean

test/%.out: test/%.cpp
	$(CXX) -static ${@:.out=.cpp} $(TEST_CXXFLAGS) -o $@

gmock:
	$(MAKE) -C submodule/gmock/make

test.build: gmock $(TEST_TARGETS)
	@echo "Test build complete"

test/%.test:
	${@:.test=.out}

test: test.build $(TESTS)
	@echo "Test passed"

doc: 
	doxygen Doxyfile
