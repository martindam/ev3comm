CXXFLAGS =  -O2 -g -Wall -std=c++11 -fmessage-length=0 -I src/ -I include/
ARFLAGS = rcs

# Library setup
LIB_SRC = $(wildcard src/*.cpp)
OBJS =		${LIB_SRC:.cpp=.o}
TARGET =	libev3comm.a

# Test programs
TEST_CXXFLAGS =  -O2 -g -Wall -std=c++11 -fmessage-length=0 -L . -lev3comm -I include/
TEST_SRC = $(wildcard test/*.cpp)
TEST_TARGETS = ${TEST_SRC:.cpp=.out}
TESTS = ${TEST_SRC:.cpp=.test}

$(TARGET):	$(OBJS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJS)

all:	$(TARGET) test

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGETS)

test/%.out: test/%.cpp
	$(CXX) -static ${@:.out=.cpp} $(TEST_CXXFLAGS) -o $@

test.build: $(TEST_TARGETS)
	@echo "Test build complete"

test/%.test:
	${@:.test=.out}

test: test.build $(TESTS)
	@echo "Test passed"
	

doc:
	doxygen Doxyfile
