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

int main(int argc, char** argv) {
    
    //Master Index, having all Names and a Pointer to the Class
    map <string, Person*> phonebook;
    //Master Index, having all Names and a Pointer to the Class
    map <string, Course*> coursebook;
    
    //Welcome
    cout << "Welcome to G.R.A.D.I.N.G.!" << endl
         << "The one and only Student / Teacher Grading System!" << endl << endl;
    
    //Menu
    printmenu();
    
    
    int choice = 0;
    
    do {
        string tempstring;
        
        
        printmenu();
        cout << "> ";
        choice = validinput();
        int studorteach = 0;
        
        switch (choice) {
            //Add person    
            case 1:
                cout << "[1] Add student" << endl
                     << "[2] Add teacher" << endl
                     << "[0] Quit" << endl << endl;

                do {
                    studorteach = validinput();
                    switch (studorteach) {
                        case 0:
                            printmenu();
                            cout << "> ";
                            break;
                        case 1:
                            cout << "Enter name: " << endl << "> ";
                            tempstring = getstring();
                            phonebook.insert ( pair<string,Person*>(tempstring,new Student(tempstring)) );
                            break;
                        case 2:
                            cout << "Enter name: " << endl << "> ";
                            tempstring = getstring();
                            phonebook.insert ( pair<string,Person*>(tempstring,new Teacher(tempstring)) );
                            break;
                        default:
                            cout << "Invalid Input." << endl << endl;
                            break;
                    }
                } while(studorteach != 0);
                break;
            //Find person
            case 2:
                cout << endl << "Enter name: " << endl << "> ";
                tempstring = getstring();
                //Iterate through phonebook and compare given names with input
                for(auto sp : phonebook) {
                    if (sp.first == tempstring) {
                        sp.second->getinfo();
                        break;
                    }
                    else {
                        cout << endl <<"Person not found" << endl;
                    }
                }
                break;
            //Show people
            case 3:
                //Iterate through phonebook and print output
                for(auto sp : phonebook) {
                    cout << sp.first << " existiert als " << sp.second->name << endl;
                }
                break;
            //Grade student
            case 4:
                break;
            case 5:
                cout << endl << "Goodbye!" << endl << endl;
                break;
            default:
                cout << endl << "Invalid Input." << endl << endl;
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
    cout << "-- Make your choice --" << endl
         << "[1] Add person" << endl
         << "[2] Find person" << endl
         << "[3] Show people" << endl
         << "[4] Grade student" << endl
         << "[5] Quit" << endl << endl;
}