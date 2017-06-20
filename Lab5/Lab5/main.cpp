//
//  main.cpp
//  Lab5
//
//  Created by Brandon Derbidge on 10/31/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include <stdio.h>
#include "Pathfinder.h"
#include <iostream>

int main(){
    Pathfinder* finder = new Pathfinder;
    vector<string> myvec;
    finder->importMaze("Invalid1.txt");
    cout << finder->getMaze() << endl; 
    cout << finder->getMaze() << endl; 
    myvec = finder->solveMaze();
    for ( int i = 0 ; i < myvec.size(); ++i)
        cout << myvec[i] << endl;
    
}
