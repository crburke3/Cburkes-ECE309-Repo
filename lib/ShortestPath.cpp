//
//  ShortestPath.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 11/19/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include "ShortestPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <set>


class MaxHeap {
private:
    int *heapArray;    // this is the maxheap
    int heapArraySize; // size of the array
    int nextIndex;     // location of next free array entry
    
protected:
    void percolate_up(int);
    void percolate_down(int, int);
    
public:
    MaxHeap(int size = 100) : heapArraySize(size) {
        heapArray = new int[size];
        for (int i = 0; i < size; i++)
            heapArray[i] = 0;
        nextIndex = 0;
    }
    
    void print() {
        for (int i = 0; i < nextIndex; i++) {
            printf("%d ", heapArray[i]);
        }
        printf("\n");
    }
    
    bool insert(int);
    bool remove(int &); // remove the max value
    
private:
    MaxHeap(int *array, int size, int length = 0)
    : heapArray(array), heapArraySize(size), nextIndex(length) {
        int m = nextIndex / 2 - 1; // last internal BTNode
        while (m >= 0) {
            percolate_down(m, length);
            m--;
        }
    }
    
public:
    static void sort(int *array, int size);
};

void MaxHeap::percolate_up(int index) {
    while (index > 0) {
        int parent_index = (index - 1) / 2;
        if (heapArray[index] > heapArray[parent_index]) {
            int tmp = heapArray[index];
            heapArray[index] = heapArray[parent_index];
            heapArray[parent_index] = tmp;
            index = parent_index;
        } else
            return;
    }
}

void MaxHeap::percolate_down(int index, int size) {
    int child_index = index * 2 + 1;
    int val = heapArray[index];
    while (child_index < size) {
        int max_val = val;
        int max_index = -1;
        for (int i = child_index; i < child_index + 2 && i < size; i++) {
            if (heapArray[i] > max_val) {
                max_val = heapArray[i];
                max_index = i;
            }
        }
        if (max_val == val)
            return;
        heapArray[index] = max_val;
        heapArray[max_index] = val;
        index = max_index;
        child_index = index * 2 + 1;
    }
}

bool MaxHeap::insert(int data) {
    if (nextIndex < heapArraySize) {
        heapArray[nextIndex] = data;
        percolate_up(nextIndex);
        nextIndex++;
        return true;
    } else {
        return false;
    }
}

bool MaxHeap::remove(int &val) {
    if (nextIndex > 0) {
        val = heapArray[0];
        heapArray[0] = heapArray[nextIndex - 1];
        nextIndex -= 1;
        percolate_down(0, nextIndex);
        return true;
    }
    return false;
}

void MaxHeap::sort(int *array, int size) {
    MaxHeap heap(array, size, size);
    
    printf("\nheapify: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    
    for (int i = size - 1; i > 0; i--) {
        int ref;
        heap.remove(ref);
        array[i] = ref;
    }
    
    
    // return, and the array passed in is sorted
}




bool FindPath(const node nod, const node endNode, std::set<node>& path, std::set<node>& visited, int size, int* array)
{
    unsigned long nodeReal = visited.count(nod);    //returns 0 if the node not in set
    if(nodeReal == 0)       //if node is not in visited set
    {
        visited.insert(nod);    //add node to visited set
        if(nod == endNode)   //if this is the node we are looking for
        {
            path.insert(endNode);   //add the node to the pathlist
        }
        
        //START DEFINE VERTEXS/////////////////////////////////
        node* vertexs[2];                                   ///
        int child1 = ((nod.index*2) + 1);                   ///
        int child2 = ((nod.index*2) + 2);                   ///
        if(child1 < size)                                   ///
        {                                                   ///
            vertexs[0] = new node(child1, array[child1]);   ///
        }else{                                              ///
            vertexs[0] = nullptr;                           ///
        }                                                   ///
        if(child2 < size)                                   ///
        {                                                   ///
            vertexs[1] = new node(child2, array[child2]);   ///
        }else{                                              ///
            vertexs[1] = nullptr;                           ///
        }                                                   ///
        //END DEFINE VERTEXs///////////////////////////////////
        
        for(int j=0; j<2;j++)   // for each vertex
        {
            if(vertexs[j] != nullptr)
            {
                if(FindPath(nod, endNode, path, visited, size, array) == true)
                {
                    path.insert(nod);   //add node to path list
                    return true;
                }
            }
        }
        
        
    }
    return false;
}


std::set<node> shortestPath(int* array, int size, const node start, const node end) {
    std::set <node> pathSet;
    std::set <node> visitedSet;
    
    //FindPath(start, end, pathSet, visitedSet, size, array);
    
    return pathSet;
}



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
    
    shortestPath(array, size, startNode, endNode);

    return 0;
}
