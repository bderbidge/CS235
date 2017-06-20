//
//  Student.cpp
//  Maps and sets
//
//  Created by Brandon Derbidge on 11/19/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include "Student.h"

unsigned long long int Student::getID(){
    unsigned long long int ID;
    stringstream ss;
    
    ss<< studentID;
    ss >> ID;
    
    return ID;
}

string Student::getGPA(){
   
    stringstream ss;
    string zero = "0.00";
    
    if(numOfClasses == 0)
    {
        return zero;
    }
    
    double avgGPA = GPAPoints/numOfClasses;
    
    ss << fixed << setprecision(2) << avgGPA;
    ss >> studentGPA;

    return studentGPA;
    
}

string Student::getName(){
    
    return studentName;
}

void Student::addGPA(double classGrade)
{
    numOfClasses++;
    
    GPAPoints+=  classGrade;
}

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


string Student::toString(){
    
    string student;
    stringstream ss;
    string id;
    
    ss << getID();
    ss >> id;
    
    student =  id + "\n" + studentName + "\n" + studentAddress + "\n" + studentPhoneNumber +"\n" + getGPA();
    
  
    
    return student;
}







