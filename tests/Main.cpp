//
//  Main.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 10/17/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>

#include "IntegerSet.h"
#include <cstdlib>
#include <ctime>

int main()
{
    IntegerSetHT set;
    set.insert(5);
    set.insert(99);
    set.insert(0);
    
    IntegerSetHT::iterator sit = set.begin();
    while(!sit.end())
    {
        printf("%d \n", sit.getInt());
        sit.increment();
    }

    
    
    /*
    IntegerSetHT set(1000);
    srand(time(NULL));

    for (int i = 0; i<500; i++)
    {
        int r = rand()%1000+1;
        set.insert(r);
    }
    printf("collisions: %d\n\n",set.collisions);
    printf("failures: %d\n",set.failures);
*/
}

