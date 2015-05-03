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
 *          This file contains the attributes and methods for Person, Teacher and Student
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

void Person::getInfo() {
    if (!this->courses.empty()) {
        cout << this->name << " (" << this->ptype << ": ";

        for (auto it = this->courses.begin(); it != this->courses.end(); ++it) {
            cout << it->first;
            
            if (this->ptype == "Student") {
                int tmpgrade = it->second->getGrade(this->name);
                cout << ": " << tmpgrade;
            }
            
            if (it != --(this->courses.end())) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }
    else {
        cout << this->name << " is a " << this->ptype << " without courses." << endl;
    }
}

bool Person::isStudent() {
    if (this->ptype == "Student") {
        return true;
    }
    return false;
}

Student::Student(string name) : Person(name, "Student") {
    cout << this->name << " added as a " << this->ptype << "." << endl;
}

Student::~Student() {
    
}

void Student::addCourse(string course, Course* courseptr) {
    courses.insert ( pair<string,Course*>(course,courseptr) );
}

Teacher::Teacher(string name) : Person(name, "Teacher") {
    cout << this->name << " added as a " << this->ptype << "." << endl;
}

Teacher::~Teacher() {
    
}

void Teacher::addCourse(string course, Course* courseptr) {
    courses.insert ( pair<string,Course*>(course,courseptr) );
}

