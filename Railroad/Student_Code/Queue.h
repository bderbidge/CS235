//
//  Queue.hpp
//  Railroad
//
//  Created by Brandon Derbidge on 10/15/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//


#ifndef Queue_H
#define Queue_H


#include "LinkedList.h"


template<typename T>
class Queue
    {
    
    private:
        LinkedList<T> container;
    
    public:
        Queue(){}
        ~Queue(){}
    
        bool push(T value)
        {
            container.insertTail(value);
            return true;
        }
        
        bool popLeft(){
            
            container.remove(container.at(0));
            return true;
        }
        
        T top(){
            
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
            cout << "Queue: " ;
            for (int i = 0; i < container.size(); i++) {
                cout << container.at(i) << ", ";
            }
            cout << endl;
        }
        
    
    
    
};


#endif /* Queue_hpp */
