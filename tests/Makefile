CXX = g++
CXXFLAGS = -Wall -fexceptions -Wextra -pedantic -std=c++17 -I../
TARGET = test-all
SOURCES = test-all.cc

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: all clean