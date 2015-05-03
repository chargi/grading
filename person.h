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
            Person(string name, string ptype);
            virtual ~Person();
            const string name;
            const string ptype;
            void virtual getinfo() { };
            void virtual addcourse(string, Course*) { };
    };
    
    class Student : public Person {
        public:
            Student(string name);
            ~Student();
            map <string, Course*> courses;
            void getinfo();
            void addcourse(string, Course*);
    };
    
    class Teacher : public Person {
        public:
            Teacher(string name);
            ~Teacher();
            map <string, Course*> courses;
            void getinfo();
            void addcourse(string, Course*);
    };


#endif	/* GRADING_H */

