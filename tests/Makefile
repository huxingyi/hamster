CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -I../
TARGET = hamster-tests
SOURCES = \
	math/vector2.spec.cc

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: all clean