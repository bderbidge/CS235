//
//  Station.hpp
//  Railroad
//
//  Created by Brandon Derbidge on 10/15/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#ifndef Station_h
#define Station_h

#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "LinkedList.h"
#include "StationInterface.h"
#include "Factory.h"
#include "StationInterfaceExtra.h"


    

class Station : public StationInterface
{
private:
    int carId;
    Stack<int> stack;
    Queue<int> queue;
    Deque<int> deque;
    Deque<int> dequeir;
    Deque<int> dequeor;
    
public:
    Station(){
        carId = -1;
    }
    ~Station(){}
    
    //Part 1--------------------------------------------------------------
    /**
     * Let another car arrive at the station and become the current car.
     * Do not allow a new car to arrive if any of the following conditions apply:
     * 1.	There is already a current car
     * 2.	The new car's ID already exists in any structure
     * 3.	The new car's ID is negative
     *
     * @param car the ID of the car arriving at the station
     * @return true if the car successfully arrived; false otherwise
     */
    bool addToStation(int car){
       
        if(carId == -1 && car >= 0){
            
            if(stack.search(car) == false && queue.search(car) == false && deque.search(car) == false)
            {
                carId = car;
                return true;
            }
            else{
                return false;
            }
        }
        
            
            return false;
        
    
    }
    
    /**
     * Returns the ID of the current car.
     * Return -1 if there is no current car.
     *
     * @return the ID of the current car; -1 if there is no current car
     */
    int showCurrentCar()
    {
        if( carId == -1)
            return -1;
        else
            return carId;
    }
    /**
     * Removes the current car from the station.
     * Does nothing if there is no current car.
     *
     * @return true if the current car successfully left; false otherwise
     */
    bool removeFromStation()
    {
        if(carId == -1)
        {
            return false;
        }
        else{
            carId = -1;
            return true;
        }
    }
    
    //Part 2--------------------------------------------------------------
    /**
     * Adds the current car to the stack.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the stack is already full.
     *
     * @return true if the car is successfully added to the stack; false otherwise
     */
    bool addToStack(){
        if(carId == -1 )
        {
            cout << "There is no id in the station" << endl;
            return false;
        }
        else if(showSizeOfStack() >= 5)
        {
            cout << "The stack is full" << endl;
            return false;
        }
        else{
            stack.push(carId);
            
            carId = -1;
            return true;
    
        }
    }
    
        
        
    
    
    /**
     * Removes the first car in the stack and makes it the current car.
     * Does nothing if there is already a current car or if the stack already empty.
     *
     * @return true if the car is successfully removed from the stack; false otherwise
     */
    bool removeFromStack(){
       
        if(carId == -1 && stack.size() > 0)
        {
            carId = stack.top();
            stack.pop();
            return true;
        }else{
             return false;
        }
        
       
    }
    
    /**
     * Returns the ID of the first car in the stack.
     *
     * @return the ID of the first car in the stack; -1 if the stack is empty
     */
    int showTopOfStack(){
        if(stack.size() > 0)
        {
            return stack.top();
    
        }else{
            return -1;
        }
    }
    
    /**
     * Returns the number of cars in the stack.
     *
     * @return the number of cars in the stack
     */
    int showSizeOfStack(){
        
        return stack.size();
        
        return 0;
    }
    
    //Part 3--------------------------------------------------------------
    /**
     * Adds the current car to the queue.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the queue is already full.
     *
     * @return true if the car is successfully added to the queue; false otherwise
     */
    bool addToQueue()
    {
        if(carId == -1 )
        {
            cout << "There is no id in the station" << endl;
            return false;
        }
        else if(showSizeOfQueue()>= 5)
        {
            cout << "The Queue is full." << endl;
            return false;
        }
        else{
            queue.push(carId);
            
            carId = -1;
            return true;
        }
    }
    
    /**
     * Removes the first car in the queue and makes it the current car.
     * Does nothing if there is already a current car or if the queue already empty.
     *
     * @return true if the car is successfully removed from the queue; false otherwise
     */
    bool removeFromQueue(){
       
        if(carId == -1 && queue.size() > 0)
        {
            carId = queue.top();
            queue.popLeft();
            return true;
        }else{
            return false;
        }
        
        
        
    }
    
    /**
     * Returns the ID of the first car in the queue.
     *
     * @return the ID of the first car in the queue; -1 if the queue is empty
     */
    int showTopOfQueue(){
        
        if(queue.size() > 0)
        {
            return queue.top();
            
        }else{
            return -1;
        }
        
    }
    
    /**
     * Returns the number of cars in the queue.
     *
     * @return the number of cars in the queue
     */
    int showSizeOfQueue(){
        
        return queue.size();
    }
    
    //Part 4--------------------------------------------------------------
    /**
     * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the deque is already full.
     *
     * @return true if the car is successfully added to the deque; false otherwise
     */
    bool addToDequeLeft(){
        
        if(carId == -1 )
        {
            cout << "There is no id in the station" << endl;
            return false;
        }
        else if(showSizeOfDeque()>= 5)
        {
            cout << "The Deque is full" << endl;
            return false;
        }
        else{
            
            deque.pushLeft(carId);
            carId = -1;
            return true;
        }

        
    }
    /**
     * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the deque is already full.
     *
     * @return true if the car is successfully added to the deque; false otherwise
     */
    bool addToDequeRight(){
        
        
        if(carId == -1 )
        {
            cout << "There is no id in the station" << endl;
            return false;
        }
        else if(showSizeOfDeque()>= 5)
        {
            cout << "The Deque is full" << endl;
            return false;
        }
        else{
            
            deque.pushRight(carId);
            carId = -1;
            return true;
        }

    }
    
    /**
     * Removes the leftmost car in the deque and makes it the current car.
     * Does nothing if there is already a current car or if the deque already empty.
     *
     * @return true if the car is successfully removed from the deque; false otherwise
     */
    bool removeFromDequeLeft(){
        
        if(carId == -1 && deque.size() > 0)
        {
            carId = deque.topLeft();
            deque.popLeft();
            return true;
        }else{
            return false;
        }

    }
    
    /**
     * Removes the rightmost car in the deque and makes it the current car.
     * Does nothing if there is already a current car or if the deque already empty.
     *
     * @return true if the car is successfully removed from the deque; false otherwise
     */
    bool removeFromDequeRight(){
        
        if(carId == -1 && deque.size() > 0)
        {
            carId = deque.topRight();
            deque.popRight();
            return true;
        }else{
            return false;
        }
        
        
    }
    
    /**
     * Returns the ID of the leftmost car in the deque.
     *
     * @return the ID of the leftmost car in the deque; -1 if the deque is empty
     */
    int showTopOfDequeLeft(){
        
        if(deque.size() > 0)
        {
            return deque.topLeft();
            
        }else{
            return -1;
        }

    }
    
    /**
     * Returns the ID of the rightmost car in the deque.
     *
     * @return the ID of the rightmost car in the deque; -1 if the deque is empty
     */
    int showTopOfDequeRight(){
        
        if(deque.size() > 0)
        {
            return deque.topRight();
            
        }else{
            return -1;
        }

    }
    
    /**
     * Returns the number of cars in the deque.
     *
     * @return the number of cars in the deque
     */
    int showSizeOfDeque()
    {
        
        return deque.size();
    }
    
    void printStorage()
    {
        stack.printStorage();
        queue.printStorage();
        deque.printStorage();
        cout << "Output resticted " ;
        dequeor.printStorage();
        cout << "Input resticted " ;
        dequeir.printStorage();
        if(carId == -1)
            cout << "Station: Empty." << endl;
        else
            cout << "Station: " << carId << endl;
        
    }
    
    //Input-Restricted Deque----------------------------------------------
    /**
     * Adds the current car to the IRDeque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the IRDeque is already full.
     *
     * @return true if the car is successfully added to the IRDeque; false otherwise
     */
    bool addToIRDequeLeft(){
        
        if(carId == -1 )
        {
            cout << "There is no id in the station" << endl;
            return false;
        }
        else if(showSizeOfIRDeque()>= 5)
        {
            cout << "The Deque is full" << endl;
            return false;
        }
        else{
            
            dequeir.pushLeft(carId);
            carId = -1;
            return true;
        }

    }
    
    /**
     * Removes the leftmost car in the IRDeque and makes it the current car.
     * Does nothing if there is already a current car or if the IRDeque already empty.
     *
     * @return true if the car is successfully removed from the IRDeque; false otherwise
     */
    bool removeFromIRDequeLeft(){
        if(carId == -1 && dequeir.size() > 0)
        {
            carId = dequeir.topLeft();
            dequeir.popLeft();
            return true;
        }else{
            return false;
        }
    }
    /**
     * Removes the rightmost car in the IRDeque and makes it the current car.
     * Does nothing if there is already a current car or if the IRDeque already empty.
     *
     * @return true if the car is successfully removed from the IRDeque; false otherwise
     */
    bool removeFromIRDequeRight()
    {
        if(carId == -1 && dequeir.size() > 0)
        {
            carId = dequeir.topRight();
            dequeir.popRight();
            return true;
        }else{
            return false;
        }
    
    }
    /**
     * Returns the ID of the leftmost car in the IRDeque.
     *
     * @return the ID of the leftmost car in the IRDeque; -1 if the IRDeque is empty
     */
    int showTopOfIRDequeLeft(){
        
        if(dequeir.size() > 0)
        {
            return dequeir.topLeft();
            
        }else{
            return -1;
        }
        
    }
    
    /**
     * Returns the ID of the rightmost car in the IRDeque.
     *
     * @return the ID of the rightmost car in the IRDeque; -1 if the IRDeque is empty
     */
    int showTopOfIRDequeRight()
    {
        if(dequeir.size() > 0)
        {
            return dequeir.topRight();
            
        }else{
            return -1;
        }
    }
    
    /**
     * Returns the number of cars in the IRDeque.
     *
     * @return the number of cars in the IRDeque
     */
    int showSizeOfIRDeque() {
        
        return dequeir.size();
    }
    
    //Output-Restricted Deque---------------------------------------------
    /**
     * Adds the current car to the ORDeque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the ORDeque is already full.
     *
     * @return true if the car is successfully added to the ORDeque; false otherwise
     */
    bool addToORDequeLeft(){
        
        if(carId == -1 )
        {
            cout << "There is no id in the station" << endl;
            return false;
        }
        else if(showSizeOfORDeque()>= 5)
        {
            cout << "The Deque is full" << endl;
            return false;
        }
        else{
            
            dequeor.pushLeft(carId);
            carId = -1;
            return true;
        }

        
        
    }
    
    /**
     * Adds the current car to the ORDeque on the right side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the ORDeque is already full.
     *
     * @return true if the car is successfully added to the ORDeque; false otherwise
     */
    bool addToORDequeRight(){
        
        if(carId == -1 )
        {
            cout << "There is no id in the station" << endl;
            return false;
        }
        else if(showSizeOfORDeque()>= 5)
        {
            cout << "The Deque is full" << endl;
            return false;
        }
        else{
            
            dequeor.pushRight(carId);
            carId = -1;
            return true;
        }
        
    }
    
    /**
     * Removes the leftmost car in the ORDeque and makes it the current car.
     * Does nothing if there is already a current car or if the ORDeque already empty.
     *
     * @return true if the car is successfully removed from the ORDeque; false otherwise
     */
    bool removeFromORDequeLeft(){
        
        if(carId == -1 && dequeor.size() > 0)
        {
            carId = dequeor.topLeft();
            dequeor.popLeft();
            return true;
        }else{
            return false;
        }
        
    }
    
    /**
     * Returns the ID of the leftmost car in the ORDeque.
     *
     * @return the ID of the leftmost car in the ORDeque; -1 if the ORDeque is empty
     */
    int showTopOfORDequeLeft(){
        
        if(dequeor.size() > 0)
        {
            return dequeor.topLeft();
            
        }else{
            return -1;
        }
        
    }
    /**
     * Returns the number of cars in the ORDeque.
     *
     * @return the number of cars in the ORDeque
     */
    int showSizeOfORDeque(){
        
        return dequeor.size();
    }


    
};
    


#endif /* Station_hpp */
