SHELL := /bin/bash

.PHONY: all
all : release

.PHONY: release
release: testlib.o clean
	$(CC) -c -o $< testlib.c

.PHONY: debug
debug : testlib.o clean
	$(CC) -g -c -o $< testlib.c

.PHONY: test
test : test.c testlib.c clean
	$(CC) -g -o $@ $@.c testlib.c

testlib.o:

.PHONY: check
check: test
	./test

.PHONY: clean
clean:
	rm -f $(wildcard *.o)
