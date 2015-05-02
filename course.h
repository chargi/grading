/* 
 * File:   grading.h
 * Author: chargi
 *
 * Created on April 23, 2015, 2:44 PM
 */

#ifndef COURSE_H
#define	COURSE_H

#include <iostream>
#include <string>
#include <map>
#include "person.h"

using namespace std;

    class Course {
        public:
            Course();
            ~Course();
            map <string, int> grades;
            void insert(string);
            void grade(string);
            void list();
            void find(string);
    }; 


#endif	/* COURSE_H */

