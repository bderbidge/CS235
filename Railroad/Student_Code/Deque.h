//
//  Deque.hpp
//  Railroad
//
//  Created by Brandon Derbidge on 10/15/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#ifndef Deque_H_
#define Deque_H_


#include "LinkedList.h"


template<typename T>
class Deque
{
    
private:
    LinkedList<T> container;
    
public:
    Deque(){}
    ~Deque(){}
    
    bool pushLeft(T value)
    {
        container.insertHead(value);
        return true;
    }

    
    bool pushRight(T value)
    {
        container.insertTail(value);
        return true;
    }
    
    bool popLeft(){
        
        container.remove(container.at(0));
        return true;
    }
    
    bool popRight(){
        
        container.removeTail();
        return true;
    }
    
    T topRight(){
        
        return container.valueAtTail();
        
        
    }
    
    T topLeft(){
        
        return container.at(0);
    }

    
    bool empty(){
        
        container.clear();
        return 0;
    }
    
    bool search(T value){
        
        bool condition = true;
        
        condition = container.search(value);
        return condition;
    }
    
    int size()
    {
        return container.size();
    }

    void printStorage()
    {
        cout << "Deque: " ;
        for (int i = 0; i < container.size(); i++) {
            cout << container.at(i) << ", ";
        }
        cout << endl;
    }

    
};

#endif /* Deque_hpp */
