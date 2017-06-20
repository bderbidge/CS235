
//
//  GPA.cpp
//  Maps and sets
//
//  Created by Brandon Derbidge on 11/19/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include "GPA.h"

map<unsigned long long int,StudentInterface*>GPA::getMap(){
    
    return gpaMap;
    
}


set<StudentInterface*,Comparator>GPA:: getSet(){
    
    
    return gpaSet;
    
}

/*
 * importStudents()
 *
 * Read in and parse through the given files. Each part of an entry in a
 * file is given on a separate line in the file. Student ID is first, name is
 * second, address is third, and phone is last. There are no blank lines between
 * students. The following is an example file:
 *
 *	 5291738600
 * 	 Dick B. Smith
 * 	 879 Maple Road, Centralia, Colorado 24222
 * 	 312-000-1000
 * 	 9251738707
 *	 Harry C. Anderson
 *	 635 Main Drive, Midville, California 48444
 * 	 660-050-2200
 *
 * If a valid file is given, the new Students should be added to the existing
 * map and set.
 *
 * If an invalid file name is given or if there is a missing entry for a student,
 * return false. Duplicate student ID numbers and duplicate students will not be
 * tested for. There will never be a student that exists in the map and set. If
 * the function returns false, then no changes should have been made to the
 * existing map or set.
 *
 * The key of the map should be the student ID.
 *
 * Returns false if an invalid filename is given or if there is a missing entry for a
 * student, otherwise true.
 */

int GPA::loadNumberOfLines(string fileName){
    
    ifstream myfile;
    string test;
    myfile.open(fileName);
    int numlines = 0;
    
    while(getline(myfile,test) ){
        
        numlines++;
    }
    
    
    if (myfile.is_open())
    {
        myfile.close();
        
        return numlines;
        
    }
    else
    {
        
        return 1;
    }
    
}


bool GPA::importStudents(string mapFileName, string setFileName){
    
    ifstream myfile;
    string test;
    string name;
    string address;
    string phoneNumber;
    int numlines = 0;
    stringstream ss;
    
    numlines = loadNumberOfLines(mapFileName);
    
    if((numlines % 4) != 0)
    {
        return false;
    }
    
    numlines = loadNumberOfLines(setFileName);
    
    if((numlines % 4) != 0)
    {
        return false;
    }
    
    myfile.open(mapFileName);
    
    while( getline(myfile,test) ){
    
        
       // cout << "THIS IS THE ID D!!!!!!!!" << test << endl << endl << endl;
        getline(myfile,name);
        getline(myfile, address);
        getline(myfile, phoneNumber);
        
        StudentInterface* student = new Student( test, name, address, phoneNumber);
        
        gpaMap[student->getID()]= student;
    }
    
    
    if (myfile.is_open())
    {
        myfile.close();
        
    }
    else
    {
        
        return false;
    }
    
    myfile.open(setFileName);
    
    while(getline(myfile,test) ){
    
        
        getline(myfile,name);
        getline(myfile, address);
        getline(myfile, phoneNumber);
        
        StudentInterface* student;
        
        student = new Student( test, name, address, phoneNumber);
        
        gpaSet.insert(student);
    }
    
    if (myfile.is_open())
    {
        myfile.close();
        
    }
    else
    {
        
        return false;
    }
    
    return true;
    
}

/*
 * importGrades()
 *
 * Read in and parse through the given file. Each part of an entry in the file
 * is given on a separate line in the file. Student ID is first, course is
 * second, and grade is last. There are no blank lines between entries. The
 * following is an example file:
 *
 * 	5291738860
 * 	CHEM134
 * 	A
 * 	9251734870
 * 	BOT180
 * 	B
 * 	9251733870
 * 	PE273
 * 	D+
 * 	5291738760
 * 	HIS431
 *  	A-
 *
 * Compute the GPA by finding the average of all the grades with a matching student ID
 * in the Grade file. The GPA is calculated by taking a Student's total sum GPA and
 * dividing by the number of classes taken. If the given student ID has no matching
 * grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
 * names so long as the total number of courses taken is counted.
 *
 * You may assume that the given student ID exists in the map or set.
 *
 * Use the following point values for each grade.
 *
 *		  A = 4.0  A- = 3.7
 *	B+ = 3.4  B = 3.0  B- = 2.7
 *	C+ = 2.4  C = 2.0  C- = 1.7
 *	D+ = 1.4  D = 1.0  D- = 0.7
 *		  E = 0.0
 *
 * Returns false if an invalid filename is given, otherwise true.
 */

bool GPA::importGrades(string fileName){
    
    string getID;
    unsigned long long int ID;
    string collegeClass;
    string collegeGrade;
    fstream myfile;
    int numlines = 0;
    
    map<string, double > mapgpa = {{"A" ,4.0}, {"A-", 3.7},{"B+" , 3.4}, {"B" ,3.0}, {"B-", 2.7}, {"C+", 2.4}, {"C", 2.0}, {"C-", 1.7}, {"D+", 1.4 }, {"D", 1.0}, {"D-", 0.7},{"E" , 0.0}};
    
    
    numlines = loadNumberOfLines(fileName);
    
    if((numlines % 3) != 0)
    {
        return false;
    }
    
    myfile.open(fileName);
    
    while (getline(myfile, getID) )
    {
        getline(myfile, collegeClass);
        getline(myfile, collegeGrade);
        stringstream ss;

        ss << getID;
        ss >> ID;
        
       // cout << "THIS IS THE ID D!!!!!!!!" << ID << endl << endl << endl;
        //cout << "THIS IS THE ID D!!!!!!!!   " << getID << endl << endl << endl;
        
        if(gpaMap.count(ID) > 0)        //This checks if the id is in the map
        {
            gpaMap[ID]->addGPA(mapgpa[collegeGrade]); //If it's in the map then we go to that Student and add the letter
                                                            //grade to the student's total gpa
        }
        else
        {
            for( StudentInterface* s: gpaSet){
        
                if(s->getID() == ID )
                {
                    s->addGPA(mapgpa.at(collegeGrade));
                }
    
            }
        }
    }
    
    if (myfile.is_open())
    {
        myfile.close();
        
        
    }
    else
    {
        
        return false;
    }
    return true;
}

/*
 * querySet()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your set to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. If an invalid file name is given,
 * then return an empty string. The precision of the GPA will be rounded to two decimal places.
 * There will be a trailing new line.
 */
string GPA::querySet(string filename){
    
    fstream myfile;
    string getID;
    string querystring;
    unsigned long long int ID;
    
    
    myfile.open(filename);
    
    while (getline(myfile, getID) )
    {
        stringstream ss;
        ss << getID;
        ss >> ID;

        for( StudentInterface* s: gpaSet){
            
            if(s->getID() == ID )
            {
                stringstream id;
                id << ID;
                id >> getID;
                querystring += getID + " " + s->getGPA()+ " " + s->getName() + "\n";
            }
            
        }
        
    }
    
    return querystring;
}

/*
 * queryMap()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your map to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. if an ivalid file name is given,
 * then return an empty string. The precision of the GPA will be rounded to two decimal places.
 * There will be a trailing new line.
 */
string GPA::queryMap(string fileName){
    
    fstream myfile;
    string getID;
    string mapstring;
    unsigned long long int ID;
    
    
    myfile.open(fileName);
    
    while (getline(myfile, getID) )
    {
        stringstream ss;
        ss << getID;
        ss >> ID;

        
        if(gpaMap.count(ID) > 0)
        {
            stringstream id;
            id << ID;
            id >> getID;
            mapstring += getID + " " +gpaMap[ID]->getGPA() + " " + gpaMap[ID]->getName() + "\n";
        }
        
        
    }
    
    return mapstring;

}

