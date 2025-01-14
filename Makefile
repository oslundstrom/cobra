CC = gcc
CFLAGS = -I./unity/src -I. -g
TEST_FILES = $(wildcard test_*.c)
TEST_RUNNERS = $(TEST_FILES:.c=_runner)
SRC = list.c queue.c

.PHONY: all test clean check debug

all: cobra

# Debug target to print variables
debug:
	@echo "Test files found: $(TEST_FILES)"
	@echo "Test runners to build: $(TEST_RUNNERS)"

cobra: main.c
	$(CC) $< -o $@

# Rule to create individual test runners
%_runner: %.c $(SRC) unity/src/unity.c
	$(CC) $(CFLAGS) -DTESTING $^ -o $@

check: $(TEST_RUNNERS)
	@for runner in $(TEST_RUNNERS) ; do \
		echo "Running $$runner..." ; \
		./$$runner || exit 1 ; \
	done

unity/src/unity.c:
	git clone https://github.com/ThrowTheSwitch/Unity.git unity

clean:
	rm -f cobra $(TEST_RUNNERS)
