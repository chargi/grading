/* 
 * File:   grading.h
 * Author: chargi
 *
 * Created on April 23, 2015, 2:44 PM
 */

#ifndef PERSON_H
#define	PERSON_H

#include <iostream>
#include <string>
#include <map>
#include "course.h"

using namespace std;

    class Person {
        public:
            Person(string name);
            virtual ~Person();
            const string name;
            const string ptype;
            void getinfo();
    };
    
    class Student : public Person {
        public:
            Student(string name);
            ~Student();
            const string ptype;
            map <string, Course*> courses;
            void getinfo();
    };
    
    class Teacher : public Person {
        public:
            Teacher(string name);
            ~Teacher();
            const string ptype;
            map <string, Course*> courses;
            void getinfo();
    };


#endif	/* GRADING_H */

