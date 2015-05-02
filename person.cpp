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

#include "person.h"
#include "course.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

Person::Person(string name, string ptype) : name(name), ptype(ptype) {
    
}

Person::~Person() {
    
}

void Person::getinfo() {
    cout << endl << this->name << " is a " << this->ptype << endl << endl;
}

Student::Student(string name) : Person(name, "student") {
    cout << this->name << " added as a " << this->ptype << "." << endl;
}

Student::~Student() {
    
}

Teacher::Teacher(string name) : Person(name, "teacher") {
    cout << this->name << " added as a " << this->ptype << "." << endl;
}

Teacher::~Teacher() {
    
}


