//
//  main.cpp
//  Quicksort
//
//  Created by Brandon Derbidge on 11/23/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include <iostream>
#include "QS.h"

int main() {
    
    QS* quick;
    
    quick = new QS;
    
    quick->createArray(5);
    
    for (int i = 0; i < 5; i++) {
        
        quick->addToArray(i);
    }
    
    
    cout << quick->getArray() << endl;
    
    return 0;
}
