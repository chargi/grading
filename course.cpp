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

#include "person.h"
#include "course.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

Course::Course() {
    
}

Course::~Course() {
    
}

void Course::insert(string guy) {
    grades.insert ( pair<string,int>(guy,0) );
}

void Course::grade(string guy) {
    
}
    
void Course::list() {
    
}
    
void Course::find(string guy) {
    
}