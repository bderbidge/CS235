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


template<typename T>
class LinkedList: public LinkedListInterface<T>
{
    
private:
    struct Node{        /** This constructs the Node*/
        
        T data;         //data can be any type passed into the node
        Node* next;     //This pointer points to the next node in the linked list.
        
        Node(T value, Node* next) : data(value), next(next){}
        
    };
    

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
       Node* ptr = head;
    

        if( head == NULL)       /**If a head node has not been created then a new head node is create*/
        {
            head = new Node(value, NULL);
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
        
            
            
            Node* new_node = new Node(value, ptr); /** A node is created and assigned to the head pointer then deleted*/
            head = new_node;
           // delete new_node;

            
    
          count++; //Increase the number of nodes counted in the list. 
        }
        ptr = NULL;
        current = NULL;
    }
    
    /*
     insertTail
     
     A node with the given value should be inserted at the end of the list.
     
     Do not allow duplicate values in the list.
     */
    void insertTail(T value){
        
        Node* current = head;
         

        if(current == NULL)
        {
            Node* tail = new Node(value, NULL);
            head = tail;
            //delete tail;
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
                break;
            }
            else{
                current = current->next;
            }
        }
    
    
            Node* tail = new Node(value, NULL);
            
            current->next = tail;
           // delete tail;

            count++;
        
    
        
        
    }
    
    /*
     insertAfter
     
     A node with the given value should be inserted immediately after the
     node whose value is equal to insertionNode.
     
     A node should only be added if the node whose value is equal to
     insertionNode is in the list. Do not allow duplicate values in the list.
     */


    void insertAfter(T value, T insertionNode){
        
        Node* current = head;
        Node* ptr = head;

        bool condition = false;
    
        while(ptr != NULL)
        {
           
            if( ptr->data == value)
            {
                ptr = NULL;
                return;
            }
                ptr = ptr->next;
         } 

    
        
        while(current != NULL)
        {
            if( current->data == insertionNode)
            {
                condition = true;
                break;
            }
            current = current->next;
            
        }
        
        if(condition == true)
        {
            
            Node* new_node = new Node(value, current->next);
            current->next = new_node;      
            //delete new_node;

            count++;
        }
        ptr = NULL;
        
    }
    
    /*
     remove
     
     The node with the given value should be removed from the list.
     
     The list may or may not include a node with the given value.
     */
    void remove(T value){
        
        Node* current = head;
        Node* node_to_delete = head->next;
        bool condition = false;

        if(current->data == value)
        {
            head = node_to_delete;
            delete current;
            node_to_delete = NULL;
            count--; 
            return;
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
        }
        
       
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
    /*
     size
     
     Returns the number of nodes in the list.
     */
    int size(){
        
        return count;
        
    }
    
    
};


#endif /* LinkedList_h */
