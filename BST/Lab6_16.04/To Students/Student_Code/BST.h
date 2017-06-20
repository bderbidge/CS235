//
//  BST.hpp
//  BST
//
//  Created by Brandon Derbidge on 11/9/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#ifndef BST_H_
#define BST_H_
#include "BSTInterface.h"
#include <stdio.h>


class BST: public BSTInterface{
    
private:
    struct Node : public NodeInterface
    {
        
        int data;
        Node* left;
        Node* right;
        
        
        
        Node( const int the_data,
             Node* left_val = NULL,
             Node* right_val = NULL) :
        data(the_data), left(left_val), right(right_val) {}
        
        
        /*
         * Returns the data that is stored in this node
         *
         * @return the data that is stored in this node.
         */
        int getData(){
            return data;
        }
        
        /*
         * Returns the left child of this node or null if it doesn't have one.
         *
         * @return the left child of this node or null if it doesn't have one.
         */
        NodeInterface * getLeftChild(){
            return left;
        }
        
        /*
         * Returns the right child of this node or null if it doesn't have one.
         *
         * @return the right child of this node or null if it doesn't have one.
         */
        NodeInterface * getRightChild(){
            return right;
        }
        
    };
    
    Node* root;

public:
    BST();
    ~BST();
    
    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface
    
    /*
     * Returns the root node for this tree
     *
     * @return the root node for this tree.
     */
    NodeInterface * getRootNode();
    
    bool find(Node*& cur, int data);
    
    /*
     * Attempts to add the given int to the BST tree
     *
     * @return true if added
     * @return false if unsuccessful (i.e. the int is already in tree)
     */
    bool recursive_add(Node*& cur, int data);
    void repace_parent(Node*& old_root, Node*& local_root);
    
    bool add(int data);
    
    /*
     * Attempts to remove the given int from the BST tree
     *
     * @return true if successfully removed
     * @return false if remove is unsuccessful(i.e. the int is not in the tree)
     */
    bool recursiveRemove(Node*& cur, int data);
    
    bool remove(int data);
    
    /*
     * Removes all nodes from the tree, resulting in an empty tree.
     */
    void clear();
};

#endif /* BST_hpp */
