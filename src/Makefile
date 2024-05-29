#!/bin/bash

CC=gcc
CFLAGS=-std=c11 -Wall -Wpedantic -O2  

all: selectionsort insertionsort shellsort

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< 
	
selectionsort: selectionsort.o
	$(CC) $(CFLAGS) -o $@ $^

insertionsort: insertionsort.o
	$(CC) $(CFLAGS) -o $@ $^

shellsort: shellsort.o
	$(CC) $(CFLAGS) -o $@ $^

install:
	mv selectionsort insertionsort shellsort ../bin
	
clean:
	rm -f selectionsort insertionsort shellsort *.o *~

