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
 *          This file contains the main procedure and main logic.
 */

#include "person.h"
#include "course.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int validinput();
string getstring();
void printmenu();
bool nameExists(string, map<string,Person*>* mapptr);
bool courseExists(string, map<string,Course*>* mapptr);

int main(int argc, char** argv) {
    
    //Master Index, having all Names and a Pointer to the Class
    map <string, Person*> phonebook;
    //Master Index, having all Names and a Pointer to the Class
    map <string, Course*> coursebook;
    
    //Welcome
    cout << "Welcome to G.R.A.D.I.N.G.!" << endl
         << "The one and only Student / Teacher Grading System!" << endl << endl;
    
    
    int choice = 0;
    int studorteach = 0;
    
    do {
        string tempstring;
        string tempstring2;
        
        
        printmenu();
        cout << "> ";
        choice = validinput();
        Course* courseptr = nullptr;
        Person* personptr = nullptr;
        
        switch (choice) {
            //Add person    
            case 1:
                cout << "[1] Add student" << endl
                     << "[2] Add teacher" << endl << endl;
                
                studorteach = validinput();
                switch (studorteach) {
                    case 1:
                        cout << "Enter name: " << endl << "> ";
                        tempstring = getstring();
                        if (nameExists(tempstring, &phonebook)) {
                            cout << tempstring << " already exists." << endl << endl;
                        }
                        else {
                            personptr = new Student(tempstring);
                            phonebook.insert ( pair<string,Person*>(tempstring,personptr) );
                        }
                        break;
                    case 2:
                        cout << "Enter name: " << endl << "> ";
                        tempstring = getstring();
                        if (nameExists(tempstring, &phonebook)) {
                            cout << tempstring << " already exists." << endl << endl;
                            break;
                        }
                        else {
                            personptr = new Teacher(tempstring);
                            phonebook.insert ( pair<string,Person*>(tempstring,personptr) );

                            cout << endl << "Add course (0 to exit): " << endl;
                            do {
                                    cout << "> ";
                                    tempstring = getstring();

                                    if (nameExists(tempstring, &phonebook)) {
                                        cout << tempstring << " already exists." << endl << endl;
                                    }                                    
                                    else {
                                        if (tempstring != "0") {
                                            courseptr = new Course();
                                            coursebook.insert ( pair<string,Course*>(tempstring,courseptr) );
                                            if (personptr != nullptr) {
                                                personptr->addCourse(tempstring, courseptr);
                                            }
                                            else {
                                                cout << endl << "Fatal error. Contact the developers." << endl;
                                            }
                                        }
                                    }
                            } while (tempstring != "0");                            
                        }  
                    default:
                        cout << "Invalid Input. Going back to main menu." << endl << endl;
                        break;
                    }
                break;
            //Find person
            case 2:
                cout << endl << endl << "Enter name: " << endl << "> ";
                tempstring = getstring();
                //Iterate through phonebook and compare given name with input
                if (nameExists(tempstring, &phonebook)) {
                    personptr = phonebook.find(tempstring)->second;

                    if (personptr != nullptr) {
                        cout << endl;
                        personptr->getInfo();
                    }
                    else {
                        cout << endl << "Fatal error. Contact the developers." << endl;
                    }
                }
                else {
                    cout << endl << "No records found for " << tempstring << "." << endl;
                }
                break;
            //Show people
            case 3:
                //Iterate through phonebook and print getinfo())
                cout << endl;
                for(auto sp : phonebook) {
                    sp.second->getInfo();
                }
                cout << endl;
                break;
            //Grade student
            case 4:
                cout << endl << "Enter name: " << endl << "> ";
                tempstring = getstring();
                if (nameExists(tempstring, &phonebook)) {
                    personptr = phonebook.find(tempstring)->second;
                    
                    if (personptr->isStudent()) {
                        cout << endl << "Enter course: " << endl << "> ";
                        tempstring2 = getstring();
                        if (courseExists(tempstring2, &coursebook)) {
                            cout << endl << "Enter grade (1-5): " << endl << "> ";
                            int grade = 0;
                            grade = validinput();
                            if (grade > 0 && grade < 6) {
                                //Grade student
                                courseptr = coursebook.find(tempstring2)->second;
                                if (courseptr->grade(tempstring,grade) == 1) {
                                    cout << "Student was already graded. Grade was updated." << endl;
                                }
                                personptr->addCourse(tempstring2, courseptr);
                            }
                            else {
                                cout << endl << "Invalid grade." << endl;
                                break;
                            }
                        }
                        else {
                            cout << endl <<  "Course not found." << endl;
                            break;
                        }
                    }
                    else {
                        cout << endl <<  tempstring << " is not enlisted as a student." << endl;
                        break;
                    }
                }
                else {
                    cout << endl <<  "Name not found." << endl;
                    break;
                }
                break;
            //Quit
            case 5:
                cout << endl << "Goodbye!" << endl << endl;
                break;
            //Invalid Input
            default:
                cout << endl << "Invalid Input. Take a look at the menu." << endl << endl;
                break;
        }            
    } while(choice != 5);
    
    //Clean up after us
    for (auto i: phonebook) {
        delete i.second;
    }
    
    for (auto i: coursebook) {
        delete i.second;
    }
    
    
    return 0;
}

int validinput() {
    int choice = 0;
    cin.sync();
    string input;
    getline(cin, input);
    stringstream safeinput(input);
    safeinput >> choice;
    cin.sync();
    return choice;
}

string getstring() {
    cin.sync();
    string input;
    getline(cin, input);    
    cin.sync();
    return input;
}

void printmenu() {
    cout << endl
         << "-- Make your choice --" << endl
         << "[1] Add person" << endl
         << "[2] Find person" << endl
         << "[3] Show people" << endl
         << "[4] Grade student" << endl
         << "[5] Quit" << endl << endl;
}

bool nameExists(string name, map<string,Person*>* mapptr) {
    if (mapptr->count(name) > 0) {
        return true;
    }
    
    return false;
    
}

bool courseExists(string name, map<string,Course*>* mapptr) {
    if (mapptr->count(name) > 0) {
        return true;
    }
    
    return false;
}