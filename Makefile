CC = gcc
CFLAGS = -I./unity/src -I. -g

.PHONY: all test
	
all: cobra

cobra: main.c
	gcc main.c -o $@

test_runner: CFLAGS += -DTESTING 
test_runner: test_cobra.c list.c unity/src/unity.c
	$(CC) $(CFLAGS) $^ -o test_runner

check: test_runner
	./$<

unity/src/unity.c:
	git clone https://github.com/ThrowTheSwitch/Unity.git unity

clean:
	rm cobra test_runner
