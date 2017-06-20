//
//  Player.hpp
//  Midterm
//
//  Created by Brandon Derbidge on 10/25/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>

#pragma once
#include "PlayerInterface.h"
#include <string>
using namespace std;

class Player : public PlayerInterface {
public:
    Player(string name, int strength, int speed){
        
        playername = name;
        playerspeed = speed;
        playerstrength = strength;
        
    }
    ~Player(){}
    
    
    /*
     * getName()
     *
     * returns the name of the player
     */
    string getName(){return playername;}
    
    /*
     *getStrength()
     *
     *returns the strength of the player
     */
    int getStrength(){return playerstrength;}
    
    /*
     *getSpeed()
     *
     *returns the speed of the player
     */
    int getSpeed(){return playerspeed;}
    
private:
    string playername;
    int playerstrength;
    int playerspeed;
};

#endif /* Player_hpp */
