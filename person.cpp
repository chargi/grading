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
#include <typeinfo>
#include <cxxabi.h>
#include <algorithm>

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
        string temptype = this->ptype;
        temptype[0] = tolower(temptype[0]);
        cout << this->name << " is a " << temptype << " without courses." << endl;
    }
}

string Person::getType(string derived) {
    string str = derived;
    str.erase(remove_if(str.begin(), str.end(), [](char c) {
        return !isalpha(c); 
    } ), str.end());
    return str;
}

bool Person::isStudent() {
    if (this->ptype == "Student") {
        return true;
    }
    return false;
}

Student::Student(string name) : Person(name, "Student") {
    string temptype = this->getType();
    temptype[0] = tolower(temptype[0]);
    cout << this->name << " added as a " << temptype << "." << endl;
}

Student::~Student() {
    
}

void Student::addCourse(string course, Course* courseptr) {
    courses.insert ( pair<string,Course*>(course,courseptr) );
}

Teacher::Teacher(string name) : Person(name, "Teacher") {
    string temptype = this->getType();
    temptype[0] = tolower(temptype[0]);
    cout << this->name << " added as a " << temptype << "." << endl;
}

Teacher::~Teacher() {
    
}

void Teacher::addCourse(string course, Course* courseptr) {
    courses.insert ( pair<string,Course*>(course,courseptr) );
}

