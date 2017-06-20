//
//  main.cpp
//  Midterm
//
//  Created by Brandon Derbidge on 10/25/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//
#include "Redrover.h"
#include <iostream>
using namespace std;

int main() {
    
    int selection;
    RedRover* rover = new RedRover;
    
    do{
        cout << "1. Add a player to the Roster." << endl
        << "2. Print all the players in the roster." << endl
        << "3. Add a car from the station to a storage facility" << endl
        << "4. Remove a car from a storage facility and add it to the station" << endl
        << "5. Display the cars currently accessible in the station and storage facilities." << endl
        << "6. Quit." << endl;
        cin >> selection;
        while ( cin.fail()) {
                cin.clear(); //clear bad input flag
                cin.ignore(1000, '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
                cin >> selection;
            }
        if(selection ==1)
        {
            string data, name, strength, speed;
            cout << "Enter the player's name" << endl;
            cin >> name;
            cout << "Enter the player's strength" << endl;
            cin >> strength;
            cout << "Enter the player's speed" << endl;
            cin >> speed;
            
            data = name + " " + strength + " " + speed;
           string test = "Brandon\n5\n3\nDarren\n10\n2\nStephen\n2\n3\nDork\n1\n1\ndude\n12\n12 ";
            cout << test << endl;
            rover->addToRoster(test);
            
            
        }else if( selection == 2 ){
            
            cout << rover->getRoster() << endl;
            cout << rover->getTeamA() << endl;
            cout << rover->getTeamB() << endl;
            cout << rover->getRosterSize() << endl;
            cout << rover->getTeamASize() << endl;
            cout << rover->getTeamBSize() << endl;
        }
        else if(selection == 3)
        {
            rover->shuffleRoster();
        }
        else if(selection == 4)
        {
            rover->teamReset();
            rover->rosterReset();
        }
        else if(selection == 5)
        {
            rover->createTeams();
            rover->sendSomeoneOver(rover->teamBAt(1), rover->teamAAt(1) );
        }
        
        }while(selection!= 6);
        
    delete rover;
    
    return 0;
    
}
