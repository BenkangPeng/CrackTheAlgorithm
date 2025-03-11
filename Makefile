CC=g++
flag=-Wall -O2
debug_flag=-g
source=draft.cpp
target=draft.out
debug_target=debug.out

$(target):$(source)
	$(CC) $(flag) $< -o $@

$(debug_target):$(source)
	$(CC) $(debug_flag) $< -o $@

all:$(target)
	$(CC) $(flag) $< -o $@

run:$(target)
	./$(target)

debug:$(debug_target)
	gdb $(debug_target)

clean:
	rm -rf $(target) $(debug_target)

.PHONY:all run debug clean