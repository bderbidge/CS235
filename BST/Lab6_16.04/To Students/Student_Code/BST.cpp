//
//  BST.cpp
//  BST
//
//  Created by Brandon Derbidge on 11/10/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include <stdio.h>
#include "BST.h"


BST::BST()
{
    root = NULL;
}
BST::~BST()
{
    clear();
}


//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface * BST::getRootNode(){
    
    return root;
}


/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */

bool BST::recursive_add(Node*& cur, int data)
{
    
    
    if(cur == NULL)
    {
        Node* n = new Node(data, NULL, NULL);
        root = n;
        return true;
    }
    else if(data == cur->data)
    {
        return false;
    }
    else if (data > cur->data)
    {
        if(cur->right == NULL)
        {
            Node* n = new Node(data, NULL, NULL);
            cur->right = n;
            return true;
        }
        else{
        
            cur = cur->right;
            return recursive_add(cur, data);
        }
        
    }
    else
    {
        if(cur->left == NULL)
        {
            Node* n = new Node(data, NULL, NULL);
            cur->left = n;
            return true;
        }
        else{
            
            cur = cur->left;
            return recursive_add(cur, data);
        }
    }
    
    
}

bool BST::add(int data){
    Node* cur = root;
    
    return recursive_add(cur, data);
    
}

/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */



/*bool BST::find(Node*& cur, int data){
    
    if(data == cur->data)
    {
        return true;
    }
    else if(cur == NULL)
    {
        return false;
    }
    else if (data > cur->data)
    {
        cur = cur->right;
        return find(cur, data);
        
    }
    else
    {
        cur = cur->left;
        return find(cur, data);
    }
    
}*
 /*

bool BST::recursiveRemove(Node*& cur, int data){
   
    Node* temp;
    Node* next;
    Node* nobranch = root;
    
    while (cur != NULL) {
        
        if(cur->left == NULL && cur->right == NULL)
        {
            
            while (nobranch!= NULL) {
                
                if(data > nobranch->data)
                {
                    next = nobranch->right;
                    
                    if(next->data == data)
                    {
                        nobranch->right = NULL;
                        delete next;
                        return true;
                        
                    }
                    else{
                        nobranch = nobranch->right;
                    }
                }
                else{
                    next = nobranch->left;
                    
                    if(next->data == data)
                    {
                        nobranch->left = NULL;
                        delete next;
                        return true;
                        
                    }
                    else{
                        nobranch = nobranch->left;
                    }
                }
                
                
            }
            
            
        }
        else if(cur->left == NULL)
        {
            if(cur->right->data == data)
            {
                temp = cur->right;
                cur->right = temp->right;
                
                delete temp;
                return true;
            }
            else if( data > cur->data)
            {
                cur = cur->right;
            }

        }
        else if(cur->right == NULL)
        {
            if(cur->left->data == data)
            {
                temp = cur->left;
                cur->left = temp->left;
                
                delete temp;
                return true;
            }
            else{
                cur = cur->left;
            }


        }
        else
        {
            
            if(cur->left->data == data)
            {
                temp = cur->left;
                cur->left = temp->left;
            
                delete cur;
                return true;
            }
            else if(cur->right->data == data)
            {
                temp = cur->right;
                cur->right = temp->left;
            
                delete temp;
                return true;
            }
            else if( data > cur->data)
            {
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
    }
   
    return false;
}
*/

void BST::repace_parent(Node*& old_root, Node*& local_root){
    if(local_root->right != NULL){
        repace_parent(old_root, local_root->right);
    } else{
        old_root->data = local_root->data;
        old_root = local_root;
        local_root = local_root->left;
    }
    
}

bool BST::recursiveRemove(Node*& cur, int data){
    
    
    if(cur ==NULL){
        return false;
    }else{
        
        if(data < cur->data)
            return recursiveRemove(cur->left, data);
        else if(cur->data < data)
            return recursiveRemove(cur->right, data);
        else{
            Node* old_root = cur;
            if(cur->left == NULL){
                cur = cur->right;
            }else if(cur->right == NULL)
            {
                cur = cur->left;
            }else{
             
                repace_parent(old_root, old_root->left);
            }
            delete old_root;
            return true;
        }
    }
}


bool BST::remove(int data){
    
    
    return recursiveRemove(this->root, data);
 
    
    
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void BST::clear(){
    
    while (root != NULL) {
        remove(root->data);
    }
    
    
}

