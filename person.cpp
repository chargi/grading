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
 *          This file contains the class definitions for Person, Teacher and Student
 */

#include "grading.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

Person::Person(string name) : name(name) {
    
}

Person::~Person() {
    
}

Student::Student(string name) : Person(name), ptype("Student") {
    
}

Student::~Student() {
    
}

Teacher::Teacher(string name) : Person(name), ptype("Teacher") {
    
}

Teacher::~Teacher() {
    
}


