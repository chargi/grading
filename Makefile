 # Grundlagen der Programmierung 2
 # 
 # Exercise 5: Student-Teacher-Grading System
 # 
 # Team members: Markus Richter (if14b006)
 #               Marco Kretschmer (if14b028),
 # 		 
 # File: Makefile
 # 
 # Description:
 #	    This is the Makefile


CC=g++
CFLAGS=-g -Wall -O -std=c++11
PROJ=grading

all: ${PROJ}

${PROJ}: grading.o course.o person.o
	${CC} ${CFLAGS} -o ${PROJ} grading.o course.o person.o

grading.o: grading.cpp
	${CC} ${CFLAGS} -c grading.cpp

course.o: course.cpp
	${CC} ${CFLAGS} -c course.cpp

person.o: person.cpp person.h
	${CC} ${CFLAGS} -c person.cpp

clean:
	rm -f grading.o course.o person.o ${PROJ}