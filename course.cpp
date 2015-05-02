/* 
 * Grundlagen der Programmierung 2
 * 
 * Exercise 5: Student-Teacher-Grading System
 * 
 * Team members: Markus Richter (if14b006),
 *               Marco Kretschmer (if14b028)
 *
 * File:   grading.cpp
 *
 * Description:
 *          This file contains the class definitions for Course
 */

#include "grading.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

Course::Course() {
    
}

Course::~Course() {
    
}

void Course::insert(Person Guy) {
    this->book.insert(pair<Person, map<string, int> >(Guy, NULL));
}

void Course::grade(Person Guy) {
    
}
    
void Course::list() {
    
}
    
void Course::find(string) {
    
}