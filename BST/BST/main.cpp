//
//  main.cpp
//  BST
//
//  Created by Brandon Derbidge on 11/9/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include <iostream>
#include "BST.h"


int main() {
    
    BST* tree = new BST;
    
    tree->add(50);
    tree->add(25);
    tree->add(75);
    tree->add(60);
    tree->add(80);
    tree->add(35);
    tree->add(10);
    tree->add(5);
    tree->add(15);
    
    cout << tree->getRootNode()->getData() << endl;
    
    tree->remove(10);
    tree->remove(80);
    tree->remove(75);
    tree->remove(35);
    tree->remove(15);
    tree->remove(25);
    tree->remove(5);
    tree->remove(50);
    tree->remove(60);
    tree->add(50);
    tree->add(25);
    tree->add(75);
    tree->add(60);
    tree->add(80);
    tree->add(35);
    tree->add(10);
    tree->add(5);
    tree->add(15);
    tree->clear();
    
    return 0;
}
