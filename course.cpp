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
 *          This file contains the attributes and methods for Course
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

int Course::grade(string guy, int mark) {
    if (grades.count(guy) > 0) {
        auto it = grades.find(guy);
        it->second = mark;
        return 1;
    }
    else {
        grades.insert ( pair<string,int>(guy,mark));
        return 0;
    }
}
    
int Course::getGrade(string guy) {
    auto it = grades.find(guy);
    return it->second;
}