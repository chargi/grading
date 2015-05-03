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
#include <typeinfo>
#include <cxxabi.h>
#include "course.h"

using namespace std;

    class Person {
        protected:
            map <string, Course*> courses;
            const string name;
            const string ptype;
        public:
            Person(string name, string ptype);
            virtual ~Person();
            void getInfo();
            virtual void addCourse(string, Course*) = 0;
            bool isStudent();
            string getType(string);
    };
    
    class Student : public Person {
        public:
            Student(string name);
            ~Student();
            void addCourse(string, Course*);
            string getType() { return Person::getType(abi::__cxa_demangle(typeid(this).name(),0,0,0)); }
    };
    
    class Teacher : public Person {
        public:
            Teacher(string name);
            ~Teacher();
            void addCourse(string, Course*);   
            string getType() { return Person::getType(abi::__cxa_demangle(typeid(this).name(),0,0,0)); }
    };


#endif	/* GRADING_H */

