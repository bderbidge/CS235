//
//  Redrover.hpp
//  Midterm
//
//  Created by Brandon Derbidge on 10/25/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#ifndef Redrover_H_
#define Redrover_H_

#pragma once
#include <iostream>
#include <stdexcept>
#include "LinkedList.h"
#include "Player.h"
#include "RedRoverInterface.h"
#include <string>
#include <ctime>
#include <sstream>

class RedRover : public RedRoverInterface
{
private:
    LinkedList<PlayerInterface*> roster;
    LinkedList<PlayerInterface*> teamA;
    LinkedList<PlayerInterface*> teamB;
    
    
    
public:
    RedRover(){}
    ~RedRover(){}
    
    /*
     * addToRoster()
     *
     * Accepts a string containing the name, strength, and speed of several Players
     * and adds those Players to the roster.
     *
     * The string will be of the format :
     * 			"PlayerName0
     * 			PlayerStrength0
     * 			PlayerSpeed0
     * 			PlayerName1
     * 			PlayerStrength1
     * 			..."
     *
     * and so on with no trailing endline.
     *
     * In the example above, Player0 would be the first entry in the roster followed by Player1 and any other Players.
     *
     * You may assume that the format of the string and the name, strength, and speed of each player will be valid.
     *
     * Returns true if players were added to the roster, false otherwise */
     
     bool addToRoster(string player_list){             /*Adds a player to the roster */
        stringstream str;
        string name;
    	int strength = -1;
    	int speed = -1;
         
         str << player_list;
         while (str >> name) {
            
             if(name.empty())
             {
                 cout << "No players were added to the Roster"<< endl;
                 return false;
             }
             else if(!(str >> strength >> speed))
             {
                 cout << "No players have been added to the roster" << endl;
                 return false;
             }
             else
             {
             
             
                 //If there is not input for any element than the program returns false. 
                 if(name.empty() || strength == -1 || speed == -1 )
                 {
                     return false;
                 }
             
                 roster.insertTail(new Player(name, strength, speed));
            
             
             }
         }
         if(name.empty() || strength == -1 || speed == -1 )
         {
             cout << "No players were added to the Roster"<< endl;
             return false;
         }else{
             
             return true;
             
         }
        
        
        
    }
    
    int getRosterSize()             /*Gets the size of the Roster*/
    {
        return roster.size();
    }
    int getTeamASize(){             /*Gets the size of Team A*/
    
        return teamA.size();
    
    }
    int getTeamBSize(){             /*Gets the size of TeamB*/
        
        return teamB.size();
        
    }
    
    
string getRoster(){
       
       string teamroster;
       
       if(getRosterSize() == 0)         /*If there are no players in the roster then the user is notified*/
       {
           teamroster = "Roster empty";
           return teamroster;
       }else{
           
       
           for(int i = 0; i < getRosterSize(); i++ )       /*All the names of the players in the roster are placed in a string*/
           {
               if( i == getRosterSize() - 1)
               {
                   teamroster += roster.at(i)->getName();
               }else{
                   teamroster += roster.at(i)->getName();
                   teamroster += " ";
               }
           }
           return teamroster;
       }
    
   }
    
string getTeamA(){
    
    string steamA;
      if(getTeamASize() == 0)
      {
          steamA = "Team A empty";
          return steamA;
      }else{
          
        for(int i = 0; i < getTeamASize(); i++ )        /*All the names of the players in the team are placed in a string*/
        {
            if( i == getTeamASize() - 1)
            {
                steamA += teamA.at(i)->getName();
            }else{
                steamA += teamA.at(i)->getName();
                steamA += " ";
                
            }
        }
          return steamA;
      }
    
    }
    
    string getTeamB(){
        
        string steamB;
       
        if(getTeamBSize() == 0)
        {
            steamB = "Team B empty";
            
            return steamB;
            
        }else{
            for(int i = 0; i < getTeamBSize(); i++ )    /*All the names of the players in the team are placed in a string*/
            {
                if( i == getTeamBSize() - 1)
                {
                    steamB+= teamB.at(i)->getName();
                }else{
                    steamB+= teamB.at(i)->getName();
                    steamB+= " ";
                }
            }
            return steamB;
        }
       
    }
    
    /*
     * rosterAt()
     *
     * Returns a pointer to the player at the given index in the roster.
     * Returns NULL if the index is out of range
     */
    
    PlayerInterface* rosterAt(int index){
        
        if(index >= getRosterSize() || index < 0)
        {
            return NULL;
        }
        else if(getRosterSize() == 0)
        {
            return NULL;
        }
        else
        {
            return roster.at(index);
        }
    }
    
    /*
     * teamAAt()
     *
     * Returns a pointer to the player at the given index in Team A.
     * Returns NULL if the index is out of range
   */
    PlayerInterface* teamAAt(int index){
        if(index >= getTeamASize() || index < 0)
        {
            return NULL;
        }
        else if(getTeamASize() == 0)
        {
            return NULL;
        }
        else
        {
            return teamA.at(index);
        }
    }
    
    /*
     * teamBAt()
     *
     * Returns a pointer to the player at the given index in Team B.
     * Returns NULL if the index is out of range
     */
    
    PlayerInterface* teamBAt(int index){
        
        if(index >= getTeamBSize() || index < 0)
        {
            return NULL;
        }
        else if(getTeamBSize() == 0)
        {
            return NULL;
        }
        else
        {
            PlayerInterface* ptr;
            ptr = teamB.at(index);
            return ptr;
        }

    }
    
    /*
     * shuffleRoster()
     *
     * Shuffles the players in the roster
     * Does not affect the players in Team A or Team B
     */
    
    void shuffleRoster(){
        int n = 0;
        srand(time(0));
        
        LinkedList<PlayerInterface*> temp;
        
        while(getRosterSize() >0)
        {
            n = rand() % getRosterSize();       /*The function randomly gets a number within the parameters of the roster size */
            temp.insertTail(rosterAt(n));       /*The program then inserts a random player from the team into a temp linkedlist*/
            roster.remove(rosterAt(n));         /*The player that was inserted into temp is now deleted from the roster*/
        }
        
        while(temp.size() > 0)
        {
            roster.insertTail(temp.at(0));      /*The players are put back in the roster from the temp and then deleted from temp*/
            temp.remove(temp.at(0));
        }
        
        temp.clear();
    
    }
    
    
    bool createTeams(){
        if(getRosterSize() < 4)
        {
            cout << "No players have been added to the teams." << endl;
            return false;
        }
        else{
        if(getRosterSize() % 2 == 0)
        {
            while(getRosterSize() > 0 )
            {
                teamA.insertTail( rosterAt(0));
                roster.removeHead();
                
                teamB.insertTail( rosterAt(0));
                roster.remove(rosterAt(0));
            }
            
            
            return true;
        }
        else{
            
            while(getRosterSize() > 1 )
            {
                teamA.insertTail( rosterAt(0));
                roster.removeHead();
                
                teamB.insertTail( rosterAt(0));
                roster.removeHead();
            }
            
            return true;
        }
        
    }
    }
    
    /*
     * sendSomeoneOver()
     *
     * The Player "runner" is called over and attempts to break through the defender's defenses.
     *
     * The runner will always attempt to break the link between the defender and the next player in the defender's team.
     * If the defender is the last player in the team, the runner attempts to break the link between the last two players of the team.
     *
     * The runner is successful if the sum of his strength and speed exceeds the sum of the strengths of the defending players.
     *
     * If the runner is successful the stronger of the two players that he attempted to break through is added to the runner's team after the runner
     * If the runner does not break the link, the runner is added to the defender's team after the defender
     *
     * The names of Players will be unique, they will not exist in more than one team.
     *
     * If the runner and the defender are on the same team or if one of the players cannot be located, does nothing
     * If either the runner or the defender is NULL, does nothing
     */
    
void sendSomeoneOver(PlayerInterface* runner, PlayerInterface* defender){
        
        /*If there are less than two players in each team then the program returns from the function. */
        if(getTeamASize() <2 || getTeamBSize() < 2)
        {
            return;
        }
       //If both players are in the same team then the program returns fromt the function
       if((teamA.search(runner) == true && teamA.search(defender) == true) || (teamB.search(defender) == true && teamB.search(runner)== true))
       {
           return;
       }
       else
       {
           /*if either player has a value of null then the program returns from the function*/
           if(runner == NULL || defender == NULL)
           {
               return;
           }
           else{
               
               PlayerInterface* defender2;
               int runnertotal, defendertotal;
               
               
               
               runnertotal = runner->getSpeed() + runner->getStrength();
               
               if(teamA.search(defender) == true)           /*determines if the defender is in team A*/
               {
                  defender2 = teamA.searchForIndex(defender);   /*The function goes in and finds the index for the correct 2nd defender */
                                                                /*Then it goes into the function TeamBAt and returns a ptr to that defender*/
                   
                   defendertotal = defender->getStrength() + defender2->getStrength();
                   
                   
                   if(runnertotal > defendertotal)                          /*This determines if the if the runner wins*/
                   {
                       if(defender->getStrength() > defender2->getStrength())
                       {
                           teamB.insertAfter(defender, runner);       /*If the runner wins then then he takes the stronger defender with him*/
                           teamA.remove(defender);
                       }
                       else
                       {
                           teamB.insertAfter(defender2, runner);
                           teamA.remove(defender2);
                       }
                   }
                   else{
                       teamA.insertAfter(runner, defender);         /*else the runner loses and is added to the defenders team*/
                       teamB.remove(runner);
                       
                   }

               }
               else if(teamB.search(defender) == true)
               {                                                      /*The function goes in and finds the index for the correct 2nd defender */
                   defender2 = teamB.searchForIndex(defender);    /* Then it goes into the function TeamBAt and returns a ptr to that defender*/
                  
                   defendertotal = defender->getStrength() + defender2->getStrength();
                   
                   
                   if(runnertotal> defendertotal)               /*This determines if the if the runner wins*/
                   {
                       if(defender->getStrength()>defender2->getStrength())
                       {
                           teamA.insertAfter(defender, runner);     /*If the runner wins then then he takes the stronger defender with him*/
                           teamB.remove(defender);
                       }
                       else
                       {
                           teamA.insertAfter(defender2, runner);
                           teamB.remove(defender2);

                       }
                   }
                   else{
                       teamB.insertAfter(runner, defender);             /*else the runner loses and is added to the defenders team*/
                       teamA.remove(runner);
                       
                   }

               }
               if(getTeamASize() <2 )
               {
                   cout << "Team B wins! " << getTeamB() << endl;
               }
               else if(getTeamBSize()<2)
               {
                   
                   cout << "Team A wins! " << getTeamA() << endl;
               }
              
               
           
           }
           
        
    
       }
    }
    
void teamReset(){
        
        teamA.clear();
        teamB.clear();
    }
    
void rosterReset(){
        
        roster.clear();
    }
    
    
    
    
void autoPlay(){}
    
    
    
};

#endif /* Redrover_hpp */
