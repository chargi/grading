/* 
 * File:   grading.h
 * Author: chargi
 *
 * Created on April 23, 2015, 2:44 PM
 */

#ifndef GRADING_H
#define	GRADING_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

    class Person {
        protected:
            string name;
        public:
            Person(string name);
            virtual ~Person();
    };
    
    class Student : public Person {
        public:
            Student(string name);
            ~Student();
            const string ptype;
    };
    
    class Teacher : public Person {
        public:
            Teacher(string name);
            ~Teacher();
            const string ptype;
    };
    
    class Course {
        public:
            Course();
            ~Course();
            map <Person, map <string, int> > book;
            map <string, int> dummy;
            void insert(Person);
            void grade(Person);
            void list();
            void find(string);
    }; 
    



#endif	/* GRADING_H */

