//
//  ShortestPathTester.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 11/21/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include "ShortestPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace ece309;

int main() {
    
    int size = 10;
    int *array = new int[size];
    printf("Before: ");
    for (int i = 0; i < size; i++) {
        array[i] = 2 * i;
        printf("%d ", array[i]);
    }
    
    MaxHeap::sort(array, size);
    
    int* minHeap = new int[size];
    for (int i = 0; i < size; i++)
    {
        minHeap[i] = array[(size - 1) - i];
    }
    
    printf("\nAfter: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    
    node startNode(0, array[0]);
    node endNode(9, array[9]);
    std::set<node> shortestSet;
    
    //shortestPath(array, size, startNode, endNode);
    
    return 0;
}
