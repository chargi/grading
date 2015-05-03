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
        protected:
            map <string, int> grades;
        public:
            Course();
            ~Course();
            int grade(string, int);
            int getGrade(string);
    }; 


#endif	/* COURSE_H */

