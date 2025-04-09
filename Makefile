CXX := g++
CXXFLAGS := -Wall -O2
DEBUG_CXXFLAGS := -g

SRC := debug.cpp
TARGET_EXEC := debug.out
DEBUG_EXEC := debug.out

all: $(TARGET_EXEC)

$(TARGET_EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

$(DEBUG_EXEC): $(SRC)
	$(CXX) $(DEBUG_CXXFLAGS) $< -o $@

run: $(TARGET_EXEC)
	./$<

debug: $(DEBUG_EXEC)
	gdb $<

clean:
	rm -f $(TARGET_EXEC) $(DEBUG_EXEC)

.PHONY: all run debug clean