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
            //don't do that, what will you do if you have to add a 'schoolcaretaker' (schulwart) to your software ?
            //would you add an isSchoolCaretaker() ?
            //if you really need this, do it with sth. like getType() and return an enum (or string), but that's not beautiful at all
            //maybe you should think about, how you could clever cast/return objects (Person/Student/Teacher).
            //we had a short talk about this in today's tutorium, maybe we could talk about this in more detail next time.
            //br, David
            
    };
    
    class Student : public Person {
        public:
            Student(string name);
            ~Student();
            void addCourse(string, Course*);
    };
    
    class Teacher : public Person {
        public:
            Teacher(string name);
            ~Teacher();
            void addCourse(string, Course*);
    };


#endif	/* GRADING_H */

