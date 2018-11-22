//
//  ShortestPath.hpp
//  ECE309Tester
//
//  Created by Christian Burke on 11/19/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#ifndef ShortestPath_h
#define ShortestPath_h

#include <stdio.h>
class node{
public:
    int index;
    int val;
    node(int ind, int num)
    {
        index = ind;
        val = num;
    }
    node()
    {
        index = 0;
        val = 0;
    };
    
    node& operator= (const node that)
    {
        val = that.val;
        index = that.index;
        return *this;
    }
    
    bool operator== (const node &that) const
    {
        if((val == that.val) && (index == that.index))
        {
            return true;
        }else{
            return false;
        }

    }
};

#endif /* ShortestPath_hpp */
