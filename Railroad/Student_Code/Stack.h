//
//  Stack.hpp
//  Railroad
//
//  Created by Brandon Derbidge on 10/15/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//


#ifndef Stack_H
#define Stack_H



#include "LinkedList.h"

    
template<typename T>
class Stack
    {
    
    private:
        LinkedList<T> container;
    
    public:
        Stack(){}
        ~Stack(){}
    
        bool push(T value){
        
            container.insertHead(value);
            
            return true;
        }
    
        bool pop(){
        
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
            cout << "Stack: " ;
            for (int i = 0; i < container.size(); i++) {
                cout << container.at(i) << ", ";
            }
            cout << endl;
        }

      
};

#endif /* Stack_hpp */
