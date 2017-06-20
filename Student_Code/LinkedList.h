//
//  LinkedList.hpp
//  
//
//  Created by Brandon Derbidge on 9/24/16.
//
//

#ifndef LinkedList_H_
#define LinkedList_H_
#include "Factory.h"
#include "LinkedListInterface.h"
#include <stdexcept>

#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class LinkedList
{
    
private:
    struct Node{        /** This constructs the Node*/
        
        T data;         //data can be any type passed into the node
        Node* next;     //This pointer points to the next node in the linked list.
        Node* prev;
        
        Node(T value, Node* next, Node* prev) : data(value), next(next), prev(prev){}
        
    };
    
    Node* tailend;
    Node* head;
    int count;      //counts the number nodes in the linked list. 
   
    /*
     insertHead
     
     A node with the given value should be inserted at the beginning of the list.
     
     Do not allow duplicate values in the list.
     */


public:

    LinkedList()
    {
        head = NULL;    //initializes the head node and the counter of nodes.
        count = 0;
    }
    ~LinkedList(){
        clear();
    }
   

    void insertHead(T value){
    
       Node* current = head;
       
        

        if( head == NULL)       /**If a head node has not been created then a new head node is create*/
        {
            
            Node* new_node = new Node(value, NULL, NULL);
            head = new_node;
            tailend = new_node;
            //delete head;
            count++;
        }
        else
        {
         while(current != NULL)     /**This loop ensures that there are no nodes of the same value in the linked list */
            {

             
                if( current->data == value) /**If a node of the same value is found then the function is terminated */
                {  
                    return;
                }

                
                current = current->next;    /**If a node of the same value is not found then the next node is selected to be examined */
            }
        
            
            
            Node* new_node = new Node(value, head, NULL); /** A node is created and assigned to the head pointer then deleted*/
            head->prev = new_node;
            head = new_node;
           

            
    
          count++; //Increase the number of nodes counted in the list. 
        }
    
        current = NULL;
    }
    
    /*
     insertTail
     
     A node with the given value should be inserted at the end of the list.
     
     Do not allow duplicate values in the list.
     */
    void insertTail(T value){
        
        Node* current = head;
        Node* prev = NULL;

        if(current == NULL)
        {
            Node* tail = new Node(value, NULL, prev);
            head = tail;
            tailend = tail;
            count++;
            return;
        }
    
        
        
        while(current != NULL)
        {
            if( current->data == value)
            {
                return;
            }
            else if( current->next == NULL)
            {
                prev = current;
                break;
            }
            else{
                current = current->next;
            }
        }
    
        
            Node* tail = new Node(value, NULL, prev);
            
            current->next = tail;
            tailend = tail;
           // delete tail;

            count++;

        
    }
    
    T valueAtTail()
    {
        return tailend->data;
    }
    
    void removeTail()
    {
        Node* current;
        Node* nodeToDelete;
        nodeToDelete = tailend;
        current = tailend->prev;
        
        tailend = current;
        current->next = NULL;
        delete nodeToDelete;
        count--;
        
    }
    

    
    /*
     remove
     
     The node with the given value should be removed from the list.
     
     The list may or may not include a node with the given value.
     */
    bool remove(T value){
        
        Node* current = head;
        Node* node_to_delete = head->next;
        bool condition = false;

        if(current->data == value)
        {
            head = node_to_delete;
            delete current;
            node_to_delete = NULL;
            count--; 
            return true;
        }

        while(node_to_delete != NULL)
        {
           
            if( node_to_delete->data == value)
            {
                condition = true;
                break;
            }
            current = current->next;
            node_to_delete = node_to_delete->next;
                
        }
    
    
        if(condition == true)
        {
            
            current->next = node_to_delete->next;
            delete node_to_delete;
            node_to_delete = NULL;
            count--;
            return true;
        }
        return false;
       
    }
    
    /*
     clear
     
     Remove all nodes from the list.
     */
     void delete_node(Node* &ptr)
     {
        if( ptr == NULL){
            
            return;
        }
        else{

            delete_node(ptr->next);
            
            delete ptr;
            ptr = NULL;
        
        }

     }


    void clear(){

        delete_node(head);
        count = 0;
        
        
    }
    
    
    
    /*
     at
     
     Returns the value of the node at the given index. The list begins at
     index 0. 
     
     If the given index is out of range of the list, throw an out of range exception.
     */
    T at(int index){
        
        Node* current = head;
        int i = 0;
        if(index >= size())
        {
            throw out_of_range("Inapt function thrown out of range.");
        }
        
            while( current != NULL)
            {

                if(i == index){

                    return current->data;
                }
                 current = current-> next;
                 i++;
            }  

            throw out_of_range("Inapt function thrown out of range.");      
            
    }
    
    T topright()
    {
        return tailend->data;
    }
    /*
     size
     
     Returns the number of nodes in the list.
     */
    int size(){
        
        return count;
        
    }
    
    bool search(T value){
        
        Node* ptr = head;
        
        bool condition = false;
        
        while(ptr != NULL)
        {
            
            if( ptr->data == value)
            {
                ptr = NULL;
                condition = true;
                return condition;
            }
            ptr = ptr->next;
        }
        return condition;
        
    }
    
    
};


#endif /* LinkedList_h */
