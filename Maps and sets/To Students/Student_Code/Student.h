//
//  Student.hpp
//  Maps and sets
//
//  Created by Brandon Derbidge on 11/19/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#ifndef Student_H_
#define Student_H_

#include <stdio.h>
#include <sstream>
#include <iomanip>
#include "StudentInterface.h"


class Student : public StudentInterface
{
private:
    
    string studentName;
    string studentID;
    string studentGPA;
    string studentAddress;
    string studentPhoneNumber;
    double GPAPoints;
    int numOfClasses;
    
    
public:
    Student( string ID, string name, string address, string phoneNumber ){
        
        studentID = ID;
        studentName = name;
        studentAddress = address;
        studentPhoneNumber = phoneNumber;
        GPAPoints = 0.00;
        studentGPA = "0.00";
        numOfClasses = 0;
    }
    ~Student(void){};
    
    /*
     * getID()
     *
     * Returns the ID of the Student.
     */
    unsigned long long int getID();
    
    /*
     * getName()
     *
     * Returns the name of the Student
     */
    
    string getName();
    
    /*
     * getGPA()
     *
     * Returns the string representation of the Student's GPA.
     */
    
    string getGPA();
    
    /*
     * addGPA()
     *
     * Incorporates the given course grade into the Student's overall GPA.
     */
    
    void addGPA(double classGrade);
    
    /*
     * toString()
     *
     * The student object will be put into string representation. Student info will be
     * ordered ID, name, address, phone number, and GPA. Each piece of information will
     * be on its own line. GPA will not have a newline following it and the precision
     * of the GPA will be rounded to two decimal places. For example,
     *
     * 123456789
     * Ben Thompson
     * 17 Russell St, Provo, UT 84606
     * 555-555-5555
     * 3.12
     *
     * Returns a string representation of the student object There is no trailing new line.
     */
    string toString();
};




#endif /* Student_hpp */
