//
//  main.cpp
//  Railroad
//
//  Created by Brandon Derbidge on 10/15/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//
#include "Station.h"
#include <iostream>
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

int main() {
   
    
    int selection;
    bool runtrain = true;
    Station* curentcar = new Station;
    
    do{
        cout << "1. Add a car to the station" << endl
        << "2. Remove a car from the station" << endl
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
        if(selection == 1)
        {
            int car;
            bool added = true;
            cout <<"Enter the car's id. "<< endl;
            cin >> car;
            if(cin.fail()) {
                cin.clear(); //clear bad input flag
                cin.ignore(1000, '\n'); //discard input
                cout << "The car could not be added."<< endl;
            }
            else{
                added = curentcar->addToStation(car);
            
                if(added)
                {
                    cout << "The car was added to the Station." << endl;
                }
                else{
                    cout << "The car could not be added." << endl;
                }
            }
            
        }
        else if(selection == 2)
        {
            bool removed = true;
            removed = curentcar->removeFromStation();
            
            if(removed)
            {
                cout << "The car was removed to the Station" << endl;
            }
            else{
                cout << "There is no car in the station to remove" << endl;
            }
        }
        else if(selection == 3)
        {
            bool added = true;
            int selection;
            cout << "Which storage facility would you like to add the car in the station to?" << endl
            << "1. Add to Stack" << endl
            << "2. Add to the left of the Deque" << endl
            << "3. Add to the Right of the Deque" << endl
            << "4. Add to the Queue" << endl
            << "5. Add to the input restricted Deque" << endl
            << "6. Add to the right of the output restricted Deque" << endl
            << "7. Add to the left of the output restricted Deque" << endl;
            cin >> selection;
            if(cin.fail()) {
                cin.clear(); //clear bad input flag
                cin.ignore(1000, '\n'); //discard input
                cout << "The car could not be added."<< endl;
            }
            
            switch (selection) {
                case 1: added = curentcar->addToStack();
                    break;
                case 2: added = curentcar->addToDequeLeft();
                    break;
                case 3: added = curentcar->addToDequeRight();
                    break;
                case 4: added = curentcar->addToQueue();
                    break;
                case 5: added = curentcar->addToIRDequeLeft();
                    break;
                case 6: added = curentcar->addToORDequeRight();
                    break;
                case 7: added = curentcar->addToORDequeLeft();
                    break;
            }
            
            if(!added)
            {
                cout << "The car was not added" << endl;
            }
            else{
                cout << "The car was added" << endl;
            }
            
        }
        else if(selection == 4)
        {
            bool deleted = true;
            int selection;
            cout << "Enter the id of the car you would like to add to the station" << endl;
            
            cin >> selection;
            if(cin.fail()) {
                cin.clear(); //clear bad input flag
                cin.ignore(1000, '\n'); //discard input
                cout << "The car could not be added."<< endl;
            }
            
            if(selection == curentcar->showTopOfStack())
                deleted = curentcar->removeFromStack();
            else if(selection == curentcar->showTopOfQueue())
                deleted = curentcar->removeFromQueue();
            else if(selection == curentcar->showTopOfDequeLeft())
                deleted = curentcar->removeFromDequeLeft();
            else if(selection == curentcar->showTopOfDequeRight())
                deleted = curentcar->removeFromDequeRight();
            else if(selection == curentcar->showTopOfIRDequeLeft())
                deleted = curentcar->removeFromIRDequeLeft();
            else if (selection == curentcar->showTopOfORDequeLeft())
                deleted = curentcar->removeFromORDequeLeft();
            else if (selection == curentcar->showTopOfIRDequeRight())
                deleted = curentcar->removeFromIRDequeRight();
            else
                deleted = false;
            
            if(!deleted)
            {
                cout << "The car was not added to the station." << endl;
            }
            else{
                cout << "The car was added to the station." << endl;
            }
            
        }
        else if(selection == 5)
        {
            curentcar->printStorage();
        }
        else if(selection == 6)
        {
            cout << "Choo choo ciao!" << endl;
            runtrain = false;
        }
        else
        {
            cout <<"Please select a valid option" << endl << endl;
        }
        
        
        
    }while( runtrain );
    
    
    return 0;
}
