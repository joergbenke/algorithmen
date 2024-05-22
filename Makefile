#!/bin/bash

CC=gcc
CFLAGS=-std=c99 -Wall -O3 

all: selectionsort insertionsort shellsort

selectionsort: 
	${CC} ${CFLAGS} -c $@ $<
	${CC} ${CFLAGS} -o $@ $<

insertionsort: insertionsort.c
	${CC} ${CFLAGS} -o $@ $<

shellsort: shellsort.c
	${CC} ${CFLAGS} -o $@ $<

*.o:*.c
	${CC} ${CFLAGS} -o $@ $<
	
clean:
	rm selectionsort insertionsort shellsort *~

